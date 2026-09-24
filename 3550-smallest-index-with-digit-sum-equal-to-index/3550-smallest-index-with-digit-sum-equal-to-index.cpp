class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=10)
            {
                int rem;
                int t=nums[i];
                int sum=0;
                while(t>0)
                {
                    rem=t%10;
                    sum+=rem;
                    t/=10;
                }
                nums[i]=sum;
            }
            if(nums[i]==i)
            {
                return i;
            }
        }
        return -1;
    }
};