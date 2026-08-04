#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> deployment_date;
    for(int i = 0; i < progresses.size(); i++){
        int date = (100 - progresses[i]) / speeds[i];
        if((100 - progresses[i]) % speeds[i] != 0){
            date += 1;
        }
        deployment_date.push_back(date); // [7, 3, 9]
        // [5, 10, 1, 1, 20, 1]
    }
    
    vector<int> answer;
    int count = 1;
    int startDate = deployment_date[0];
    
    for(int i = 1; i < deployment_date.size(); i++){
        if(startDate >= deployment_date[i]){
            count++;
        }
        else{
            answer.push_back(count);
            startDate = deployment_date[i];
            count = 1;
        }
    }
    
    answer.push_back(count);
    return answer;
}