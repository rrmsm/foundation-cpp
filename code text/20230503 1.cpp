//274. H 指数
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int count = n;
        sort(citations.begin(), citations.end());
        for(int i = 0; i < n; i++){
            if(citations[i] < count) count--;
        }
        return count;
    }
};