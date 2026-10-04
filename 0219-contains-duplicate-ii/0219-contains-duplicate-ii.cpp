class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        if(n==1 || k==0)return false;
        for(int i=0;i<min(k,n);i++)
        {
            mpp[nums[i]]++;
        }
        for(auto it:mpp)
        {
            if(it.second>=2)return true;
        }
        for(int i=k;i<n;i++)
        {
            mpp[nums[i]]++;
            if(mpp[nums[i]]>=2)return true;
            mpp[nums[i-k]]--;
        }
        return false;
    }
};