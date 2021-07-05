#include <iostream>
using namespace std;

int main() {
    int N, M, X, Y, A, B, C, D;
    cin >> N >> M >> X >> Y >> A >> B >> C >> D;
    int ans = INT32_MAX;
    for (int i = -1000; i <= 1000; ++i) {
        ans = min(ans, max(0, A + i * C - N) * X + max(0, B - i * D - M) * Y);
    }
    cout << ans << "\n";
}