#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream> // 문자열 쪼개려고 씀

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    
    map<string, int> idIndex; // id -> 인덱스
    map<string, int> reportedCount; // 신고당한 횟수
    map<string, set<string>> reporterList; // key: 신고당한사람,value: 신고한사람리스트
    
    // id별 인덱스 저장
    for(int i = 0; i < id_list.size(); i++){
        idIndex[id_list[i]] = i;
    }
    
     // 신고 기록 처리
    for(string r : report){
        string from, to;
        stringstream ss(r); // 문자열을 공백 기준으로 나눠서 ss에 저장
        ss >> from >> to; // 공백 기준으로 하나씩 꺼내서 저장
        
        // to를 신고한 사람 목록에 from추가
        reporterList[to].insert(from); // -> key : 신고당한사람, value : 신고한사람
    }
    
    // 신고당한 횟수 계산
    for(auto p : reporterList){
        string reportedUser = p.first;
        set<string> reporters = p.second;
        
        reportedCount[reportedUser] = reporters.size();
        
        if(reportedCount[reportedUser] >= k){
            for(string reporter : reporters){
                // 내가 신고한 사람 중에서 정지된 사람 수
                answer[idIndex[reporter]]++;
            }
        }
    }
    
    return answer;
}