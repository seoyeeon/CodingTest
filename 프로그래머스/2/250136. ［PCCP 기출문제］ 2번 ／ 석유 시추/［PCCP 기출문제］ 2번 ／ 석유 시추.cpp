#include <string>
#include <vector>
#include <set>

using namespace std;

int n, m;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

vector<vector<int>> visited;
vector<int> oilSize();

int dfs(int r, int c, int id, vector<vector<int>> &land, set<int> &cols){
    visited[r][c] = id;
    
    // 석유 덩어리 크기 세기 위한 변수
    int count = 1;
    
    cols.insert(c);
    
    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
        
        if(land[nr][nc] == 0) continue;
        
        
        // 이미 방문했으면
        if(visited[nr][nc] != 0) continue;
        
        count += dfs(nr, nc, id, land, cols);
    }
    
    return count;
}

int solution(vector<vector<int>> land) {
    n = land.size();
    m = land[0].size();
    
    // 벡터 초기화
    visited.assign(n, vector<int>(m, 0));
    
    vector<int> columnOil(m, 0);
    
    int id = 1;
    
    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            if(land[r][c] == 1 && visited[r][c] == 0){
                set<int> cols;
                
                int size = dfs(r, c, id, land, cols);
                
                // 이 덩어리가 포함된 열들에 크기 추가
                for(int col : cols){
                    columnOil[col] += size;
                }
                
                id++;
            }
        }
    }
    
    int answer = 0;
    
    for(int oil : columnOil){
        answer = max(answer, oil);
    }
    return answer;
}