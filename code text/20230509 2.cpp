//125. 验证回文串
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = 0;
        int n =s.size();
        while(j < n){
            if(isupper(s[j])){
                s[j] = tolower(s[j]);
                s[i++] = s[j++];
            }
            else if(islower(s[j]) || isdigit(s[j])) s[i++] = s[j++];
            else j++;
        }
        s.resize(i);
        string s1 = s;
        reverse(s.begin(), s.end());
        if(s1 == s) return true;
        return false;
    }
};