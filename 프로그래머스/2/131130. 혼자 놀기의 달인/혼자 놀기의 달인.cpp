#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> res;
vector<bool> visited;

void addNum(int& sumNum, vector<int>& cards, int idx) {
    if (visited[idx]) return;
    visited[idx] = true;
    sumNum++;
    addNum(sumNum, cards, cards[idx] - 1);
}

int solution(vector<int> cards) {
    visited.assign(cards.size(), false);
    
    for (int i = 0; i < cards.size(); ++i) {
        if (visited[i]) continue;
        int sumNum = 0;
        addNum(sumNum, cards, i);
        res.emplace_back(sumNum);
    }
    
    sort(res.rbegin(), res.rend());
    
    if (res.size() < 2) return 0;
    return res[0] * res[1];
}