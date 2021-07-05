#include <iostream>
using namespace std;

int main() {
    int N, M, X, Y, A, B, C, D;
    cin >> N >> M >> X >> Y >> A >> B >> C >> D;
    int ans = max(0, A-N) * X + max(0, B-M) * Y;
    int N2 = N, M2 = M;
    while (M2 < B) {
        N2 -= C;
        M2 += D;
        ans = min(ans, max(0, A-N2) * X + max(0, B-M2) * Y);
    }
    N2 = N;
    M2 = M;
    while (N2 < A) {
        N2 += C;
        M2 -= D;
        ans = min(ans, max(0, A-N2) * X + max(0, B-M2) * Y);
    }
    cout << ans << "\n";
}