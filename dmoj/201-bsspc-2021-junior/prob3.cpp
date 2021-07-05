#include <iostream>
using namespace std;

bool is_red(char &c) {
    return c == 'R' || c == 'O' || c == 'P' || c == 'B';
}

bool is_blue(char &c) {
    return c == 'U' || c == 'G' || c == 'P' || c == 'B';
}

bool is_yellow(char &c) {
    return c == 'Y' || c == 'O' || c == 'G' || c == 'B';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> m >> n;
    int cnt_r = 0, cnt_b = 0, cnt_y = 0;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        bool in_r = false;
        bool in_y = false;
        bool in_b = false;
        for (int j = 0; j < m; ++j) {
            if (is_red(s[j])) {
                if (!in_r) {
                    in_r = true;
                    cnt_r++;
                }
            } else {
                in_r = false;
            }
            if (is_blue(s[j])) {
                if (!in_b) {
                    in_b = true;
                    cnt_b++;
                }
            } else {
                in_b = false;
            }
            if (is_yellow(s[j])) {
                if (!in_y) {
                    in_y = true;
                    cnt_y++;
                }
            } else {
                in_y = false;
            }
        }
    }

    cout << cnt_r << " " << cnt_y << " " << cnt_b << "\n";
    return 0;
}