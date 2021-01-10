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

int main() {
    setIO("trapped");
    int N;
    cin >> N;
    vector<pair<int, int>> vect;
    for (int i = 0; i < N; ++i) {
        int s, x;
        cin >> s >> x;
        vect.push_back(pair<int, int>(x, s));
    }
    sort(vect.begin(), vect.end());
    int total = 0;
    for (int i = 0; i < N - 1; ++i) {
        int delta = vect[i+1].first - vect[i].first;
        int left = i, right = i+1;
        while (left >= 0 && right < N) {
            bool stuck = true;
            int dist = vect[right].first - vect[left].first;
            if (dist > vect[left].second) {
                left--;
                stuck = false;
            }
            if (dist > vect[right].second) {
                right++;
                stuck = false;
            }
            if (stuck) {
                break;
            }
        }
        if (left >= 0 && right < N) {
            total += delta;
        }
    }
    cout << total << endl;
    return 0;
}