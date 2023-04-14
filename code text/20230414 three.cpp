/*给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。

注意：如果对空文本输入退格字符，文本继续为空。

输入：s = "ab#c", t = "ad#c"
输出：true
解释：s 和 t 都会变成 "ac"。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/backspace-string-compare
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int> s1;
        stack<int> s2;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '#' && !s1.empty()) s1.pop();
            else if(s[i] != '#') s1.push(s[i]);
        }
        for(int m = 0; m < t.size(); m++){
            if(t[m] == '#' && !s2.empty()) s2.pop();
            else if(t[m] != '#') s2.push(t[m]);
        }
        if(s1.size() != s2.size()) return false;
        while(!s1.empty() || !s2.empty()){
            char j = s1.top();
            char k = s2.top();
            if(j != k) return false;
            s1.pop();
            s2.pop();
        }
        return true;
    }
};