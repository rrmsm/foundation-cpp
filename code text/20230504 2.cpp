//134. 加油站
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //int n = gas.size();
        int ans = 0;
        int count = 0;
        int i = 0;
        for(int j = 0; j < gas.size(); j++){
            count += gas[j] - cost[j];
            if(count < 0){
                ans += count;
                count = 0;
                i = j + 1;
            }
        }
        if(count + ans >= 0) return i;
        return -1;
    }
};