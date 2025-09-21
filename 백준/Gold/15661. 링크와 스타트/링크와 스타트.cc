#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int N, result = INT_MAX;
vector<bool> visited;
vector<vector<int>> v;

int cmpSum() {
    int sumA = 0, sumB = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            
            if (visited[i] && visited[j]) {
                sumA += v[i][j] + v[j][i];
            }
            
            if (!visited[i] && !visited[j]) {
                sumB += v[i][j] + v[j][i];
            }
        }
    }
    return abs(sumA - sumB);
}

void recursion(int curr) {
    if (curr == N - 1) {
        result = min(result, cmpSum());
        return;
    }

    for (int i = curr + 1; i < N; ++i) {
        visited[i] = true;
        recursion(i);
        visited[i] = false;
    }
}

int main() {
    fastio();

    cin >> N;
    visited.resize(N, false);
    v.resize(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> v[i][j];
        }
    }
    recursion(-1);
    cout << result;
    return 0;
}