//11. 盛最多水的容器
class Solution {
public:
    int maxArea(vector<int>& height) {
        // int ans = 0;
        // int sum = (height.size()-1)*min(height[0],height[height.size() - 1]);
        // for(int i = 0; i<height.size(); i++){
        //     for(int j = height.size() - 1; j >= 0 ; j--){
        //         if(j > i){
        //             ans = (j-i)*min(height[i],height[j]);
        //             if(sum < ans){
        //                 sum = ans;
        //             }
        //         }
        //     }
        // }
        // return sum;
        int size = height.size();
        int left = 0, right = size - 1;
        int ans = 0;
        while(left < right){
            ans = max(ans, (right - left)*min(height[right],height[left]));
            if(height[right] > height[left]){
                left++;
            }
            else right--;
        }
        return ans;
    }
};