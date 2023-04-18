//169. 多数元素
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret = nums[0];
        int count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != ret){
                count--;
                if(count == 0){
                    count = 1;
                    ret = nums[i];
                }
            }
            else count++;
        }
        return ret;
    }
};