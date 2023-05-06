//6. N 字形变换
class Solution {
public:
//找规律的，其实很厉害，取整，取余
//这个做法是用空间换时间，可以把原字符串每一行都做一个string，字符串总会这么循环，123212321321321
//所以定义一个flag,来当作循环的行数，一旦到了位置1或者位置3，就调转方向。
    string convert(string s, int numRows) {
        if(numRows == 1 || s.size() < 2) return s;
        vector<string> v(numRows);

        int flag = 0;
        for(int i = 0; i < s.size();){
            while(flag < numRows && i < s.size()){
                v[flag++] += s[i++];
            }
            flag = numRows - 2;
            while(flag >= 0 && i < s.size()){
                v[flag--] += s[i++];
            }
            flag = 1;
        }

        // int flag = -1;
        // int j = 0;
        // for(int i = 0; i < s.size(); i++){
        //     v[j] += s[i];
        //     if(j == 0 || j == numRows - 1) flag = -flag;
        //     j += flag;
        // }
        string str;
        for(int i = 0; i < numRows; i++){
            str += v[i];
        }
        return str; 
    }
};