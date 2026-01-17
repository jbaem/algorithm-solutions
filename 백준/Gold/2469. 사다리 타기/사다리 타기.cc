#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int K = 0, C = 0, N = 0, atoz = 'z' - 'a' + 1;
vector<vector<char>> v;
vector<char> res, top, bot;

void resizeAll() {
    C = K - 1;
    top.resize(K);
    bot.resize(K);
    
    v.resize(N, vector<char>(C));
    res.resize(C);
}

void inputAll() {
    for (int i = 0; i < K; ++i) {
        top[i] = 'A' + i;
        cin >> bot[i];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> v[i][j];
        }
    }
}

void swap(char& a, char& b) {
    char tmp = a;
    a = b;
    b = tmp;
}

bool checkSwapping(vector<char>& vec, int row) {
    if (v[row][0] == '?') return false;

    for (int i = 0; i < C; ++i) {
        if (v[row][i] == '-') swap(vec[i], vec[i + 1]);
    }
    return true;
}

void executeTopDown() {
    for (int i = 0; i < N; ++i) {
        if (!checkSwapping(top, i)) break;
    }
}

void executeBottomUp() {
    for (int i = N - 1; i >= 0; --i) {
        if (!checkSwapping(bot, i)) break;
    }
}

void fillResultVector() {
    for (int i = 0; i < C; ++i) {
        if (top[i] == bot[i]) {
            res[i] = '*';
        }
        else {
            res[i] = '-';
            swap(top[i], top[i + 1]);
        }
    }
}

void checkValid() {
    bool bIsValid = true;
    for (int i = 0; i < K; ++i) {
        bIsValid &= (top[i] == bot[i]);
    }
    for (int i = 1; i < C; ++i) {
        if (res[i] == '-' && res[i] == res[i - 1]) {
            bIsValid = false;
        }
    }
    if (!bIsValid) {
        for (int i = 0; i < C; ++i) {
            res[i] = 'x';
        }
    }
}

int main() {
    fastio();
    
    cin >> K >> N;
    resizeAll();
    inputAll();

    executeTopDown();
    executeBottomUp();
    
    fillResultVector();
    checkValid();
    for (int i = 0; i < C; ++i) cout << res[i];

    return 0;
}

