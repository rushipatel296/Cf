#!/usr/bin/env python3
"""Compile every solution and run it against the sample tests saved by Competitive Companion / CPH."""
import glob, json, os, subprocess, sys, tempfile
from concurrent.futures import ThreadPoolExecutor

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CXX = os.environ.get("CXX", "g++")


def tests_for(cpp):
    d, name = os.path.split(cpp)
    cph = os.path.join(d, ".cph")
    probs = [os.path.join(cph, f) for f in os.listdir(cph)
             if f.startswith(f".{name}_") and f.endswith(".prob")] if os.path.isdir(cph) else []
    if not probs:
        return None, []
    with open(probs[0]) as f:
        p = json.load(f)
    return p, p.get("tests", [])


def same(a, b):
    return a.split() == b.split()


def check(cpp, tmp):
    rel = os.path.relpath(cpp, ROOT)
    exe = os.path.join(tmp, rel.replace(os.sep, "__").replace(":", "_")[:-4])
    r = subprocess.run([CXX, "-std=c++20", "-O2", "-DONLINE_JUDGE", cpp, "-o", exe],
                       capture_output=True, text=True)
    if r.returncode:
        return rel, "compile error", r.stderr.strip().splitlines()[:3]
    prob, tests = tests_for(cpp)
    if prob and prob.get("interactive"):
        return rel, "compiled (interactive)", []
    if not tests:
        return rel, "compiled (no samples)", []
    for i, t in enumerate(tests):
        try:
            out = subprocess.run([exe], input=t["input"], capture_output=True, text=True, timeout=5).stdout
        except subprocess.TimeoutExpired:
            return rel, "differs", [f"sample {i + 1}: timeout"]
        if not same(out, t["output"]):
            return rel, "differs", [f"sample {i + 1}: expected {t['output'].split()[:8]} got {out.split()[:8]}"]
    return rel, "pass", []


def main():
    files = sorted(glob.glob(os.path.join(ROOT, "**", "*.cpp"), recursive=True))
    files = [f for f in files if f"{os.sep}scripts{os.sep}" not in f]
    with tempfile.TemporaryDirectory() as tmp, ThreadPoolExecutor(os.cpu_count()) as ex:
        results = list(ex.map(lambda f: check(f, tmp), files))
    counts = {}
    for rel, status, notes in results:
        counts[status] = counts.get(status, 0) + 1
        if status in ("compile error", "differs") or "-v" in sys.argv:
            print(f"{status:24} {rel}")
            for n in notes:
                print("    " + n)
    print("\n" + ", ".join(f"{v} {k}" for k, v in sorted(counts.items())))
    return 1 if counts.get("compile error") else 0


if __name__ == "__main__":
    sys.exit(main())
