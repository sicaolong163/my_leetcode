class Solution {
    //思路：
    /*
        1、排序
        2、去重、
        3、双索引求和
        4、比较大小；
    */
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        const int n=nums.size();
        assert(n>=3);
        sort(nums.begin(),nums.end());//1、排序
        int res=nums[0]+nums[1]+nums[n-1];//初始值；
        for(int i=0;i<n;i++)
        {
            if(i>0&&nums[i]==nums[i-1])//2、去重
                continue;
            int left=i+1;
            int right=n-1;
            while(left<right)//3双索引求和
            {
                int sum=nums[i]+nums[left]+nums[right];
                if(sum>target)
                    right--;
                else
                    left++;
                if(abs(sum-target)<abs(res-target))//4比较大小
                    res=sum;
            }
        }
        return res;
        
    }
};
