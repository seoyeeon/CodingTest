#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int fatigue, vector<vector<int>> &dungeons, vector<bool> &visited, int count){
    // 최대값 갱신
    answer = max(answer, count);
    
    for(int i = 0; i < dungeons.size(); i++){
        // 이미 방문한 던전이면 스킵
        if(visited[i]) continue;
        
        int need = dungeons[i][0];
        int consume = dungeons[i][1];
        
        // 현재 피로도로 입장 가능하면
        if(fatigue >= need){
            visited[i] = true;
            
            // 다음 탐색
            dfs(fatigue-consume, dungeons, visited, count+1);
            
            // 백트래킹
            visited[i] = false;
        }
        
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> visited(dungeons.size(), false);
    
    dfs(k, dungeons, visited, 0);
    
    return answer;
}