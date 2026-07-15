#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int x = 0;
    string s;
    
    for (int i = 0; i < n; i++) {
        cin >> s;
        // The middle character will always be the operator
        if (s[1] == '+') {
            x++;
        } else {
            x--;
        }
    }
    
    cout << x << endl;
    
    return 0;
}