class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int leftMax=0,rightMax=0;
        int i=0;
        if(n==0)return 0;
        int j=n-1;
        int ans=0;
        while(i<j)
        {
            if(height[i] <= height[j])
            {
                leftMax=max(leftMax,height[i]);
                ans+=leftMax-height[i];
                i++;
            }
            else
            {
                
                rightMax=max(rightMax,height[j]);
                ans+=rightMax-height[j];
                j--;
            }
        }
        return ans;
    }
};