//14. 最长公共前缀
class Solution {
public:
//这个思想确实厉害，排序一下这个数组，然后取最大值与最小值进行对比，就一定可以取出最长公共前缀
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        auto s1 = strs.front();
        auto s2 = strs.back();
        int i = 0;
        while(i < s1.size() && i < s2.size() && s1[i] == s2[i]){
            i++;
        }
        return string(s1.begin(), s1.begin() + i);

        // int n = strs.size();
        // int m = strs[0].size();
        // if(n == 1) return strs[0];
        // string str1;
        // for(int i = 0; i < m; i++){
        //     for(int j = 1; j < n; j++){
        //         if(strs[j][i] == strs[j-1][i]){
        //             if(j == n-1) str1 += strs[j][i];
        //             else continue;
        //         }
        //         else return str1;

        //     }
        // }
        // return str1;
    }
};