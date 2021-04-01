#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

int N, K;
vector<vector<int>> pos;
vector<int> kmap;
vector<bool> visited;

void cc(int i, vector<int> &c) {
    visited[i] = true;
    c.push_back(i);
    if (!visited[kmap[i]]) {
        cc(kmap[i], c);
    }
}

int main(void) {
//    setIO("prob1");
    cin >> N >> K;
    pos.resize(N);
    kmap.resize(N);
    visited.resize(N);

    for (int i = 0; i < N; ++i) {
        kmap[i] = i;
        visited[i] = false;
        pos[i].push_back(i);
    }
    int a, b, c;
    for (int i = 0; i < K; ++i) {
        cin >> a >> b;
        c = kmap[a - 1];
        kmap[a - 1] = kmap[b - 1];
        kmap[b - 1] = c;
        pos[kmap[b - 1]].push_back(b - 1);
        pos[kmap[a - 1]].push_back(a - 1);
    }

    vector<vector<int>> connected;
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            vector<int> comp = vector<int>();
            cc(i, comp);
            connected.push_back(comp);
        }
    }
    int cnt[N];
    for (vector<int> &con: connected) {
        unordered_set<int> s = unordered_set<int>();
        for (int i: con) {
            for (int j: pos[i]) {
                s.insert(j);
            }
        }
        int l = s.size();
        for (int i: con) {
            cnt[i] = l;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << cnt[i] << endl;
    }
    return 0;
}