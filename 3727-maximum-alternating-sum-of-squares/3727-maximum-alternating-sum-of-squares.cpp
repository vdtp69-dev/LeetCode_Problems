class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0)nums[i]=-nums[i];
        }
        sort(nums.begin(),nums.end());
        int left=0;
        int right=n-1;
        long long sum=0;
        while(left<right)
        {
            sum+=(pow(nums[right],2)-pow(nums[left],2));
            left++;
            right--;
        }
        if(n%2==1)sum+=(pow(nums[n/2],2));
        return sum;
    }
};