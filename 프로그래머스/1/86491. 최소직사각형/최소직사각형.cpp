#include <string>
#include <vector>
#include <climits>

using namespace std;

int solution(vector<vector<int>> sizes) {
    
    int maxElement = 0;
    int nextC = 0;
    int w = -1;
    
    
    for(int i = 0; i < sizes.size(); i++){
        for(int j = 0; j < 2; j++){
            if(maxElement < sizes[i][j]){
                maxElement = sizes[i][j];
                w = i;
                if(j == 0) nextC = sizes[i][1];
                else nextC = sizes[i][0];
            }
        }
    }
    
    int nextMaxElement = nextC;
    
    for(int i = 0; i < sizes.size(); i++){
        if(i == w) continue;
        if(sizes[i][0] > nextMaxElement && sizes[i][1] > nextMaxElement){
            nextMaxElement = min(sizes[i][0], sizes[i][1]);
        }
        
    }
    
    return maxElement * nextMaxElement;
    
    
}