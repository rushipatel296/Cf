#!/usr/bin/env python3
"""Collect every solution into site/data.json for the static browser in site/."""
import json, os, re

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(ROOT, "site", "data.json")
SECTIONS = {"CP_31": "ladder", "Contests": "contests", "Random_Practice": "practice"}
DEBUG_BLOCK = re.compile(r"// --- DEBUG TEMPLATE BEGIN ---.*?// --- DEBUG TEMPLATE END ---\n?", re.S)


def load_probs(d):
    cph = os.path.join(d, ".cph")
    probs = {}
    if os.path.isdir(cph):
        for f in os.listdir(cph):
            if f.endswith(".prob"):
                with open(os.path.join(cph, f)) as fh:
                    probs[f[1:].split(".cpp_")[0] + ".cpp"] = json.load(fh)
    return probs


def pretty(stem):
    name = re.sub(r"^([A-Z]\d?)_", r"\1. ", stem).replace("_", " ")
    return name[0].upper() + name[1:]


def label(folder):
    m = re.search(r"div_?(\d)", folder, re.I)
    return f"Div. {m[1]} round" if m else "Codeforces round"


def contest_date(folder):
    m = re.match(r"(\d{2})(\d{2})(\d{2})", folder)
    return f"20{m[3]}-{m[2]}-{m[1]}" if m else ""


def main():
    items = []
    for top, section in SECTIONS.items():
        for d, dirs, files in os.walk(os.path.join(ROOT, top)):
            dirs[:] = [x for x in dirs if not x.startswith(".")]
            probs = load_probs(d)
            groups = [x.get("group", "").removeprefix("Codeforces - ") for x in probs.values()]
            title = " ".join(max(set(groups), key=groups.count).split()) if groups else ""
            for f in sorted(files):
                if not f.endswith(".cpp"):
                    continue
                path = os.path.relpath(os.path.join(d, f), ROOT)
                folder = os.path.basename(d)
                p = probs.get(f, {})
                with open(os.path.join(d, f), errors="replace") as fh:
                    code = DEBUG_BLOCK.sub("// (debug helpers omitted)\n", fh.read())
                items.append({
                    "id": path[:-4],
                    "name": p.get("name") or pretty(f[:-4]),
                    "url": p.get("url", ""),
                    "section": section,
                    "rating": int(folder) if section == "ladder" else None,
                    "contest": (title or label(folder)) if section == "contests" else "",
                    "folder": folder,
                    "date": contest_date(folder) if section == "contests" else "",
                    "samples": len(p.get("tests", [])),
                    "path": path,
                    "code": code.rstrip() + "\n",
                })
    os.makedirs(os.path.dirname(OUT), exist_ok=True)
    with open(OUT, "w") as fh:
        json.dump(items, fh, separators=(",", ":"))
    print(f"wrote {len(items)} solutions to {os.path.relpath(OUT, ROOT)}")


if __name__ == "__main__":
    main()
