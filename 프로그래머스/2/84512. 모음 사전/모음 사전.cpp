#include <string>
#include <vector>

using namespace std;

vector<string> dictionary;
string standard = "AEIOU";

void dfs(string cur){
    if(cur.length() > 5) return;
    
    if(!cur.empty()){
        dictionary.push_back(cur);
    }
    
    for(char c : standard){
        dfs(cur + c);
    }
}

int solution(string word) {
    dfs("");
    for(int i = 0; i < dictionary.size(); i++){
        if(dictionary[i] == word){
            return i + 1;
        }
    }
}