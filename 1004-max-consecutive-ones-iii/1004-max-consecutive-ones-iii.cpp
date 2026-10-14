class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0;
        int maxFreq=0;
        int maxLen=0;
        int n=nums.size();
        unordered_map<int,int>mpp;
        mpp[0]=0;
        mpp[1]=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            mpp[1]++;
            else
            mpp[0]++;
            maxFreq=max(maxFreq,mpp[1]);
            while((i-start+1)-maxFreq>k)
            {
                mpp[nums[start]]--;
                start++;
            }
            maxLen=max(maxLen,i-start+1);
        }
        return maxLen;
    }
};