#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
    }
}

struct Node {
    char letter;
    vector<Node*> children;
    Node* parent;
};

int N, Q;
vector<Node*> nn;

struct Node* newNode(char c) {
    Node* n = new Node;
    n->letter = c;
    n->parent = NULL;
    n->children = vector<Node*>();
    return n;
}

int count(const Node &node, int cnt) {
    cnt += node.children.size();
    for (const Node* child: node.children) {
        cnt = count(*child, cnt);
    }
    return cnt;
}

Node* build(string s, int n) {
    Node* root = newNode('0');
    Node* curNode = root;
    int nc = 0;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == curNode->letter) {
            continue;
        } else if (c > curNode->letter) {
            Node* child = newNode(c);
            curNode->children.push_back(child);
            child->parent = curNode;
            curNode = child;
            nc++;
        } else {
            Node* parent = curNode->parent;
            while (parent->letter > c) {
                parent = parent->parent;
            }
            if (parent->letter == c) {
                curNode = parent;
            } else {
                Node* child = newNode(c);
                parent->children.push_back(child);
                child->parent = parent;
                curNode = child;
                nc++;
            }
        }
        nn[i] = curNode;
    }
    return root;
}

int main(void) {
    setIO("prob2");
    cin >> N >> Q;
    nn.resize(N);
    string s;
    cin >> s;
    string s1, s2;
    int cnt;
    Node* n1; Node* n2;
    long long pre[N];
    long long suf[N];
    for (int i = 0; i <= N; ++i) {
        s1 = s.substr(0, i);
        s2 = s.substr(i, s.size());
        n1 = build(s1, s1.size());
        n2 = build(s2, s2.size());
        pre[i] = count(*n1, 0);
        suf[i] = count(*n2, 0);
        delete n1;
        delete n2;
    }
    int a, b;
    for (int i = 0; i < Q; ++i) {
        cin >> a >> b;
        cout << pre[a-1] + suf[b] << endl;
    }

//    for (int i = 0; i < Q; ++i) {
//        int a, b;
//        cin >> a >> b;
//        s1 = s.substr(0, a-1);
//        s2 = s.substr(b, s.size() - b);
//        cnt = 0;
//        n1 = build(s1, s1.size());
//        n2 = build(s2, s2.size());
//        cnt += count(*n1, 0);
//        cnt += count(*n2, 0);
//        delete n1;
//        delete n2;
//        cout << cnt << endl;
//
//    }
    return 0;
}