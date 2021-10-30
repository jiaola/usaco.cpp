#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 200;
vector<int> adj[MAX_N];
int visited[MAX_N];

void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int dfs(int u) {
    if (visited[u]) return 0;
    visited[u] = 1;
    int count = 1;
    for (int v: adj[u]) {
        count += dfs(v);
    }
    return count;
}

int main() {
    setIO("moocast");
    int N; cin >> N;
    int x[N], y[N], p[N];
    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i] >> p[i];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            int dist = (y[i]-y[j]) * (y[i]-y[j]) + (x[i]-x[j]) * (x[i]-x[j]);
            if (dist < p[i] * p[i]) {
                adj[i].push_back(j);
            }
            if (dist < p[j] * p[j]) {
                adj[j].push_back(i);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        fill(visited, visited+N, 0);
        ans = max(ans, dfs(i));
    }
    cout << ans << "\n";
    return 0;
}