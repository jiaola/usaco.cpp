#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<vector<int>> foo(3);
    for (int i = 0; i < 3; i++) {
        cout << foo[i].size() << "\n";
    }
    vector<int> arr[5];
    for (int i = 0; i < 5; i++) {
        arr[i].push_back(5);
        cout << arr[i].size() << "\n";
    }

    int bar[5];
    return 0;
}