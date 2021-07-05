#include <iostream>

using namespace std;

int N;

int main() {
    cin >> N;
    int ans = 0;
    int c = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        ans += abs(a - c);
        c = a;
    }
    ans += c;
    cout << ans + N << "\n";
    return 0;
}