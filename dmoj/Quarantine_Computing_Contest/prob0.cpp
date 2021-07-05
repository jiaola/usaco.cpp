#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    float T;
    for (int i = 0; i < N; ++i) {
        cin >> T;
        if (T < 34) {
            cout << "Too cold, please try again." << "\n";
        } else if (T <= 35.5) {
            cout << "Take a hot bath." << "\n";
        } else if (T <= 38) {
            cout << "Rest if feeling unwell." << "\n";
        } else if (T <= 39) {
            cout << "Take some medicine." << "\n";
        } else if (T <= 41) {
            cout << "Take a cold bath and some medicine." << "\n";
        } else if (T <= 46.1) {
            cout << "Go to the hospital." << "\n";
        } else if (T <= 50) {
            cout << "Congrats, you have a new world record!" << "\n";
        } else {
            cout << "Too hot, please try again." << "\n";
        }
    }
    return 0;
}