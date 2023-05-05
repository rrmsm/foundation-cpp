//42. 接雨水

//其实方法就是遍历过去，到了当前的点，找到其左右最高的点（这个最高的点要大于当前点）
//找到了之后找左右最高点中较小的一个高点，拿去与当前点做差值，将差值加入ans中
class Solution {
public:
//我比你高才能接到水，从前向后遍历的时候，找到一个最高点（除最高点外的），若后面没有比其更高的点，就可以接水
//当然这种情况是不能带入至高点的，就是至高点不能参加对比
    int trap(vector<int>& height) {
        int n = height.size();
        int j = 0, highest = height[0];
        for(int i = 0; i < n; i++){
            if(highest < height[i]){
                highest = height[i];
                j = i;
            }
        }
        int higher = height[0];
        int ans = 0;
        for(int i = 0; i < j; i++){
            if(higher < height[i]) higher = height[i];
            else{
                ans += higher - height[i]; 
            }
        }

        higher = height[n-1];
        for(int i = n - 1; i > j; i--){
            if(higher < height[i]) higher = height[i];
            else ans += higher - height[i];
        }

        return ans;
    }
};