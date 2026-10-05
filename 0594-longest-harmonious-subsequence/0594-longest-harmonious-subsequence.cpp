class Solution {
public:
    int findLHS(vector<int>& nums) {
        int left=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxi=0;
        for(int right=1;right<n;right++)
        {
            while(left<n && nums[right]-nums[left]>1)
            {
                left++;
            }
            if(nums[right]-nums[left]==1)
                maxi=max(maxi,right-left+1);
        }
        return maxi;
    }
};