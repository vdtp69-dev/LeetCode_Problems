class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n1=img1.size();
        vector<vector<int>>a;
        vector<vector<int>>b;
        map<pair<int,int>,int>freq;
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n1;j++)
            {
                if(img1[i][j]==1)
                {
                    a.push_back({i,j});
                }
            }
        }
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n1;j++)
            {
                if(img2[i][j]==1)
                {
                    b.push_back({i,j});
                }
            }
        }
        for(auto i:a)
        {
            for(auto j:b)
            {
                freq[{i[0]-j[0],i[1]-j[1]}]++;
            }
        }
        if(freq.empty())return 0;
        auto maxFreq = max_element(
        freq.begin(), 
        freq.end(),
        [](const auto& pair1, const auto& pair2) {
            return pair1.second < pair2.second; 
        }
        );
        return maxFreq->second;
        
    }
};