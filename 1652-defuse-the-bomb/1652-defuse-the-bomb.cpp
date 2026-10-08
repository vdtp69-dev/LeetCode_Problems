class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int>ans(n,0);
        if(k==0)
        {
           return ans;
        }
        else if(k>0)
        {
            int sum=0;
            for(int i=1;i<=k;i++)
            {
                sum+=code[i];
            }
            for(int i=0;i<n;i++)
            {
                ans[i]=sum;
                sum-=code[(i+1)%n];
                sum+=code[(i+k+1)%n];
            }
        }
        else
        {
            int sum=0;
             for(int i=n-1;i>=n+k;i--)
            {
                sum+=code[i];
            }
            for(int i=0;i<n;i++)
            {
                ans[i]=sum;
                sum-=code[(n+i+k)%n];
                sum+=code[i];
            }
        }
        return ans;
    }
};