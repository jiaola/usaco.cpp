#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int M, N;
vector<vector<int>> b;
vector<vector<bool>> v;

bool dfs(int i, int j) {
    if (i > M || j > N) {
        return false;
    } else if (i == M && j == N) {
        return true;
    } else {
        if (!v[i-1][j-1]) {
            int c = b[i-1][j-1];
            v[i-1][j-1] = true;
            for (int k = 1; k < floor(pow(c, 0.5)) + 1; ++k) {
                if (c % k == 0) {
                    int l = c / k;
                    if (dfs(k, l) || dfs(l, k)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> M >> N;
    b.resize(M);
    v.resize(M);
    for (int i = 0; i < M; ++i) {
        b[i].resize(N);
        v[i].resize(N);
        for (int j = 0; j < N; ++j) {
            cin >> b[i][j];
            v[i][j] = false;
        }
    }
    if (dfs(1, 1)) {
        cout << "yes" << "\n";
    } else {
        cout << "no" << "\n";
    }
    return 0;
}