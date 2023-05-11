//36. 有效的数独
class Solution {
public:
//不会做的题目，一种哈希表，一种数组，还有一种最牛，位运算。
//这里写了数组与位运算两种方法
    bool isValidSudoku(vector<vector<char>>& board) {
        //int rows[9][9];
        //int cols[9][9];
        //int area[9][9];//也可以[3][3][9]

        int rows[10];
        int cols[10];
        int area[10];

        memset(rows, 0, sizeof(rows));//这个函数是用来初始化的，很重要！！
        memset(cols, 0, sizeof(cols));//将大的结构体或数组进行全员初始化
        memset(area, 0, sizeof(area));
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    //int c = board[i][j] - '0' - 1;

                    //数字也可以当成索引，因为数字也是唯一的
                    //这里必须减1，因为设定的长度是9，下标只能到8

                    //rows[i][c]++;
                    //cols[j][c]++;
                    //area[(i/3)*3+j/3][c]++;//(i/3)*3+j/3很厉害，分区实在不好想
                    //if(rows[i][c] > 1 || cols[j][c] > 1 || area[(i/3)*3+j/3][c] > 1){
                        //return false;
                    //}

                    int c = board[i][j] - '0';
                    int k = 1 << c, f = (i/3)*3+j/3;//这个代替来二维数组。
                    if(rows[i] & k || cols[j] & k || area[f] & k) return false;
                    //第一个i或者j或者f代表第几行第几列，第几空格，，，，后一个代表是否重复数字
                    rows[i] |= k;
                    cols[j] |= k;
                    area[f] |= k;
                }
            }
        }
        return true;
    }
};