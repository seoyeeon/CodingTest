#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    // 장르 > 재생횟수 > 고유번호 순서
    unordered_map<string, int> total;
    unordered_map<string, vector<pair<int, int>>> songs;//[장르, (재생수, 인덱스)]
    
    for(int i = 0; i < genres.size(); i++){
        total[genres[i]] += plays[i];
        songs[genres[i]].push_back({plays[i], i});
    }
    
    vector<pair<string, int>> genreOrder;
    
    for(const auto& t : total){
        genreOrder.push_back({t.first, t.second});
    }
    
    sort(genreOrder.begin(), genreOrder.end(), [](const auto& a, const auto& b){
        return a.second > b.second;
    });
    
    vector<int> answer;
    
    for(const auto& genre : genreOrder){
        string name = genre.first;
        
        sort(songs[name].begin(), songs[name].end(), [](const auto& a, const auto& b){
            if(a.first == b.first){
                return a.second < b.second;
            }
            return a.first > b.first;
        });
        
        answer.push_back(songs[name][0].second); // 첫번째 pair의 두번째 원소
        
        if(songs[name].size() >= 2){
            answer.push_back(songs[name][1].second);
        }
    }
        
    
    return answer;
}