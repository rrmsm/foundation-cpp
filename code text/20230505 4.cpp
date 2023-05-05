//12. 整数转罗马数字
class Solution {
public:
    string intToRoman(int num) {
        // unordered_map<string, int> map;
        // map.emplace("I",1); 
        // map.emplace("V",5);
        // map.emplace("X",10);
        // map.emplace("L",50);
        // map.emplace("C",100);
        // map.emplace("D",500);
        // map.emplace("M",1000);
        int a[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string b[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        string str;
        for(int i = 0; i < 13;i++){
            while(num >= a[i]){
                num -= a[i];
                str += b[i];
            }
        }
        return str;
    }
};