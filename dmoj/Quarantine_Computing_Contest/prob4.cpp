#include <iostream>
using namespace std;

const int MOD = 998244353;
long long fact[1000001];

long long power(long long x, int y, int p) {
    long long res = 1;
    x = x % p;
    while (y) {
        if (y % 2 == 1) {
            res = (res * x) % p;
        }
        y /= 2;
        x = x * x % p;
    }
    return res;
}

long long mod_inverse(long long n, int p) {
    return power(n, p-2, p);
}


long long nCr_mod_p(long long n, int r, int p) {
    if (n < r) {
        return 0;
    }
    if (r == 0) {
        return 1;
    }
    return (fact[n] * mod_inverse(fact[r], p) % p * mod_inverse(fact[n-r], p) % p) % p;
}

int main() {
    fact[0] = 1;
    for (long long i = 1; i < 1000001; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    long long T, N, K, Q;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> N >> K >> Q;
        cout << nCr_mod_p(N-K*Q+1, Q, MOD) << "\n";
    }
    return 0;
}