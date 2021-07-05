#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int N;

bool compare_points(const pair<int, int> &a, const pair<int, int> &b) {
    return make_tuple(a.first, a.second) < make_tuple(b.first, b.second);
}

bool equal(const pair<int, int> &a, const pair<int, int> &b) {
    return (long long) a.first * b.second == (long long) a.second * b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<pair<int, int>> p(n);
        vector<pair<int, int>> q(n);
        for (int j = 0; j < n; ++j) {
            cin >> p[j].first >> p[j].second;
        }
        for (int j = 0; j < n; ++j) {
            cin >> q[j].first >> q[j].second;
        }
        rotate(p.begin(), min_element(p.begin(), p.end(), compare_points), p.end());
        rotate(q.begin(), min_element(q.begin(), q.end(), compare_points), q.end());
        pair<int, int> factor;
        bool ok = true;
        for (int j = 1; j < n; ++j) {
            pair<int, int> v = make_pair(p[j].first - p[j - 1].first, p[j].second - p[j - 1].second);
            pair<int, int> w = make_pair(q[j].first - q[j - 1].first, q[j].second - q[j - 1].second);
            if (j == 1) {
                factor = v.first != 0 || w.first != 0 ?
                         make_pair(v.first, w.first) :
                         make_pair(v.second, w.second);
            }
            pair<int, int> p1 = make_pair(v.first, w.first);
            pair<int, int> p2 = make_pair(v.second, w.second);
            if (!(equal(p1, factor)  && equal(p2, factor))) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}

