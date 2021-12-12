#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;

void setIO(const string& name = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!name.empty()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int N;


int main() {
    setIO("lemonade");
    cin >> N;
    int w[N];
    for (int i = 0; i < N; ++i) {
        cin >> w[i];
    }
    sort(w, w+N, greater<>());
    int ans = -1;
    for (int i = 0; i < N; ++i) {
        if (w[i] < i) {
            ans = i;
            break;
        }
    }
    if (ans == -1) cout << N << "\n";
    else cout << ans << "\n";
    return 0;
}