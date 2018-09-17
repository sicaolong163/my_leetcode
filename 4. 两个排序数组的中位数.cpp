class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        const int n1=nums1.size();
        const int n2=nums2.size();
        //n1<n2;
        if(n1>n2)
            return findMedianSortedArrays(nums2,nums1);
        const int k=(n1+n2+1)>>1;//左边的个数k
        int left=0; int right=n1;//从小的那个数组里面找出m1个元素；
        while(left<right)//二分查找；从nums1中找出 应该在m1;
        {
             int m1=(right-left)/2+left;//表示的是前m1个元素；从nums1中取出m1个元素；
             int m2=k-m1;//则从nums2中取出m2中；
            if(nums1[m1]<nums2[m2-1])//nums1[r1]<nums2[l2];nums1的右侧小于nums2的左侧；
                left=m1+1;
            else 
                right=m1;//
        }
        const int m1=left;
        const int m2=k-left;
        //C[k-1]=max(nums1[m1-1],nums2[m2-1]);//中间的四个数里 左边的左边的数  与右边的左边的数取最大的
        //C[k]=min(nums1[m1],nums2[m2]);中间的四个数的去两个的右侧的数的最小的值；
        const int c1=max(m1<=0?INT_MIN:nums1[m1-1],
                        m2<=0?INT_MIN:nums2[m2-1]);
        if((n1+n2)&1==1)//odd
            return c1;
        const int c2=min(m1>=n1?INT_MAX:nums1[m1],
                            m2>=n2?INT_MAX:nums2[m2]);
        return (double)(c1+c2)/2;//even
    }
};
