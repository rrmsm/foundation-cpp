//151. 反转字符串中的单词
class Solution {
public:
//有一种简单的方法就是去除前面的空格，去除中间的，去除后面的。后面那个是优化的。
//不能乱用erase，因为字符串删除是o(n)
    //好的方法是快慢指针，原地做一个完美字符串，用i找到所有非空格，一旦退出了一次while就让slow自动加一个空格。
    //这样字符串后的空格就不用管了
    void remove(string &s){
        int n = s.size();
        int slow = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != ' '){
                if(slow != 0) s[slow++] = ' ';
                while(i < n && s[i] != ' '){
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow);
    }

    void reverse(string &s, int start, int end){
        while(start < end){
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
    string reverseWords(string s) {
        int j = 0;
        remove(s);//先去除杂质
        reverse(s, 0, s.size()-1);//整个逆转一遍
         for(int i = 0; i <= s.size(); i++){//遇到空格单词再转一次
             if(s[i] == ' ' || i == s.size()){
                 reverse(s, j, i-1);
                 j = i + 1;
             }
         }
        return s;
    }
};