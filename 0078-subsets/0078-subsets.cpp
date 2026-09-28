class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int>a;
        vector<vector<int>>ans;
        int count=0;
        gen(n,nums,count,a,ans);
        return ans;
    }
    void gen(int n,vector<int>& nums,int count,vector<int>& a,vector<vector<int>>& ans)
    {
        if(count==n)
        {
            ans.push_back(a);
            return;
        }
        a.push_back(nums[count]);
        gen(n,nums,count+1,a,ans);
        a.erase(a.end()-1);
        gen(n,nums,count+1,a,ans);
    }
};