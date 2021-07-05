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
//        freopen((name+".out").c_str(), "w", stdout);
    }
}

int N, M;

int main() {
    setIO("prob3");
    cin >> N >> M;
    vector<pair<int, int>> vn = vector<pair<int, int>>(N);
    vector<pair<int, int>> vm = vector<pair<int, int>>(M);
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        vn[i] = make_pair(x, y);
    }
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        vm[i] = make_pair(x, y);
    }
    sort(vn.begin(), vn.end());
    sort(vm.begin(), vm.end());

    int j = 0;
    for (int i = 0; i < M; ++i) {
        while (j < N && vn[j] < vm[i]) {
            ++j;
        }

    }

    int ni, mi = 0;
    while (ni < N && mi < N) {

    }
    while (vn[ni].first > vm[mi].first) {
        ++ni;
    }

    for (int i = 0; i < N; ++i) {
        cout << vn[i].first << " " << vn[i].second << "\n";
    }
    return 0;
}

/*

1. Worked on mappings of values from GDC/PDC to CRDC-H CDM for the attributes in the MVP model
2. Working on API for a codeset service to expand a list of concept codes to concept references.
3. Working on LinkML generators to create CRDC-H models with enumerated list of values

*/