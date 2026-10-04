class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum=0;
        unordered_map<int,int>mpp;
        for(int i=0;i<k;i++)
        {
            sum+=nums[i];
            mpp[nums[i]]++;
        }
        long long maxSum=0;
        if(mpp.size()==k)maxSum=sum;
        for(int i=k;i<n;i++)
        {

            sum-=nums[i-k];
            mpp[nums[i-k]]--;
            if(mpp[nums[i-k]] == 0)
                mpp.erase(nums[i-k]);
            sum+=nums[i];
            mpp[nums[i]]++;
            if(mpp.size()==k)
            maxSum=max(maxSum,sum);
        }
        return maxSum;
    }
};