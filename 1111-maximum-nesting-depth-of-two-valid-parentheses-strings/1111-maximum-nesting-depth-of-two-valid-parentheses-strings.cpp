class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        int n=s.size();
        int count=0;
        int maxi=INT_MIN;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                count++;
                ans.push_back(count%2);
            }
            else if(s[i]==')')
            {
                ans.push_back(count%2);
                count--;
            }
           
        }
        return ans;
    }
};