#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <unordered_map>

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
vector<pair<int, int>> points;
unordered_map<int, vector<pair<int, int>>> xmap;
unordered_map<int, vector<pair<int, int>>> ymap;
pair<mi, mi> sum[100000];


int main() {
    setIO("triangles");
    cin >> N;
    points.resize(N);
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        points[i].first = x;
        points[i].second = y;
        if (xmap.find(x) == xmap.end()) {
            xmap[x] = vector<pair<int, int>>();
        }
        xmap[x].push_back({y, i});
        if (ymap.find(y) == ymap.end()) {
            ymap[y] = vector<pair<int, int>>();
        }
        ymap[y].push_back({x, i});
    }
    for (pair<const int, vector<pair<int, int>, allocator<pair<int, int>>>> p: xmap) {
        vector <pair<int, int>>& v = p.second;
        sort(v.begin(), v.end());
        mi cur = 0;
        for (int i = 0; i < v.size(); ++i) {
            cur = cur + (v[i].first - v[0].first);
        }
        for (int i = 0; i < v.size(); ++i) {
            if (i > 0) {
                cur = cur +  (2 * i - v.size()) * (v[i].first - v[i-1].first);
            }
            sum[v[i].second].first = cur;
        }
    }
    for (auto& p: ymap) {
        vector<pair<int, int>>& v = p.second;
        sort(v.begin(), v.end());
        mi cur = 0;
        for (int i = 0; i < v.size(); ++i) {
            cur = cur + (v[i].first - v[0].first);
        }
        for (int i = 0; i < v.size(); ++i) {
            if (i > 0) {
                cur = cur +  (2 * i - v.size()) * (v[i].first - v[i-1].first);
            }
            sum[v[i].second].second = cur;
        }
    }
    mi ans = 0;
    for (int i = 0; i < N; ++i) {
        ans = ans + sum[i].first * sum[i].second;
    }
    cout << ans.v << endl;
    return 0;
}