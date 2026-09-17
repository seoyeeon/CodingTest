#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    
    // 가로 >= 세로(w >= h)
    // w * h = b + y
    // y = (w-2)*(h-2)
    
    int w, h;
    for(int i = 1; i <= (brown + yellow)/2; i++){
        if((brown + yellow)%i == 0){
            h = i;
            w = (brown + yellow)/i;
            if(yellow == (w-2) * (h-2)) break;
        }
    }
    
    
    return {w, h};
    
    
}