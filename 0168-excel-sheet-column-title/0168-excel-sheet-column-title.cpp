class Solution {
public:
    string convertToTitle(int columnNumber) {
        unordered_map<int,char>mpp;
        string s;
        
            while(columnNumber>0)
            {
                columnNumber--;
                int a=columnNumber%26;
                s+='A'+a;
                columnNumber=columnNumber/26;
            }
        reverse(s.begin(),s.end());
        return s;
    }
};