#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <deque>

using namespace std;

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
    vector<vector<int>> board(m, vector<int>(n, INT_MAX)); // 모든 값 기본적으로 0
    
    for(int i = 0; i < drops.size(); i++){
        int r = drops[i][0]; // 행
        int c = drops[i][1]; // 열
        
  
        board[r][c] = i + 1; 
    }
    
    // 가로로 길이 w짜리 구간을 몇 개 만들 수 있는지
    int colSize = n - w + 1;
    
    // 크기가 m x colSize인 2차원 벡터 만들기
    vector<vector<int>> rowMin(m, vector<int>(colSize));
    // rowMin[r][c] => r번째 행에서 c열부터 c+w-1열까지의 최솟값
    
    for(int r = 0; r < m; r++){
        deque<int> dq; // dq에는 값이 아닌 인덱스를 추가하는 것.
        
        for(int c = 0; c < n; c++){
            // 슬라이딩 윈도우 핵심 규칙
            // 1. 창문 밖으로 나간 값은 앞에서 제거
            // 2. 새 값보다 큰 값은 뒤에서 제거
            
            while(!dq.empty() && board[r][dq.back()] >= board[r][c]){
                dq.pop_back();
            }
            
            // 현재 열의 인덱스 추가
            dq.push_back(c);
            
            // 현재 윈도우 밖으로 나간 인덱스 제거
            if(!dq.empty() && dq.front() <= c-w){
                dq.pop_front();
            }
            
            // 길이 w짜리 윈도우가 완성됐을 때
            if(c >= w - 1){
                // 현재 윈도우 시작 열
                int startC = c - w + 1;
                
                // deque의 맨 앞이 최솟값
                rowMin[r][startC] = board[r][dq.front()];
            }
        }
    }
    
    int bestR = 0;
    int bestC = 0;
    int bestTime = -1;
    
    // rowMin에서 세로 h칸의 최솟값 구하기
    for(int c = 0; c < colSize; c++){
        deque<int> dq;
        
        for(int r = 0; r < m; r++){
            // 새 값보다 큰 값 제거
            while(!dq.empty() && rowMin[dq.back()][c] >= rowMin[r][c]){
                dq.pop_back();
            }
            
            dq.push_back(r);
            
            // 세로 윈도우 밖으로 나간 행 제거
            if(!dq.empty() && dq.front() <= r-h){
                dq.pop_front();
            }
            
            // 높이 h짜리 윈도우가 완성됐을 때
            if(r >= h-1){
                int startR = r - h + 1;
                
                // 이 값이 h * w 내부의 최솟값
                int firstHit = rowMin[dq.front()][c];
                
                // 처음 비 맞는 시간이 더 늦다면 갱신
                // 같은 경우: 행 작은 것 → 열 작은 것
                if(bestTime < firstHit || (bestTime == firstHit && 
                                          (startR < bestR ||
                                          (startR == bestR && c < bestC)))){
                    bestTime = firstHit;
                    bestR = startR;
                    bestC = c;
                }
            }
        }
    }
    
    return {bestR, bestC};
}