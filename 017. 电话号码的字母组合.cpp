class Solution {
    //dfs 排列组合的问题；
private:
    const string map[10]={
        " ",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    vector<string>res;
    void dfs(const string &digits,int index, string &temp)//不明白这里为什么用const  修饰temp 
    {
        if(index==digits.size())
        {
            res.push_back(temp);
            return ;
        }
        char c=digits[index];
        assert(isdigit(c)&&c!='1');
        string letters=map[c-'0'];
        for(int i=0;i<letters.size();i++)
        {
            temp.push_back(letters[i]);
            dfs(digits,index+1,temp);//上面temp如果用const修饰的话 这里需要改成 temp+letter[i];
            temp.pop_back();
        }
        return ;
    }
public:
    vector<string> letterCombinations(string digits) 
    {
       
        const int n=digits.size();
        if(n==0) return res;
        string temp="";
        dfs(digits,0,temp);
            return res;
    }
};
