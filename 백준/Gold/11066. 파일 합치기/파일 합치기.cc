#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int T, N, matrix[500][500][2]; //{curr, prefixSum}

void update_matrix(int s, int e) {
    matrix[s][e][0] = matrix[s][s][0] + matrix[s + 1][e][0];
    matrix[s][e][1] = matrix[s][s][1] + matrix[s + 1][e][1] + matrix[s][e][0]; //[s][s][1]==0

    for (int k = s + 1; k < e; k++) {
        int tmp[2];
        tmp[0] = matrix[s][k][0] + matrix[k + 1][e][0];
        tmp[1] = matrix[s][k][1] + matrix[k + 1][e][1] + tmp[0];

        if (matrix[s][e][1] > tmp[1]) {
            matrix[s][e][1] = tmp[1];
            matrix[s][e][0] = tmp[0];
        }
    }
}

void init_matrix() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j][0] = 0;
            matrix[i][j][1] = 0;
        }
    }
}

int main() {
    fastio();

    cin >> T;
    while (T-- > 0) {
        cin >> N;
        init_matrix();

        for (int i = 0; i < N; ++i) cin >> matrix[i][i][0];

        for (int len = 1; len < N; len++) {
            for (int i = 0; i < N; i++) {
                if (i + len >= N) continue;
                update_matrix(i, i + len);
            }
        }
        cout << matrix[0][N - 1][1] << "\n";
    }
    return 0;
}