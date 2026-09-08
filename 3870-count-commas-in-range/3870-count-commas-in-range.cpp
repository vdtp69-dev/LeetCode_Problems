class Solution {
public:
    int countCommas(int n) {
        if(n<1000)return 0;
        else
        {
            int ans=1*(n-999);
            return ans;
        }
    }
};