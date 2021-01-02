#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    vector<int> v = {4,2,5,3,5,8,3};
    sort(v.rbegin(), v.rend());
    for (auto &x: v) {
        cout << x << endl;
    }

    int n = 7; // array size
    int a[] = {4,2,5,3,5,8,3};
    sort(a,a+n);
    for (int x: a) {
        cout << x << endl;
    }
    cout << a[0] << endl;
}