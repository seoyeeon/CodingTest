#include <string>
#include <vector>
#include <queue>

using namespace std;

// 단어 하나만 다른지 확인하는 함수
bool canChange(string a, string b){
    int diff = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]){
            diff++;
        }
    }
    return diff == 1;
}

int solution(string begin, string target, vector<string> words) {
    // target이 words에 없으면 변환 불가능
    bool exist = false;
    
    for(string word : words){
        if(word == target){
            exist = true;
            break;
        }
    }
    
    if(!exist) return 0;
    
    // int : 현재 단어까지 오는데 걸린 변환 횟수
    queue<pair<string, int>> q;
    
    vector<bool> visited(words.size(), false);
    
    q.push({begin, 0});
    
    while(!q.empty()){
        string current = q.front().first;
        int count = q.front().second;
        
        q.pop();
        
        // target 도착
        if(current == target){
            return count;
        }
        
        // 변환 가능한 다음 단어 탐색
        for(int i = 0; i < words.size(); i++){
            // 아직 방문안했고
            // 글자 하나만 다르면 이동 가능
            if(!visited[i] && canChange(current, words[i])){
                visited[i] = true;
                q.push({words[i], count+1});
            }
        }
    }
    
    return 0;
}