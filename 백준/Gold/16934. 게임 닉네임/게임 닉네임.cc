#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N, atoz = 'z' - 'a' + 1;
string str;

struct Node {
    int cnt = 0;
    bool bEnded = false;
    vector<Node*> next;
    Node(bool _bEnded) : cnt(0), bEnded(_bEnded) {
        next.resize(atoz);
    }
    ~Node() {
        for (int i = 0; i < atoz; ++i) {
            if (!next[i]) continue;
            delete next[i];
        }
    }
};

bool printNick(Node* node, const char* remain, string& prefix, bool bIsPrint) {
    if (remain[0] == '\0')
    {
        node->cnt++;
        node->bEnded = true;
        if (!bIsPrint) {
            cout << prefix << (node->cnt > 1 ? to_string(node->cnt) : "") << '\n';
        }
        return node->bEnded;
    }

    if (!node->bEnded) {
        if (!bIsPrint) {
            cout << prefix << '\n';
            bIsPrint = true;
        }
    }

    char curr = *remain;
    int idx = curr - 'a';
    prefix += curr;

    if (!node->next[idx]) {
        node->next[idx] = new Node(false);
    }
    if (printNick(node->next[idx], remain + 1, prefix, bIsPrint)) {
        node->bEnded = true;
    }
    return node->bEnded;
}

int main() {
    fastio();

    cin >> N;
    Node* root = new Node(true);

    for (int i = 0; i < N; ++i) {
        cin >> str;
        string res;
        printNick(root, str.c_str(), res, false);
    }

    delete root;
    return 0;
}