#include <iostream>
using namespace std;

int main(void) {
    long long n;
    cin >> n;
    long long s = n * (n + 1) / 2;
    for (int i = 0; i < n - 1; ++i) {
        long long k;
        cin >> k;
        s = s - k;
    }
    cout << s << endl;
    return 0;
}