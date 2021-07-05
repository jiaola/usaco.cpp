#include <iostream>

using namespace std;

int gcd(int a, int b) {
    int temp;
    while (a % b != 0) {
        temp = a;
        a = b;
        b = temp % b;
    }
    return b;
}

int main() {
    int cnt[26] = {};
    char c;
    while (cin.get(c)) {
        cnt[c-'a']++;
    }
    int g = -1;
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] == 0) continue;
        if (g == -1) {
            g = cnt[i];
        } else {
            g = gcd(g, cnt[i]);
        }
    }
    if (g == 1) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i = 0; i < g; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (cnt[j] == 0) continue;
                for (int k = 0; k < cnt[j] / g; ++k) {
                    cout << (char)(j+'a');
                }
            }
        }
        cout << "\n";
    }
}