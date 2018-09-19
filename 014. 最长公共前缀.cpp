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
            while(strs[i].find(res)!=0)//在strs中找res 看看能不能找到 找不到的话  把res减少一个字符；
                res=res.substr(0,res.length()-1);//如果找不到 就减少一位 看看能不能找到；
        }
        return res;
    }
};

//方法二：字典序排序在一个个比较；
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        const int n=strs.size();
        if(n==0)return "";
        sort(strs.begin(),strs.end());//字典序排序；前后的差别肯定是最大的；
        // for(int i=0;i<n;i++)
        //     cout<<strs[i]<<endl;
        string first=strs[0];
        string last=strs[n-1];
        string res;
        int limit=min(first.length(),last.length());
        
        for(int i=0;i<limit;i++)
        {
            if(first[i]==last[i])
                res+=first[i];
            else
                break;
        }
        return res;
    }
};
