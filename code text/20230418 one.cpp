//88. 合并两个有序数组
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0) return;
        if(m == 0){
            nums1 = nums2;
            return;
        }
        int ans = nums1.size() - 1;
        m--;
        n--;
        while(n >= 0){
            if(m >= 0 && nums1[m] > nums2[n]){
                nums1[ans--] = nums1[m--];
            }
            else{
                nums1[ans--] = nums2[n--];
            }
        }
    }
};