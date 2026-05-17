#include <string>
#include <vector>

using namespace std;

void dfs(int cur, vector<vector<int>> &computers, vector<bool> &visited){
    visited[cur] = true;
    
    // 현재 컴퓨터와 연결된 모든 컴퓨터 확인
    for(int i = 0; i < computers.size(); i++){
        if(computers[cur][i] == 1 && !visited[i]){
            dfs(i, computers, visited); // 그 컴퓨터로 이동
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i, computers, visited); // 이 컴퓨터와 연결된애들 전부 탐색
            answer++; // 네크워크 하나 발견한 것!
        }
    }
    return answer;
}