//30. 串联所有单词的子串
class Solution {
public:

//用两个哈希表，一个记录words里面的数据，一个记录滑动窗口带来的数据
//substr来一段一段取值
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words[0].size(), m = words.size(), ss = s.size();
        string str;
        unordered_map<string, int> m1;
        unordered_map<string, int> m2;
        vector<int> v;
        if(m == 0 || ss == 0) return v;
        for(string word: words) m1[word]++;

        for(int k = 0; k < n; k++){
            int i = k, j = k;//每一个地方开始都是有可能的
            while(i <= (ss - n*m)){
                while(j < (i + n*m)){
                    str = s.substr(j, n);
                    m2[str]++;
                    j += n;
                    if(m1[str] == 0){
                        i = j;
                        m2.clear();
                        break;
                    }
                    else if(m1[str] < m2[str]){
                        while(m1[str] < m2[str]){
                            m2[s.substr(i, n)]--;//不直接像前面一个这样清空的原因是，有可能是前面几个多出来了
                            i += n;
                        }
                        break;
                    }
                }
                if(j == i + n*m){
                    //因为之前的每一个if进去之后都会导致i往前走，如果长度刚好符合n*m，说明里面的都没有问题。
                    v.emplace_back(i);
                    m2[s.substr(i,n)]--;//滑动窗口
                    i += n;
                }
            }
            m2.clear();//第二个，第三个，第四个。。开始做要清空一下
        } 
        return v;
    }
};