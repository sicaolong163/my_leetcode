class Solution {
    //思路：双索引技术；更新索引；
public:
    int maxArea(vector<int>& height) 
    {
        const int n=height.size();
        assert(n>=2);
        int left=0;
        int right=n-1;
        int maxV=0;
        while(left<right)
        {
            maxV=max(maxV,min(height[left],height[right])*(right-left));
            if(height[left]<height[right])
                left++;
            else
                right--;
            
        }
        return maxV;
    }
};
