#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int MAX_N = 100;
int grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int n;
bool lightson[MAX_N][MAX_N];
int count;

map<pair<int, int>, vector<pair<int, int>>> adj_map;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

bool next_to_visited(int r, int c) {
    if (r > 0 && visited[r-1][c]) {
        return true;
    }
    if (c > 0 && visited[r][c-1]) {
        return true;
    }
    if (r < n-1 && visited[r+1][c]) {
        return true;
    } 
    if (c < n-1 && visited[r][c+1]) {
        return true;
    }
    return false;
}

void floodfill(int r, int c) {
    if (r < 0 || c < 0 || r >= n || c >= n) return;
    if (visited[r][c]) return;
    if (!lightson[r][c]) return;
    visited[r][c] = true;
    // turn on all the lights
    for (auto room: adj_map[{r, c}]) {
        if (!lightson[room.first][room.second]) {
            // cout << room.first << " " << room.second << "\n";
            count++;
        }
        lightson[room.first][room.second] = true;
        if (next_to_visited(room.first, room.second)) {
            floodfill(room.first, room.second);
        }
    }    
    floodfill(r-1, c);
    floodfill(r+1, c);
    floodfill(r, c-1);
    floodfill(r, c+1);
}

int main() {
    setIO("lightson");
    int m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        adj_map[{r1-1, c1-1}].push_back({r2-1, c2-1});
    }
    lightson[0][0] = true;
    floodfill(0, 0);
    cout << count + 1 << "\n";
}