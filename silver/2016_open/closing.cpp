#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <numeric>
using namespace std;

const int MAX_N = 3000;
int visited[MAX_N];
vector<int> adj[MAX_N];
int in_graph[MAX_N];
int ans = 0;

void setIO(string name="") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void dfs(int u) {
    if (visited[u]) return;
    visited[u] = 1;
    for (int v: adj[u]) {
        if (in_graph[v])
            dfs(v);
    }
}

int solve() {
    auto itr = find(in_graph, in_graph + MAX_N, 1);
    int u = distance(in_graph, itr);
    dfs(u);
    int count = accumulate(visited, visited + MAX_N, 0); 
    return count;
}

int main() {
    setIO("closing");
    int N, M; cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int u, v; cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    for (int i = 0; i < N; ++i) {
        in_graph[i] = 1;
    }
    if (solve() == N) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    for (int i = 0; i < N-1; ++i) {
        int u; cin >> u;
        in_graph[u-1] = 0;
        fill(visited, visited+N, 0);
        if (solve() == N-i-1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}