#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for (auto& skill_tree : skill_trees) {
        unordered_set<char> us;
        bool flag = false;
        
        for (int i = 0; i < skill_tree.size(); ++i) {
            char curr = skill_tree[i];
            auto found = skill.find(curr);
            
            us.insert(skill_tree[i]);
            
            if (found == string::npos) {
                continue;
            }
            
            for (int j = 0; j < found; ++j) {
                if (us.find(skill[j]) == us.end()) {
                    flag = true;
                    break;
                }
            }
            if (flag) break;    
        }
        if (!flag) answer++;   
    }
    return answer;
}