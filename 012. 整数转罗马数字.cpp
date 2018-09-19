class Solution {
public:
    string intToRoman(int num) 
    {
       assert(num>=1&&num<=3999);
        int nums[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
       // vector<string >str={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        const int n=sizeof(nums)/sizeof(nums[0]);
        map<int,string>map=
        {
            {1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},{40,"XL"},
            {50,"L"},{90,"XC"}, {100,"C"},{400,"CD"},{500,"D"},{900,"CM"},{1000,"M"}
          
        };
        string res=""; 
      for(int i=n-1;num;i--)//从千位开始往后遍历数组，找出字符串的组合；
        {
            int counts=num/nums[i];
            num=num%nums[i];
            while(counts!=0)
            {
                res+=map[nums[i]];
                counts--;
            }
        }
            
        return res;
    }
};
