#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, percent[4];
bool visited[31][31];
double res = 0;


int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

void dfs(int y, int x, int cnt, double curr) {
    if (curr == 0 || visited[y][x]) return;

    if (cnt == N) {
        res += curr;
        return;
    }

    visited[y][x] = true;
    for (int i = 0; i < 4; ++i) {
        dfs(y + dy[i], x + dx[i], cnt + 1, curr * percent[i] / 100);
    }
    visited[y][x] = false;
}

int main() {
    fastio();

    cin >> N;
    for (int i = 0; i < 4; ++i) cin >> percent[i];
    
    dfs(15, 15, 0, 1);

    cout.precision(10);
    cout << res << "\n";
    return 0;
}
