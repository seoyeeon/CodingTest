#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<vector<pair<int, int>>> graph(n+1);
    
    for(auto p : paths){
        int a = p[0];
        int b = p[1];
        int w = p[2];
        
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }
    
    vector<bool> isSummit(n+1, false);
    
    for(int s : summits){
        isSummit[s] = true;
    }
    
    vector<int> dist(n+1, INF);
    
    // intensity, node
    // 우선순위 큐 : 우선순위가 높은 노드를 먼저 내보냄.
    // pq : (비용, 노드번호, 우선순위)
    // greater<> : 큰 값이 뒤로 가게 해주는 비교함수
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // 모든 gate를 시작점으로 둠.(한번에 하기위해)
    for(int g : gates){
        dist[g] = 0;
        pq.push({0, g});
    }
    
    while(!pq.empty()){
        int curIntensity = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(curIntensity > dist[cur]) continue;
        
        // 산봉우리는 종료점
        if(isSummit[cur]) continue;
        
        for(auto& nextInfo : graph[cur]){
            int next = nextInfo.first;
            int weight = nextInfo.second;
            
            // 지금까지 intensity와 현재 간선 중 큰 값
            int nextIntensity = max(curIntensity, weight);
            
            if(nextIntensity < dist[next]){
                dist[next] = nextIntensity;
                pq.push({nextIntensity, next});
            }
        }
    }
    
    sort(summits.begin(), summits.end());
    
    int bestSummit = 0;
    int bestIntegrity = INF;
    
    for(int s : summits){
        if(dist[s] < bestIntegrity){
            bestIntegrity = dist[s];
            bestSummit = s;
        }
    }
    
    return {bestSummit, bestIntegrity};
}