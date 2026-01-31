#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0, sz = diffs.size();
    
    int l = 1, r = 100000, m; //lev
    while (l < r) {
        m = l + (r - l) / 2;
        cout << l << "," << r << "\n";
        long long tmpTime = 0;
        for (int i = 0; i < sz; ++i) {
            if (diffs[i] > m) {
                tmpTime += (long long)(diffs[i] - m) * (times[i] + times[i - 1]) + times[i];
            }
            else {
                tmpTime += times[i];
            }
        }
        if (tmpTime <= limit) {
            r = m;
        }
        else {
            l = m + 1;
        }
    }
    
    return l;
}