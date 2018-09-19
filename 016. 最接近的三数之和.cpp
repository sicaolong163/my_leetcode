class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        const int n=nums.size();
        assert(n>=3);
        sort(nums.begin(),nums.end());
        int res=nums[0]+nums[1]+nums[n-1];//初始值；
        for(int i=0;i<n;i++)
        {
            if(i>0&&nums[i]==nums[i-1])
                continue;
            int left=i+1;
            int right=n-1;
            while(left<right)
            {
                int sum=nums[i]+nums[left]+nums[right];
                if(sum>target)
                    right--;
                else
                    left++;
                if(abs(sum-target)<abs(res-target))
                    res=sum;
            }
        }
        return res;
        
    }
};
