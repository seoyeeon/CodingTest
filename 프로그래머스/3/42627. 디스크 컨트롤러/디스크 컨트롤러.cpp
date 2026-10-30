#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 1. 처음에 대기큐 비어있음
// 2. 우선순위 높은거 꺼냄.
// 소요시간 짧 > 요청시각 빠른것 > 작업번호 작은것
// 3. 비선점

struct Queue{
    int num;
    int arrive;
    int run;
};

struct Compare{
    bool operator()(const Queue &a, const Queue &b) const{
        if(a.run != b.run) return a.run > b.run;
        if(a.arrive != b.arrive) return a.arrive > b.arrive;
        return a.num > b.num;
    }
};

int solution(vector<vector<int>> jobs) {
    vector<Queue> v;
    
    for(int i = 0; i < jobs.size(); i++){
        v.push_back({i, jobs[i][0], jobs[i][1]});
    }
    
    sort(v.begin(), v.end(), [](const Queue &a, const Queue &b){
        if(a.arrive == b.arrive) return a.num < b.num;
        else return a.arrive < b.arrive;
    });
    
    priority_queue<Queue, vector<Queue>, Compare> pq;
    
    int current_time = 0;
    int index = 0;
    int completed = 0;
    int total = 0;
    
    while(completed < jobs.size()){
        // 1. 현재 시간까지 요청된 작업 추가
        while(index < v.size() && v[index].arrive <= current_time){
            pq.push(v[index]);
            index++;
        }
        
        // 2. 대기 중인 작업이 있으면 실행
        if(!pq.empty()){
            Queue job = pq.top();
            pq.pop();
            
            current_time += job.run;
            
            total += current_time - job.arrive;
            
            completed++;
        }
        // 3. 대기 중인 작업이 없으면 다음 요청시각으로 이동
        else{
            current_time = v[index].arrive;
        }
        
    }
    
    
    return total / jobs.size();
}