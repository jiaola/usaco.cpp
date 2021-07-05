#include <iostream>
#include <algorithm>

using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main(void) {
    setIO("paint");
    int a, b, c, d, t = 0;
    cin >> a >> b >> c >> d;
    cout << max(b, d) - min(a, c) - max(0, max(a, c) - min(b, d)) << "\n";
    return 0;
}

