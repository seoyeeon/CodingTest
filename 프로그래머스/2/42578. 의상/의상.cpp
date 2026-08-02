#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> m;
    
    for(int i = 0; i < clothes.size(); i++){
        string type = clothes[i][1];
        m[type]++;
    }
    
    int answer = 1;
    
    for(auto& t : m){
        answer *= (t.second + 1);
    }
    
    return answer-1;
}