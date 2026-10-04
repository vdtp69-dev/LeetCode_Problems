class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int left=0;
        int right=0;
        int star=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                left++;
                right++;
            }
            else if(s[i]==')')
            {
                left--;
                right--;
            }
            else
            {
                left--;
                right++;
            }
            left = max(0, left);
        if(right<0)
            return 0;
        }
        if(left<=0)
        {
            return 1;
        }
        return 0;
    }
};