//80. 删除有序数组中的重复项 II
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();
        int i = 2;
        int j = 2;
        while(j < nums.size()){
            // if(nums[i-2] != nums[j]){
            //     nums[i] = nums[j];
            //     i++;
            // }
            // j++;
            if(nums[i] == nums[j]){
                if(nums[i] == nums[i-1] && nums[i] == nums[i-2]){
                    j++;
                }
                else{
                    i++;
                    j++;
                }
            }
            else{
                if(nums[i-1] == nums[j] && nums[i-2] == nums[j]) j++;
                else{
                    nums[i] = nums[j];
                    i++;
                    j++;
                }
            }
        }
        return i;
    }
};