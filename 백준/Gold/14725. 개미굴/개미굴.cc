#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;


class Node {
    string val;
    map<string, Node*> next;
public:
    Node(string str) {
        this->val = str;
    }
    string get_val() {
        return this->val;
    }
    Node* get_next(string str) {
        return this->next[str];
    }
    bool has_next(string str) {
        return this->next.count(str) != 0;
    }
    void insert_child(string str) {
        next.insert({ str, new Node(str) });
    }
    map<string, Node*> get_map() {
        return this->next;
    }
};

int N;
Node* hive = new Node("");

void pre_order(Node* root, int num) {
    if (num >= 0) {
        for (int i = 0; i < num; ++i) {
            cout << "--";
        }
        cout << root->get_val() << "\n";
    }

    for (auto iter : root->get_map()) {
        pre_order(iter.second, num + 1);
    }
}

int main() {
    fastio();

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int tmp; cin >> tmp;

        Node* curr = hive;
        for (int j = 0; j < tmp; ++j) {
            string str; cin >> str;
            if (!curr->has_next(str)) {
                curr->insert_child(str);
            }
            curr = curr->get_next(str);
        }
    }
    pre_order(hive, -1);
    return 0;
}