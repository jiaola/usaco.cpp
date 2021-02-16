#include <iostream>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    long long cnt[100001];
    for (int i = 0; i < 100001; ++i) {
        cnt[i] = 0;
    }
    int k;
    for (int i = 0; i < N; ++i) {
        cin >> k;
        cnt[k] += 1;
    }
    int t, q;
    for (int i = 0; i < Q; ++i) {
        cin >> t >> q;
        if (t == 1) {
            if (q % 2 == 0) {
                cnt[q / 2] += cnt[q] * 2;
            } else {
                cnt[q / 2] += cnt[q];
                cnt[q / 2 + 1] += cnt[q];
            }
            cnt[q] = 0;
        } else {
            cout << cnt[q] << "\n";
        }
    }

}