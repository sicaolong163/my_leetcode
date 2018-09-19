class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int n=s.size();
        int left=0;
        int right=-1;//滑动窗口  [left,right];
        int freq[256]={0};//用来表示记录重复字符串的字典；
        int res=0;
        
        while(left<n)
        {
            if(right+1<n&&freq[s[right+1]]==0)
                freq[s[++right]]++;
            else 
                freq[s[left++]]--;//一直循环直到 去除重复 的那个点；
            res=max(res,right-left+1);
        }
        return res;
    }
};
