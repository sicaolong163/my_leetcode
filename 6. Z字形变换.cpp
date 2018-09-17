/*将字符串 "PAYPALISHIRING" 以Z字形排列成给定的行数：

P   A   H   N
A P L S I I G
Y   I   R
之后从左往右，逐行读取字符："PAHNAPLSIIGYIR"

实现一个将字符串进行指定行数变换的函数:

string convert(string s, int numRows);
示例 1:

输入: s = "PAYPALISHIRING", numRows = 3
输出: "PAHNAPLSIIGYIR"
示例 2:

输入: s = "PAYPALISHIRING", numRows = 4
输出: "PINALSIGYAHRPI"
解释:

P     I    N
A   L S  I G
Y A   H R
P     I
*/
class Solution {
public:
    string convert(string s, int numRows) 
    {
        const int n=s.size();
        if(numRows<=1)
            return s;
        vector<string>res(numRows);
        int row=0,step=1;
        for(int i=0;i<n;i++)
        {
            res[row].push_back(s[i]);
            if(row==numRows-1)step=-1;//当到达到最后一行的时候开始倒着排序 行数--；
            if(row==0)step=1;//当到达第一行的时候 下一次开始正着排；行数增加；
            row+=step;//下一行；
        }
        string result;
        for(auto c:res)
            result+=c;
        return result;
    }
};
