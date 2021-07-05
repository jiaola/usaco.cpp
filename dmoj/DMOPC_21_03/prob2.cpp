#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>

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
    setIO("");
    long long N, M;
    int K;
    cin >> N >> M >> K;
    unordered_map<long long, int> rows;
    unordered_map<long long, int> cols;
    for (int i = 0; i < K; i++) {
        long long x, y;
        cin >> x >> y;
        rows[x]++;
        cols[y]++;
    }
    vector<long long> odd_rows;
    vector<long long> odd_cols;
    for (const auto & p: rows) {
        if (p.second % 2 == 1) {
            odd_rows.push_back(p.first);
        }
    }
    for (const auto & p: cols) {
        if (p.second %2 == 1) {
            odd_cols.push_back(p.first);
        }
    }
    int diff = odd_rows.size() - odd_cols.size();
    int mn = min(odd_rows.size(), odd_cols.size());
    int a = abs(diff) + mn;
    cout << a << "\n";
    for (int i = 0; i < mn; ++i) {
        cout << odd_rows[i] << " " << odd_cols[i] << endl;
    }
    if (odd_rows.size() > odd_cols.size()) {
        for (auto it = odd_rows.begin() + mn; it != odd_rows.end(); ++it) {
            cout << *it << " " << 1 << "\n";
        }
    } else {
        for (auto it = odd_cols.begin() + mn; it != odd_cols.end(); ++it) {
            cout << 1 << " " << *it << "\n";
        }
    }
}