#include <string>
#include <vector>
#include <functional>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq; // greater -> functional 명시적으로 써주는 게 좋음.
    
    for(int i : scoville){
        pq.push(i);
    }
    
    while(pq.size() >= 2 && pq.top() < K){
        int first = pq.top();
        pq.pop();
        
        int second = pq.top();
        pq.pop();
        
        int element = first + 2 * second;
        
        pq.push(element); // priority_queue는 자동으로 힙 구조 유지
        answer++;
    }
    
    if(pq.top() < K) return -1;
    
    
    return answer;
}