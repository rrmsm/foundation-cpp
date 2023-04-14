/*给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> summ;
        int n = nums.size();
        if(n < 3) return summ;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(nums[i] > 0) return summ;
            if(i > 0 && nums[i] == nums[i-1]) continue;//用-1不用+1，真的爱了
            int L = i + 1, R = n - 1;
            while(L < R){
                if(nums[i]+nums[L]+nums[R] == 0){
                    summ.push_back({nums[i],nums[L],nums[R]});
                    while(L<R && nums[L] == nums[L+1])  L += 1;
                    while(L<R && nums[R] == nums[R-1])  R -= 1;
                    L += 1;//再走一步，上面只是走到了最后一个一样的而已
                    R -= 1;
                }
                else if(nums[i]+nums[L]+nums[R] > 0) R -= 1;
                else L += 1;
            }
        }
        return summ;
    }
};