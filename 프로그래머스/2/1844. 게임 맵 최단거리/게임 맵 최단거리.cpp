#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    
    // 방문 체크
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    // 상 하 좌 우
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    // {x, y}
    queue<pair<int, int>> q;
    
    q.push({0, 0});
    visited[0][0] = true;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        
        // 4방향 탐색
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 맵 범위 밖
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            
            // 벽이면 이동 불가
            if(maps[nx][ny] == 0) continue;
            
            // 이미 방문
            if(visited[nx][ny]) continue;
            
            
            visited[nx][ny] = true;
            
            // 이전 칸 거리 + 1
            maps[nx][ny] = maps[x][y] + 1;
            
            q.push({nx, ny});
            
        }
    }
    // 도착 못했으면
    if(maps[n-1][m-1] == 1){
        return -1;
    }
    
    return maps[n-1][m-1];
}