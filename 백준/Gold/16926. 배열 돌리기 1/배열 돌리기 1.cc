#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>

using namespace std;

int N, M, R, arr[300][300];

void printAll() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void rotate(int y1, int x1, int y2, int x2) {
    int tmp = arr[y1][x1];
    for (int i = x1 + 1; i <= x2; ++i) arr[y1][i - 1] = arr[y1][i];
    for (int i = y1 + 1; i <= y2; ++i) arr[i - 1][x2] = arr[i][x2];
    for (int i = x2 - 1; i >= x1; --i) arr[y2][i + 1] = arr[y2][i];
    for (int i = y2 - 1; i >= y1; --i) arr[i + 1][x1] = arr[i][x1];
    arr[y1 + 1][x1] = tmp;
}

void rotateAll() {
    int y1 = 0, x1 = 0, y2 = N - 1, x2 = M - 1;
    while (y1 < y2 && x1 < x2) {
        rotate(y1++, x1++, y2--, x2--);
    }
}

int main() {
    fastio();

    cin >> N >> M >> R;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < R; ++i) rotateAll();
    printAll();
    return 0;
}