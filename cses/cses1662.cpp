#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n; cin >> n;
    long long ps = 0;
    map<int, int> cnt;
    long long ans = 0;
    cnt[0]++;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        ps += a;
        int m = ps % n;
        if (m < 0) m += n;
        ans += cnt[m];
        cnt[m]++;
    }
    cout << ans << "\n";
    return 0;
}