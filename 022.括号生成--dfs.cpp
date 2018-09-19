class Solution {
    //dfs 深度搜索 递归回溯法；
    //注意回溯递归的条件是 
        //左括号个数大于0；
    //          右括号的个数大于左括号的个数；
private:
    vector<string>res;
    void dfs(int left,int right, const string &temp)
    {
        if(left==0&&right==0)
        {
            res.push_back(temp);
            //temp.clear();
            return ;
        }
        if(left>0)//注意两个递归的条件； 左括号的条件是大于0
            dfs(left-1,right,temp+"(");
        if(right>left)//右括号的条件是 大于左括号的个数；
            dfs(left,right-1,temp+")");
        return ;
    }
public:
    vector<string> generateParenthesis(int n) 
    {
        if(n==0)return res;
        dfs(n,n,"");
        return res;
    }
};
