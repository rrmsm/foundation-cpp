//209. 长度最小的子数组
class Solution {
public:
//直接想了滑动窗口，可以
//两个指针，当找到满足的ans之后，让ans减掉left，让left++，滑动窗口
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), temp = target;
        int ans = 0;
        int left = 0, right = 0;
        while(right <= n){
            if(ans < target){
                if(left == 0 && right == n) return 0;
                if(right == n) return temp;
                ans += nums[right++];
            }
            else{
                temp = min(right - left, temp);
                if(temp == 1) return 1;
                ans -= nums[left];
                left++;
            }
        }
        return temp;
    }
};