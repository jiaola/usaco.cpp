#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
//        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("prob3");
    return 0;
}