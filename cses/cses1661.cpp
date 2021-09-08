#include <iostream>
#include <algorithm>
using namespace std;

int main() {
//    cin.sync_with_stdio(0);
//    cin.tie(0);
    int n, k;
    cin >> k;
    int u[k];
    int a[1000000];
    int p[1000001] = {0};
    fill(a, a + 1000000, 1);
    for (int i = 0; i < k; ++i) {
        cin >> u[i];
        a[u[i] - 1] = 0;
    }
    for (int i = 1; i < 1000001; ++i) {
        p[i] = p[i - 1] + a[i - 1];
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int f;
        cin >> f;
        cout << p[f] << "\n";
    }
}