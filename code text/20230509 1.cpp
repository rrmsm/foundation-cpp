//68. 文本左右对齐
class Solution {
public:

    string blank(int n){
        return string(n, ' ');
    }
//给一个左指针，给一个右指针，返回单词加需要的空格。
    string join(vector<string>& words, int left, int right, string seq){
        string s = words[left];
        for(int i = left + 1; i < right; i++){
            s += seq + words[i];
        }

        return s;
    }


    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        int right = 0;
        vector<string> v;
        while(true){
            int left = right;
            int ans = 0;
            while(right < n && ans + words[right].size() + right - left <= maxWidth){
                ans += words[right++].size();
            }

            if(right == n){
                string s = join(words, left, right, " ");//必须要这样，要保持一个空格
                v.emplace_back(s + blank(maxWidth - s.size()));
                return v;
            }

            int numwords = right - left;
            int numspace = maxWidth - ans;

            if(numwords == 1){
                v.emplace_back(words[left] + blank(numspace));
                continue;
            }

            int quyu = numspace % (numwords-1);
            int chu = numspace / (numwords-1);
            string s1 = join(words, left, left + quyu + 1, blank(chu+1));
            string s2 = join(words, left + quyu + 1, right, blank(chu));
            v.emplace_back(s1 + blank(chu) + s2);
        }
        // int ans = 0, j = 0;
        // int n = words.size();
        // vector<string> v;
        // string str;
        // for(int i = 0; i < n; i++){
        //     if(ans + words[i].size() <= maxWidth){
        //         str += words[i];
        //         ans += words[i].size() + 1;
        //         j += 1;
        //         if(i == n - 1){//最后一行
        //             str.clear();
        //             for(int m = i - j + 1; m <= i; m++){
        //                 str += words[m];
        //                 str += ' ';
        //             }
        //             int sheng = maxWidth - str.size();
        //             str += blank(sheng);
        //             v.push_back(str);
        //             str.clear();
        //         }
        //     }
        //     else{
        //         int count = maxWidth - str.size();
        //         if(j == 1) str += blank(count);//一行只有一个词
        //         else{
        //             int num1 = count % (j-1);//1
        //             int num2 = count / (j-1);//3
                    
        //             str.clear();
        //             for(int m = i - j; m < i - 1; m++){
        //                 //str += words[m];
        //                 if(num1 != 0){
        //                     while(num1-- && m < i - 1){
        //                         str += words[m];
        //                         str += blank(num2+1);
        //                         m++;
        //                     }                            
        //                 }
        //                 j = j - num1 - 1;
        //                 while(j-- && m < i - 1){
        //                     str += words[m];
        //                     str += blank(num2);
        //                     m++;
        //                 }
        //             }
        //             str += words[i-1];                    
        //         }

        //         v.push_back(str);
        //         str.clear();
        //         ans = 0;
        //         j = 0;
        //         i--;
        //     }
        // }
        // return v;
    }
};