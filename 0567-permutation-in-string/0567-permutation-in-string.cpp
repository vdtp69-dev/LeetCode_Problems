class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        int start=0;
        unordered_map<char,int>s1Freq;
        unordered_map<char,int>s2Freq;
         for (int i = 0; i < n1; i++) {
            s1Freq[s1[i]]++;
        }
        if(n1>n2)return false;
        int req = s1Freq.size();
       for(int i=0;i<n1;i++)
       {
            s2Freq[s2[i]]++;
       }
       if(s1Freq==s2Freq)return true;
       for(int i=n1;i<n2;i++)
       {
            s2Freq[s2[i-n1]]--;
            s2Freq[s2[i]]++;
            if(s2Freq[s2[i-n1]]==0)s2Freq.erase(s2[i-n1]);
            if(s1Freq==s2Freq)return true;
       }
       return false;
    }
};