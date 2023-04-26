//45. 跳跃游戏 II
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int curdistance = 0;
        int nextdistance = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            nextdistance = max(nums[i] + i, nextdistance);
            if(i == curdistance){
                if(curdistance != nums.size() - 1){
                    count++;
                    curdistance = nextdistance;
                    if(nextdistance >= nums.size() - 1) break;
                }
                else break;
            }
        }
        return count;
    }
};