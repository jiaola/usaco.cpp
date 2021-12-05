#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;

void setIO(const string& name = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!name.empty()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}


int n;
string grid[20];
struct pcl { int i1, i2, j1, j2; };
vector<pcl> v;
bool visited[20][20];


void dfs(int i, int j, int c, int i1, int i2, int j1, int j2) {
    visited[i][j] = true;
    if (i > i1 && grid[i - 1][j] - 'A' == c && !visited[i - 1][j]) {
        dfs(i - 1, j, c, i1, i2, j1, j2);
    }
    if (i < i2 && grid[i + 1][j] - 'A' == c && !visited[i + 1][j]) {
        dfs(i + 1, j, c, i1, i2, j1, j2);
    }
    if (j > j1 && grid[i][j - 1] - 'A' == c && !visited[i][j - 1]) {
        dfs(i, j - 1, c, i1, i2, j1, j2);
    }
    if (j < j2 && grid[i][j + 1] - 'A' == c && !visited[i][j + 1]) {
        dfs(i, j + 1, c, i1, i2, j1, j2);
    }

}


bool PCL(int i1, int i2, int j1, int j2) {
    int count = 0;
    int colors[26] = {0};
    for (int i = i1; i <= i2; ++i) {
        for (int j = j1; j <= j2; ++j) {
            visited[i][j] = false;
        }
    }
    for (int i = i1; i <= i2; ++i) {
        for (int j = j1; j <= j2; ++j) {
            if (!visited[i][j]) {
                int c = grid[i][j] - 'A';
                if (!colors[c]) count++;
                colors[c]++;
                dfs(i, j, c, i1, i2, j1, j2);
            }
        }
    }
    if (count != 2) return false;
    bool one = false; bool many = false;
    for (int i : colors) {
        if (i == 1) one = true;
        if (i > 1) many = true;
    }
    return one && many;
}

bool inside(int i, int j) {
    pcl a = v[i];
    pcl b = v[j];
    if (a.i1 >= b.i1 && a.i2 <= b.i2 && a.j1 >= b.j1 && a.j2 <= b.j2) return true;
    return false;
}

int main() {
    setIO("where");
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                for (int l = 0; l < n; ++l) {
                    if (PCL(i, j, k, l)) {
                        pcl p = {i, j, k, l};
                        v.push_back(p);
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < v.size(); ++i) {
        bool valid = true;
        for (int j = 0; j < v.size(); ++j) {
            if (i == j) continue;
            if (inside(i, j)) valid = false;
        }
        if (valid) ans++;
    }
    cout << ans << "\n";
    return 0;
}