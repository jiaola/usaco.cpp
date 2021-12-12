// Source: https://usaco.guide/general/io

#include <iostream>
using namespace std;

const int MAX_N = 1000;
char grid[MAX_N][MAX_N];
int side;
bool visited[MAX_N][MAX_N];
int cur_size = 0;
int cur_perim = 0;

void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void floodfill(int r, int c) {
	if (r < 0 || c < 0 || r >= side || c >= side || grid[r][c] == '.') {
        cur_perim++;
        return;
    }
	if (visited[r][c]) return;
	visited[r][c] = true;
	cur_size++;

	floodfill(r-1, c);
	floodfill(r+1, c);
	floodfill(r, c-1);
	floodfill(r, c+1);
}

int main() {
    setIO("perimeter");
	cin >> side;
	for (int i = 0; i < side; ++i) {
		for (int j = 0; j < side; ++j) {
            cin >> grid[i][j];
		}
	}
	int ans = 0, perim = 0;
	for (int i = 0; i < side; ++i) {
		for (int j = 0; j < side; ++j) {
			if (!visited[i][j]) {
				floodfill(i, j);
                if (cur_size > ans) {
                    ans = cur_size;
                    perim = cur_perim;
                } else if (cur_size == ans) {
                    perim = min(cur_perim, perim);
                }
				cur_size = 0;
                cur_perim = 0;
			}
		}
	}
	cout << ans << " " << perim << "\n";
}