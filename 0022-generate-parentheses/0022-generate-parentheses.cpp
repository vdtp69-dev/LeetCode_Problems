class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>s;
        int count=0;
        string a;
        gen(n,s,count,0,0,a);
        return s;
    }
    void gen(int n,vector<string>&s,int count,int open,int close,string a)
    {
        if(count==2*n)
        {
            s.push_back(a);
            return;
        }
        if(open<n)gen(n,s,count+1,open+1,close,a+'(');
        if(close<open)gen(n,s,count+1,open,close+1,a+')');
    }
};