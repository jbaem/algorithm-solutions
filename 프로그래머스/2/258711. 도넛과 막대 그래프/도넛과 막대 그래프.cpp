#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <iostream>

using namespace std;

int N = 0;
vector<int> answer(4, 0);
vector<vector<int>> inE, outE;

vector<int> solution(vector<vector<int>> edges) {
    for (auto& edge : edges) {
        N = max(N, edge[0]);
        N = max(N, edge[1]);
    }
    
    inE.assign(N + 1, vector<int>());
    outE.assign(N + 1, vector<int>());
    
    // 간선 분류
    for (auto& edge : edges) {
        inE[edge[1]].push_back(edge[0]);
        outE[edge[0]].push_back(edge[1]);
    }
    
    // 중간점 찾기
    for (int curr = 0; curr < N; ++curr) {
        int indegree = inE[curr].size(), outdegree = outE[curr].size();
        
        if (indegree == 0 && outdegree > 1) {
            answer[0] = curr;
        }
    }
    for (auto start : outE[answer[0]]) {
        
        int next = start;
        if (outE[next].size() == 2) {
            answer[3]++;
        }
        else if (outE[next].size() == 0) {
            answer[2]++;
        }
        else {
            while (true) {
                if (outE[next].size() == 2) {
                    answer[3]++;
                    break;
                }
                else if (outE[next].size() == 0) {
                    answer[2]++;
                    break;
                }
                next = outE[next][0];
                
                if (next == start) {
                    answer[1]++;
                    break;
                }
            }
        }
    }
    return answer;
}