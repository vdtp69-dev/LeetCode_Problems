class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int diff=-1;
        int maxi1=INT_MIN,maxi2=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxi1=*max_element(nums.begin(),nums.begin()+i);
            maxi2=*min_element(nums.begin()+i,nums.end());
            if(maxi1-maxi2<=k)
            {
                diff=i;
                break;
            }
        }
        return diff;
    }
};