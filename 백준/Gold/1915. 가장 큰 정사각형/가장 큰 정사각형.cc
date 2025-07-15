#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>

using namespace std;

int N, M, tmp, arr[1001][1001], res = 0;

void check_square(int y, int x) {
    while (y <= N && x <= M) {
        for (int dist = 0; dist <= N + M; dist++) {
            int surf = (dist + 1) * (dist + 1);

            int r = y + dist, c = x + dist;
            if (r > N || c > M) return;

            int curr = arr[r][c] + arr[y - 1][x - 1]
                - arr[y - 1][c] - arr[r][x - 1];

            if (surf == curr) {
                res = max(res, surf);
            }
            else {
                y++; x++;
                dist -= 2;
            }
        }
    }
}

int main() {
    fastio();

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            char ch; cin >> ch;
            tmp = ch - '0';
            arr[i][j] = tmp + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= N; ++i) {
        check_square(i, 1);
    }
    for (int j = 1; j <= M; ++j) {
        check_square(1, j);
    }
    cout << res;
    return 0;
}