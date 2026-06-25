#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s) {
    int len = 0;

    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] != ' ') {
            len++;
        }
        else if (len > 0) {
            break;
        }
    }

    return len;
}

int main() {
    string s;
    getline(cin, s);

    cout << lengthOfLastWord(s);

    return 0;
}