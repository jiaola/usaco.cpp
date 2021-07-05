#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, n; cin >> x >> n;
    vector<tuple<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        int t, f; cin >> t >> f;
        v[i] = tie(t, f);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int t = 0;
    int i = 0;
    while (true) {
        tuple<int, int> &p = v[i];
        if (get<0>(p) - t <= x) {  // temperature is ok
            if (get<1>(p) >= t) {  // still fresh
                ans++;
                i++;
                t++;
            } else {
                i++; // check next
            }
            if (i == n) {
                break;
            }
        } else {
            t++;
        }
    }
    cout << ans << "\n";
    return 0;
}