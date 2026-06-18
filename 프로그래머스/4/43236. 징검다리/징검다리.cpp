#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 최솟값이 최대가 되도록 바위 제거
// => 모든경우 봐야 해서 힘듦
// 최솟값을 직접 구하지 말고 특정한 x값 이상이 되게 하자!
// 특정값(x) 이하면 불가능으로 해서 빼보자.
// 그 빼는 개수가 n이어야함. 
// x가 만족하면 x이하는 다 만족하는 것임.
// x+1이 n보다 많은 개수를 빼게 되면 x가 최댓값이 됨.
// 경계가있다 -> 전형적인 이분탐색!!
int solution(int distance, vector<int> rocks, int n) {
    
    
    sort(rocks.begin(), rocks.end());
    
    rocks.push_back(distance);
    
    int left = 1; // 바위는 적어도 1이상의 위치.
    int right = distance;
    int answer = 0;
    
    while(left <= right){
        int mid = (left + right)/2; // 최소 거리 후보
        
        int prev = 0; 
        int removed = 0;
        
        for(int rock : rocks){
            
            // 현재 바위를 유지했을 때 거리
            if(rock-prev < mid){
                removed++; // 제거
            } else{
                prev = rock; // 유지
            }
        }
        
        // n개 이하 제거로 가능
        // 정확히 n일 필요가 없는이유
        // => n개 이하면 추가로 지워도 최솟값은 같기 때문
        if(removed <= n){
            answer = mid;
            left = mid + 1; // 더 큰 최소거리 도전
        } else{
            right = mid - 1;
        }
        
    }
    
    return answer;
}