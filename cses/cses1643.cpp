#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    long long ans = INT8_MIN;
    long long s = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        s += x;
        ans = max(ans, s);
        if (s < 0) s = 0;
    }
    cout << ans << "\n";
    return 0;
}