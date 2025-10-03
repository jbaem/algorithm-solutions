#include <algorithm>
#include <climits>
#include <cmath>
#include <unordered_map>

using namespace std;

using pii = pair<int, int>;

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    if(t1 <= temperature && temperature <= t2) return 0;
    int answer = INT_MAX;

    int N = onboard.size();
    int dist1 = abs(t1 - temperature);
    int dist2 = abs(t2 - temperature);
    int upperBound = max(dist1, dist2);
    int lowerBound = min(dist1, dist2);        
    
    unordered_map<int, int> um; // temperature, consumed power
    um[0] = 0;
    
    for(int isPerson : onboard) {
        vector<pii> v;
        
        for(pii curr : um) {
            int onT = min(curr.first + 1, upperBound);
            int offT = max(curr.first - 1, 0);
            
            if(curr.first < lowerBound) {
                if(isPerson) continue;
                v.push_back({onT, curr.second + a});
                v.push_back({offT, curr.second});
            }
            else {
                v.push_back({onT, curr.second + a});
                v.push_back({curr.first, curr.second + b});
                v.push_back({offT, curr.second});
            }
        }
        um.clear();
        for(pii curr : v) {
            if(um.find(curr.first) != um.end()) {
                um[curr.first] = min(um[curr.first], curr.second);
            }
            else {
                um[curr.first] = curr.second;
            }
        }
    }    
    for(pii curr : um) {
        answer = min(answer, curr.second);
    }
    return answer;
}