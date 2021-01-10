#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("cowjog");
    int N;
    cin >> N;
    vector<pair<int, int>> pos;
    for (int i = 0; i < N; ++i) {
        int x, s;
        cin >> x >> s;
        pos.push_back(pair<int, int>(x, s));
    }
    sort(begin(pos), end(pos));
    int s = pos[N-1].second;
    int ans = 1;
    for (int i = N-2; i >= 0; --i) {
        if (pos[i].second <= s) {
            ans++;
            s = pos[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}