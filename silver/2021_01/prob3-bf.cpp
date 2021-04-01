/**
 * Brute force solution. Passes case 1-10 but Timeout 11-20
 */

#include <iostream>
#include <algorithm>


using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
        // freopen((name+".out").c_str(), "r", stdout);
    }
}

long long g[1000][1000];
bool c[1000][1000];
int N;


long long solve(int i, int j, long long sum) {
    long long ans = -1;
    for (int k = 0; k <= 1; ++k) {
        // cout << i << " " << j << " " << k << " " << sum << "\n";
        if (i == 1 || j == 1 || c[i-1][j-1] + c[i-1][j] + c[i][j-1] + k == 2) {
            sum += k * g[i][j];
            c[i][j] = k;
            if (i == N && j == N) {
                return sum;
            } else {
                long long s;
                if (j == N) {
                    s = solve(i+1, 1, sum);
                } else {
                    s = solve(i, j+1, sum);
                }
                if (s > ans) ans = s;
            }
            c[i][j] = false;
        }
    }
    return ans;
}

int main(void) {
    setIO("");

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> g[i][j];
            c[i][j] = false;
        }
    }
    long long ans = solve(1, 1, 0);
    cout << ans << "\n";
}