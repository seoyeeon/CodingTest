import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        Map<String, Integer> m = new HashMap<>();
        for(String k : participant){
            m.put(k, m.getOrDefault(k, 0) + 1);
        }
        
        for(String k : completion){
            m.put(k, m.get(k) - 1);
        }
        
        for(String k : m.keySet()){
            if(m.get(k) != 0){
                return k;
            }
        }
        
        return "";
    }
}