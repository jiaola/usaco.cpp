#include <iostream>
using namespace std;

int main(void) {
    long long n;
    cin >> n;
    while (n != 1) {
        cout << n << " ";
        if (n % 2 == 0) {
            n = (long long) n / 2;
        } else {
            n = 3 * n + 1;
        }
    }
    cout << n << endl;
    return 0;
}