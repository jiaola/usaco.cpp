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

const int MOD = 1e9+7;

struct mi {
    int v;
    mi(long long _v) : v(_v % MOD) {
        v += (v < 0) * MOD;
    }
    mi() : mi(0) {}
};
mi operator + (mi a, mi b) { return mi(a.v+b.v); }
mi operator - (mi a, mi b) { return mi(a.v-b.v); }
mi operator * (mi a, mi b) { return mi((long long)a.v*b.v); }

int N;
vector<pair<int, int>> vect;
vector<pair<int, int>> todo[20001];
pair<mi, mi> sum[100000];

void check(bool first) {
    for (int i = 0; i < 20001; ++i) {
        if (todo[i].size() > 0) {
            int sz = todo[i].size();
            sort(begin(todo[i]), end(todo[i]));
            mi cur = 0;
            for (int j = 0; j < sz; ++j) {
                cur = cur +  todo[i][j].first - todo[i][0].first;
            }
            for (int j = 0; j < sz; ++j) {
                if (j > 0) {
                    cur = cur + (2 * j - sz) * (todo[i][j].first - todo[i][j-1].first);
                }
                if (first) {
                    sum[todo[i][j].second].first = cur;
                } else {
                    sum[todo[i][j].second].second = cur;
                }

            }
        }
    }
}

int main() {
    setIO("triangles");
    cin >> N;
    vect.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> vect[i].first >> vect[i].second;
    }
    for (int i = 0; i < 20001; ++i) {
        todo[i].clear();
    }
    for (int i = 0; i < N; ++i) {
        todo[vect[i].first + 10000].push_back({vect[i].second, i});
    }
    check(true);
    for (int i = 0; i < 20001; ++i) {
        todo[i].clear();
    }
    for (int i = 0; i < N; ++i) {
        todo[vect[i].second + 10000].push_back({vect[i].first, i});
    }
    check(false);
    mi ans = 0;
    for (int i = 0; i < N; ++i) {
        ans = ans + sum[i].first * sum[i].second;
    }
    cout << ans.v << endl;
    return 0;
}