//55. 跳跃游戏
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        if(nums[0] == 0) return false;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                for(int j = i; j >= 0; j--){
                    if(j + nums[j] > i) break;
                    if(i == n - 1){
                        if(j + nums[j] >= i){
                            return true;
                        }                        
                    }
                    else if(j == 0 && i != n - 1){
                        if(j + nums[j] <= i){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};