class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string res;
        const int n=strs.size();
        if(n==0)
            return res;
        res=strs[0];
        for(int i=1;i<n;i++)
        {
            while(strs[i].find(res)!=0)//在strs[i]中找res；返回的开始索引；
                res=res.substr(0,res.length()-1);
        }
        return res;
    }
};
