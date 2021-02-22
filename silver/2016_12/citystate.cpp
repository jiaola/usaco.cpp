#include <iostream>
#include <unordered_map>

using namespace std;

void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("citystate");
    int n;
    cin >> n;
    unordered_map<string, unordered_map<string, int>> city_state;
    for (int i = 0; i < n; i++) {
        string city, state;
        cin >> city >> state;
        city = city.substr(0, 2);
        city_state[city][state]++;
    }
    long long ans = 0;
    for (const auto & item: city_state) {
        const string & city = item.first;
        for (const auto & state_count: item.second) {
            const string & state = state_count.first;
            if (city == state) {
                continue;
            }
            if (city_state.find(state) != city_state.end()) {
                if (city_state[state].find(city) != city_state[state].end()) {
                    ans += city_state[state][city] * state_count.second;
                }
            }
        }
    }
    cout << ans / 2 << "\n";
    return 0;
}