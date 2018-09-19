class Solution {
//思路就是创建一个map 关联式容器，然后进行 从后往前遍历字符串；
public:
    int romanToInt(string s)
    {
        const int n=s.size();
        if(n==0)
            return 0;
        map<char,int>map=
        {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
       int  sum=map[s[n-1]];
        for(int i=n-2;i>=0;i--)
        {
            if(map[s[i]]>=map[s[i+1]])
                sum+=map[s[i]];
            else
                sum-=map[s[i]];
  
        }
        return sum;
        
    }
};
