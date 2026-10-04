class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int j=1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(j==nums.size())return true;
            if(nums[i]==nums[j])
            {
                return true;
            }
            j++;
        }
        return false;
    }
};