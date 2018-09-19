class Solution {
    /*
        思路 就是 1、排序去重；
                    2、找两个数的和；
                    3、双索引；（也包括去重）
    */
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>>res;
        const int n=nums.size();
        if(n<=2)return res;
        
        sort(nums.begin(),nums.end());//排序
        for(int i=0;i<n;i++)
        {
            if(i>0&&nums[i]==nums[i-1])//去重
                continue;
            int left=i+1;
            int right=n-1;
            int target=0-nums[i];
            while(left<right)//双索引
            {
                int sum=nums[left]+nums[right];
                if(sum==target)
                {
                    vector<int>temp={nums[i],nums[left],nums[right]};
                    res.push_back(temp);
                    temp.clear();
                    while(left<right&&nums[left]==nums[left+1])//去重
                        left++;
                    while(left<right&&nums[right]==nums[right-1])
                        right--;
                    left++;
                    right--;
                }
               else if(sum>target)right--;
                else left++;
            }
        }
        return res;
    }
};
