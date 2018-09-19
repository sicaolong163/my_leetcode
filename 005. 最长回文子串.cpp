class Solution {
public:
    string longestPalindrome(string s) 
    {
        const int n=s.size();
        if(n==0)return "";
        vector<vector<bool>>dp(n,vector<bool>(n,false));//dp[i][j]表示的是i-j是不是回文串；
        dp[0][0]=1;
        string res="";
        for(int i=0;i<n;i++)
        {
            for(int j=i;j>=0;j--)
            {
                // dp[i][j]=true的条件是  1、s[i]==s[j]
                //                        2、ij之间的距离小于等于2，也就是中间最多还有一个字符，或者是 dp[j+1][i-1]已经是回文串；
                
                if((s[i]==s[j])&&(i-j<=2||dp[j+1][i-1]))//dp[i][j]=true的条件是  1、s[i]==s[j]
                    dp[j][i]=true;
                if(dp[j][i]&&(i-j+1)>res.size())
                    res=s.substr(j,i-j+1);
            }
        }
        return res;
    }
};
