#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> adj[100000];
int visited[100000];
vector<pair<int, int>> ans;

void dfs1(int p, int v) {
    for (int u: adj[v]) {
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
    for (int u: adj[v]) {
        if (!visited[u]) {
            visited[u] = 1;
            ans.push_back(make_pair(u, v));
            dfs2(u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(visited, 0, sizeof(visited));
    visited[0] = 1;
    dfs1(-1, 0);

    memset(visited, 0, sizeof(visited));
    visited[0] = 1;
    dfs2(0);

    for (auto &p: ans) {
        cout << p.first + 1 << " " << p.second + 1 << "\n";
    }
}
