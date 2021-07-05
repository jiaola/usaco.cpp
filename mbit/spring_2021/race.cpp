#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    vector<string> v;
    while (cin >> s) {
        if (s[0] < 'a') {
            s[0] = tolower(s[0]);
            s[s.size()-1] = toupper(s[s.size()-1]);
        }
        reverse(s.begin(), s.end());
        v.push_back(s);
    }
    for (int i = v.size()-1; i >= 0; --i) {
        cout << v[i] << " ";
    }
    return 0;
}

