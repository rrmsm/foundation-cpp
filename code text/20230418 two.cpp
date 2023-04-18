//27. 移除元素
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // int n = nums.size();
        // for(int i = 0; i < nums.size(); i++){
        //     if(nums[i] == val){
        //         nums.erase(nums.begin()+i);
        //         i--;
        //     }
        // }
        // return nums.size();
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[j++] = nums[i];
            }
        }
        return j;
        // 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
    }
};