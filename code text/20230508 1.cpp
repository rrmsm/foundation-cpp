//28. 找出字符串中第一个匹配项的下标

//KMP看了好久，累了
class Solution {
public:
    int strStr(string haystack, string needle) {
        //haystack.find(needle);
        int i = 0, j = 0, m = 0;
        int n = haystack.size(), s = needle.size();
        if(n < s) return -1;
        while(i < n){
            if(haystack[i] == needle[j]){
                if(s == 1) return i;
                m = i+1;
                j += 1;
                while(j < s && m < n){
                    if(haystack[m] == needle[j]){
                        m += 1;
                        j += 1;
                    }
                    else{
                        i += 1;
                        j = 0;
                        break;
                    }
                }
                if(j == s) return i;
            }
            else{
                i++;
            }
        }
        return -1;
    }
};