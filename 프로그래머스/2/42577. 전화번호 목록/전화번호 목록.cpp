#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> s;
    
    for(const string& a : phone_book){
        s.insert(a);
    }
    
    for(const auto& number : s){
        for(int i = 1; i < number.size(); i++){
            string prefix = number.substr(0, i);
            
            if(s.find(prefix) != s.end()){
                return false;
            }
        }
    }
    
    
    return true;
    
    
}