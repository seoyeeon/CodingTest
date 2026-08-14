#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    
    for(int i = 0; i < priorities.size(); i++){
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }
    
    int count = 0;
    
    while(!q.empty()){
        int index = q.front().first;
        int priority = q.front().second;
        q.pop();
        
        if(priority == pq.top()){
            pq.pop();
            count++;
            
            if(index == location){
                return count;
            }
        }
        else{
            q.push({index, priority});
        }
        
    }
    
    return 0;
    
}