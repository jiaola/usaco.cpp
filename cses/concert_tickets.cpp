#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int n, m, h, t;
multiset<int> tickets;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> h;
        tickets.insert(h);
    }
    for (int i = 0; i < m; ++i) {
        cin >> t;
        auto it = tickets.upper_bound(t);
        if (it == tickets.begin()) {
            cout << -1 << endl;
        } else {
            cout << *(--it) << endl;
            tickets.erase(it);
        }
    }
    return 0;
}