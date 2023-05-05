//58. 最后一个单词的长度
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int ans = 0;
        bool real = false;
        for(int i = n-1; i >= 0; i--){
            if(s[i] != ' '){
                real = true;
            }
            else if(s[i] == ' ' && real) break;
            if(real && s[i] != ' '){
                ans++;
            }
        }
        return ans;
    }
};