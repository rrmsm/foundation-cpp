/*给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
*/
class Solution {
public:

    int findright(vector<int>& nums, int target){
        int right = -2;
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high){
            int mid = low + ((high - low)/2);
            if(nums[mid] <= target){
                low = mid + 1;
                right = low;                            
            }
            else{
                high = mid - 1;
            }
        }
        return right;
    }
    int findleft(vector<int>& nums, int target){
        int left = -2;
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high){
            int mid = low + ((high - low)/2);
            if(nums[mid] >= target){
                high = mid - 1;
                left = high;                            
            }
            else{
                low = mid + 1;
            }
        }
        return left;
    }
     vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1, -1};
        int left = findleft(nums, target);
        int right = findright(nums, target);
        if(left == -2 || right == -2) return {-1, -1};
        if(right - left > 1) return {left+1, right-1};
        return {-1, -1};
     }
};