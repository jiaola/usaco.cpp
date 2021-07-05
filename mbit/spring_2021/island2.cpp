#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<pair<int, int>> ans;
vector<vector<int>> graph;
int N;
vector<int> visited;

void dfs1(int p, int v) {
    for (int u: graph[v]) {
        if (!visited[u]) {
            visited[u] = 1;
            dfs1(v, u);
        }
    }
    if (p != -1) {
        ans.push_back(make_pair(p, v));
    }
}

void dfs2(int v) {
    for (int u: graph[v]) {
        if (!visited[u]) {
            visited[u] = 1;
            ans.push_back(make_pair(u, v));
            dfs2(u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    graph.resize(N);
    visited.resize(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    fill(visited.begin(), visited.end(), 0);
    visited[0] = 1;
    dfs1(-1, 0);

    fill(visited.begin(), visited.end(), 0);
    visited[0] = 1;
    dfs2(0);

    for (auto &p: ans) {
        cout << p.first + 1 << " " << p.second + 1 << "\n";
    }
}
