/*峰值元素是指其值严格大于左右相邻值的元素。

给你一个整数数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。

你可以假设 nums[-1] = nums[n] = -∞ 。

你必须实现时间复杂度为 O(log n) 的算法来解决此问题。
输入：nums = [1,2,3,1]
输出：2
解释：3 是峰值元素，你的函数应该返回其索引 2。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-peak-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = ((right - left) >> 2) + left;
            if(mid < nums.size() - 1 && nums[mid] < nums[mid+1]){
                left = mid + 1;
            }
            else if(mid > 0 && nums[mid] < nums[mid-1]){
                right = mid - 1;
            }
            else return mid;
        }
        return -1;
    }
};