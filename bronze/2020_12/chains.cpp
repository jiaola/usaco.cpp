#include <iostream>
#include <numeric>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int photos[n];
    for (int i = 0; i < n; ++i) {
        cin >> photos[i];
    }

    int total = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int sum = 0;
            for (int k = i; k <= j; ++k) {
                sum += photos[k];
            }
            int count = j - i + 1;
            if (sum % count == 0) {
                int average = int(sum / count);
                for (int k = i; k <= j; ++k) {
                    if (photos[k] == average) {
                        total++;
                        break;
                    }
                }
            }
        }
    }
    cout << total << endl;
}

