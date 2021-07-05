#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

long long MOD = 10007;
int a[10000];

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO();
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a, a+N);
    int l = 0, r = N-1;
    long long res = 0;
    while (l < r) {
        res += (long long) a[l] * (long long) a[r] * 2;
        l++;
        r--;
    }
    if (l == r) {
        res += (long long) a[l] * (long long) a[r];
    }
    cout << res % MOD << "\n";
    return 0;
}