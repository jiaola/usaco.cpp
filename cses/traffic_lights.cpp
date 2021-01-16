#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int x, n, p;
set<int> lights;
multiset<int> gaps;

int main() {
    cin >> x >> n;
    lights.insert(0);
    lights.insert(x);
    gaps.insert(x);
    for (int i = 0; i < n; ++i) {
        cin >> p;
        auto it1 = lights.upper_bound(p), it2 = it1;
        --it2;
        gaps.erase(gaps.find(*it1 - *it2));
        gaps.insert(p - *it2);
        gaps.insert(*it1 - p);
        lights.insert(p);
        auto ans = gaps.end();
        --ans;
        cout << *ans << " ";
    }
    return 0;
}