#include <bits/stdc++.h>
class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int n = t.size();
        int m = s.size();
        int minLen = INT_MAX;
        unordered_map<char, int> freq_t1;
        unordered_map<char, int> freq_s;
        int match = 0;
        if (n == 0)
            return "";
        int start = 0;
        for (int i = 0; i < n; i++) {
            freq_t1[t[i]]++;
        }
        int req = freq_t1.size();
        for (int right = 0; right < m; right++) {
            freq_s[s[right]]++;
            if (freq_s[s[right]] == freq_t1[s[right]]) {
                match++;
            }
            while (match == req) {
                if (minLen > right - left + 1) {
                    minLen = right - left + 1;
                    start = left;
                }
                if (freq_s[s[left]] == freq_t1[s[left]])
                    match--;
                freq_s[s[left]]--;
                left++;
            }
        }
        if (minLen == INT_MAX)
            return "";
        return s.substr(start, minLen);
    }
};