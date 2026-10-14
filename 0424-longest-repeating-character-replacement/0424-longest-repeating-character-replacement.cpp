class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int start = 0;
        unordered_map<char, int> mpp;
        int maxFreq = 0;
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            mpp[s[i]]++;
            maxFreq = max(maxFreq, mpp[s[i]]);
            while (((i - start + 1) - (maxFreq)) > k) {
                mpp[s[start]]--;
                start++;
            }
            maxLen = max(maxLen, (i - start + 1));
        }
        return maxLen;
    }
};