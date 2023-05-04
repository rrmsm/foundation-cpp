//238. 除自身以外数组的乘积
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n, 1);
        int left=1, right=1;
        for(int i = 0; i < n; i++){
            v[i] *= left;
            left *= nums[i];//记录当前位置以及左边所有值的乘积。
            //一旦某个值左指针与右指针都已经越过，就说明这个点已经得到了左乘积与右乘积
            v[n-1-i] *= right;
            right *= nums[n-1-i];
        }
        return v;
    }
};