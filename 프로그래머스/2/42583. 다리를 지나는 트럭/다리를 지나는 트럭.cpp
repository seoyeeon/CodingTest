#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int current_weight = 0;
    int index = 0;
    
    queue<int> passing;
    
    for(int i = 0; i < bridge_length; i++){
        passing.push(0);
    }
    
    while(index < truck_weights.size()){
        answer++;
        
        current_weight -= passing.front();
        passing.pop();
        
        if(current_weight + truck_weights[index] <= weight){
            passing.push(truck_weights[index]);
            current_weight += truck_weights[index];
            index++;
        }
        else{
            passing.push(0);
        }
    }
    
    //마지막 트럭이 다리에 진입한 후, 다리를 완전히 빠져나가는 데 걸리는 시간을 더해줌
    answer += bridge_length;
    
    
    return answer;
}