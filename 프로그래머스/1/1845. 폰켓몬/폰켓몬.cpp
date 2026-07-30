#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{ 
    unordered_map<int, int> count;
    
    for(int n : nums){
        count[n]++;
    }
    
    if(nums.size()/2 < count.size()){
        return nums.size() / 2;
    }
    else return count.size();
}