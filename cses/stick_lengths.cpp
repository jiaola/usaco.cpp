#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    long long s[n];
    long long total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        total += s[i];
    }
    double ad = ((double) total) / n;
    long long n1 = ceil(ad);
    long long n2 = floor(ad);
    long long n3 = n1 + 1;
    long long n4 = n2 - 1;
    long long ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
    for (int i = 0; i < n; ++i) {
        ans1 += abs(n1 - s[i]);
        ans2 += abs(n2 - s[i]);
        ans3 += abs(n3 - s[i]);
        ans4 += abs(n4 - s[i]);
    }
    cout << min(min(min(ans1, ans2), ans3), ans4) << endl;
    return 0;
}