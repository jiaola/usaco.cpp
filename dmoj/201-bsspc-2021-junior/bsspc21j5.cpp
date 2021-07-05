#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> sieve(int n) {
    vector<bool> prime(n+1);
    fill(prime.begin(), prime.end(), true);
    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
    return prime;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> v = sieve(250000);
    vector<int> primes;
    vector<int> sums;
    int sum;
    for (int i = 2; i < 250000; i++) {
        if (v[i]) {
            primes.push_back(i);
            sum += i;
            sums.push_back(sum);
        }
    }

    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int x, k; cin >> x >> k;
        auto low = lower_bound(primes.begin(), primes.end(), x);
        int pos = low - primes.begin();
        cout << primes[pos+k-1] << " " << sums[pos+k-1] - sums[pos-1] << "\n";
    }
    return 0;
}