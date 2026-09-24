class Solution {
public:
    double myPow(double x, int n) {
        int count=1;
        long long N=n;
        if(n==1)return x;
        if(n==0)return 1.0;
        if(x==-1 && n%2==1)return -1.0;
        if(x==-1 && n%2==0)return 1.0;
        if(N<0)
        {
            x=1/x;
            N=-N;
        }
        return cal(x,N);
    }
    double cal(double x,long long n)
    {
        if(n==0)
        {
            return 1.0;
        }
       if(n%2==0)
        {
            
            return cal(x*x,n/2);
        }
        else
        {
            return x*cal(x,n-1);
        }
    }
};