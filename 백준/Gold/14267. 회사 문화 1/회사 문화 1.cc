#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v, res;

int main() {
    fastio();

    cin >> N >> M;
    res.resize(N + 1, 0);
	v.resize(N + 1);

    for (int i = 1; i <= N; ++i) {
        int tmp; cin >> tmp;
        if (tmp == -1) tmp = 0;
        v[i] = tmp;
    }

    for (int i = 0; i < M; ++i) {
        int num, score; cin >> num >> score;
		res[num] += score;
    }

    for(int i = 1; i <= N; ++i) {
        res[i] += res[v[i]];
        cout << res[i] << ' ';
	}
    return 0;
}