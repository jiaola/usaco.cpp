#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    long long l = s.length();
    long long ans = 0, count = 1;
    for (int i = 1; i < l; ++i) {
        if (s[i] != s[i-1]) {
            ans = max(ans, count);
            count = 0;
        }
        count++;
    }
    ans = max(ans, count);
    cout << ans << endl;
    return 0;
}