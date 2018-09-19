class Solution {
    //思路：
    /*
        1排序；
        2、一层循环去重
        3、二层循环去重
        4、双层指针 求和与target对比；
        5、双索引去重；
    */
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>>res;
        const int n=nums.size();
        sort(nums.begin(),nums.end());//1、sort
        for(int i=0;i<n;i++)
        {
            if(i>0&&nums[i]==nums[i-1])//2、一层遍历 去重
                continue;
            for(int j=i+1;j<n;j++)
            {
                if(j>i+1&&nums[j]==nums[j-1])//3、二层遍历去重
                    continue;
                int left=j+1;
                int right=n-1;
                while(left<right)//4、双索引 遍历求和；
                {
                    int sum=nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum==target)
                    {
                        vector<int>temp={nums[i],nums[j],nums[left],nums[right]};
                        res.push_back(temp);
                        while(left<right&&nums[left]==nums[left+1])//5、双索引去重；
                            left++;
                        while(left<right&&nums[right]==nums[right-1])
                            right--;
                        left++,right--;
                    }
                    else if(sum>target)
                        right--;
                    else 
                        left++;
                }
            }
        }
        return res;
    }
};
