#include <iostream>
using namespace std;

const int MAX_N = 1000;
int grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int n;
int cur_size;
int cur_perim;


void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void floodfill(int r, int c) {
    if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] == 0) {
        cur_perim++; 
        return;
    }
    if (visited[r][c]) return;
    visited[r][c] = true;
    cur_size++;
    floodfill(r+1, c);
    floodfill(r-1, c);
    floodfill(r, c-1);
    floodfill(r, c+1);
}

int main() {
    setIO("perimeter");
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c; cin >> c;
            if (c == '#') grid[i][j] = 1;
        }
    }
    int ans_size = 0; 
    int ans_perim = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!visited[i][j]) {
                cur_size = 0;
                cur_perim = 0;
                floodfill(i, j);
                if (cur_size > ans_size) {
                    ans_size = cur_size;
                    ans_perim = cur_perim;
                } else if (cur_size == ans_size) {
                    ans_perim = min(ans_perim, cur_perim);
                }                
            }
        }
    }
    cout << ans_size << " " << ans_perim << "\n";
}