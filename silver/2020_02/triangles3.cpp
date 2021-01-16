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
const int MOD = 1e9 + 7;
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


int main() {
    setIO("triangles");
    int n;

    pair<mi, mi> arr[100000];
    vector<pair<int,int>> v;
    unordered_map<int, vector<pair<int, int>>> xmap;
    unordered_map<int, vector<pair<int, int>>> ymap;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 0; i < n; ++i) {
        pair<int, int>& p = v[i];
        int x = p.first;
        int y = p.second;
        if (xmap.find(x) == xmap.end()) {
            xmap[x] = vector<pair<int, int>>();
        }
        xmap[p.first].push_back({p.second, i});
        if (ymap.find(p.second) == ymap.end()) {
            ymap[p.second] = vector<pair<int, int>>();
        }
        ymap[p.second].push_back({p.first, i});
    }

    for (const pair<int, vector<pair<int, int>>>& p: xmap) {
        mi xsum = 0;
        vector<pair<int, int>> a = p.second;
        sort(a.begin(), a.end());
        int a1 = a[0].first;
        for (pair<int, int> i: a) {
            xsum = xsum + abs(a1 - i.first);
        }
        arr[a[0].second].second = xsum;
        for (int i = 1; i < a.size(); ++i) {
            xsum = xsum + (2*i - a.size()) * (a[i].first - a[i-1].first);
            arr[a[i].second].second = xsum;
        }
    }

    for (const pair<int, vector<pair<int, int>>>& p: ymap) {
        mi ysum = 0;
        vector<pair<int, int>> a = p.second;
        sort(a.begin(), a.end());
        int a1 = a[0].first;
        for (pair<int, int> i: a) {
            ysum = ysum + abs(a1 - i.first);
        }
        arr[a[0].second].first = ysum;
        for (int i = 1; i < a.size(); ++i) {
            ysum = ysum + (2*i - a.size()) * (a[i].first - a[i-1].first);
            arr[a[i].second].first = ysum;
        }
    }
    mi ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = ans + arr[i].first * arr[i].second;
    }
    cout << ans.v << endl;
    return 0;
}