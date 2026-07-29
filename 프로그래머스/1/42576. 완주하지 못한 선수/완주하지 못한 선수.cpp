#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> count;
    
    for(string p : participant){
        count[p]++;
    }
    
    for(string c : completion){
        count[c]--;
    }
    
    for(auto a : count){
        if(a.second > 0){
            return a.first;
        }
    }
    
    return "";
}