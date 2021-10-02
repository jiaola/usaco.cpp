#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

struct Timestamp {
    int id;
    int time;;
    bool starting;
    bool operator < (const Timestamp& y) {
        return time < y.time;
    }
};

int main() {
    setIO("lifeguards");
    int N;
    cin >> N;
    Timestamp ts[2*N];
    int single_time[N];
    int total = 0;
    for (int i = 0; i < N; ++i) {
        single_time[i] = 0;
        int t1, t2;
        cin >> t1 >> t2;
        ts[2*i]= {i, t1, true};
        ts[2*i+1] = {i, t2, false};
    }
    sort(ts, ts+2*N);
    set<int> on_duty;
    int prev = 0;
    for (int i = 0; i < 2 * N; ++i) {
        Timestamp t = ts[i];
        if (on_duty.size() > 0) {
            total += t.time - prev;
        }
        if (on_duty.size() == 1) {
            int id = *on_duty.begin();
            single_time[id] += t.time - prev;
        }
        if (t.starting) {
            on_duty.insert(t.id);
        } else {
            on_duty.erase(t.id);
        }
        prev = t.time;
    }
    int m = *min_element(single_time, single_time + N);
    cout << total - m << "\n";
    return 0;
}