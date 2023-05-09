//167. 两数之和 II - 输入有序数组
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        while(i < j){
            int sum = numbers[i] + numbers[j];
            if(sum > target){
                j--;
            }
            else if(sum < target){
                i++;
            }
            else{
                return {i+1,j+1};
            }
        }
        return {-1,-1};
        // for(int i = 0; i <= numbers.size() - 1; i++){
        //     int z = i;
        //     int j = numbers.size() - 1;
        //     int goal = target - numbers[i];
        //     while(i <= j){
        //         int mid = i + (j - i) / 2;
        //         if(numbers[mid] == goal){
        //             return {z+1,mid+1};
        //         }
        //         else if(numbers[mid] > goal){
        //             j = mid - 1;
        //         }
        //         else if(numbers[mid] < goal){
        //             i = mid + 1;
        //         }
        //     }
        // }
        // return {z+1,mid+1};
    }
};