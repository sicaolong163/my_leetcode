/*
给定一个 32 位有符号整数，将整数中的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。根据这个假设，如果反转后的整数溢出，则返回 0。*/
class Solution {
public:
    int reverse(int x)
    {
        if(x==0)return x;
        // if(x>INT_MAX||x<INT_MIN)
        //     return 0;
        int sign;
        if(x<0)
        {
            sign=-1;
            x=-x;
        }
        else sign=1;
        while(x%10==0)
        {
            x=x/10;
        }
        long long  res=0;//数字可能越界。整型溢出；
        while(x)
        {
            res=res*10+x%10;
            x/=10;
        }
        res*=sign;
        if(res>INT_MAX||res<INT_MIN)//所以这里需要判断
            return 0;
        return res;
    }
};
