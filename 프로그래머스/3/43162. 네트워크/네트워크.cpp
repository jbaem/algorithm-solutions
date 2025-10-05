#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


void bfs(int n, vector<vector<int>>& computers, int target, vector<bool>& visited) {
    queue<int> q;
    q.push(target);
    visited[target] = true;
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        for(int i = 0; i < n; ++i) {
            if(visited[i] || i == curr) continue;
            
            if(computers[curr][i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    
    for(int i = 0; i < n; ++i) {
        if(!visited[i]) {
            bfs(n, computers, i, visited);
            answer++;
        }
    }
    return answer;
}