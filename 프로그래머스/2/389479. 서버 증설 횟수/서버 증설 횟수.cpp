#include <string>
#include <vector>
#include <queue>

using namespace std;

using pii = pair<int, int>;

int solution(vector<int> players, int m, int k) {
    int answer = 0, cnt = 0;
    
    queue<pii> q; // fin, cnt

    for (int i = 0; i < players.size(); ++i) {
        if (!q.empty() && q.front().first == i) {
            cnt -= q.front().second;
            q.pop();
        }
                
        int needSv = players[i] / m;
        if (needSv > cnt) {
            int addSv = needSv - cnt;
            q.push({i + k, addSv});
            cnt += addSv;
            answer += addSv;
        }
    }
    return answer;
}