class Solution {
    //思路  就是一个入栈出栈的过程；
    /*
        思路 ：栈 ；当时左括号的时候入栈  右括号的时候看看是否和栈顶匹配；
            匹配的话 栈顶出栈
            否则就是不匹配 直接返回false；
    */
public:
    bool isValid(string s)
    {
        const int n=s.size();
        if(n==0)return true;
        stack<char >stack;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
                stack.push(s[i]);
            else
            {
                if(stack.size()==0)
                    return  false;
                char match;
                if(s[i]==')')
                    match='(';
                else if(s[i]==']')
                    match='[';
                else 
                    match='{';
                if(stack.top()!=match)
                    return false;
                stack.pop();
            }
        }
     
        if(stack.size()!=0)
            return false;
        return true;
    }
};
