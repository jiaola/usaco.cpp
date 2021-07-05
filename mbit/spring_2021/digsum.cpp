#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (n > m * 9) {
        cout << -1 << "\n";
    } else if (n == 0) {
        if (m == 1) {
            cout << 0 << "\n";
        } else {
            cout << -1 << "\n";
        }
    } else {
        for (int i = 0; i < m; ++i) {
            if (n > 0 && n <= 9) {
                cout << n;
                n = 0;
            } else if (n > 9) {
                cout << 9;
                n -= 9;
            } else {
                cout << 0;
            }
        }
        cout << "\n";
    }
}
