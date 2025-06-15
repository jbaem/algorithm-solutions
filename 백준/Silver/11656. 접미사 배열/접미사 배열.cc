//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("test.txt", "r", stdin);

    string str; cin >> str;
    priority_queue<string, vector<string>, greater<string>> pq;
    for (int i = 0; i < str.length(); ++i) pq.push(str.substr(i));
    while (!pq.empty()) { cout << pq.top() << "\n"; pq.pop(); }

    return 0;
}