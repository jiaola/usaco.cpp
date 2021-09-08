#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, Q;
    cin >> N;
    long long x[N], y[N];
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> y[i];
    }
    long long max_x = *max_element(x, x+N);
    long long max_y = *max_element(y, y+N);
    long long min_x = *min_element(x, x+N);
    long long min_y = *min_element(y, y+N);
    long long max_r[N], max_c[N], min_r[N], min_c[N];
    for (int i = 0; i < N; ++i) {
        max_r[i] = max(max_x, y[i]);
        max_c[i] = max(max_y, x[i]);
        min_r[i] = max(min_x, y[i]);
        min_c[i] = max(min_y, x[i]);
    }
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int a, w;
        cin >> a >> w;
        if (a == 1) {
            cout << max_c[w-1] << "\n";
        } else if (a == 2) {
            cout << min_c[w-1] << "\n";
        } else if (a == 3) {
            cout << max_r[w-1] << "\n";
        } else {
            cout << min_r[w-1] << "\n";
        }
    }
    return 0;
}