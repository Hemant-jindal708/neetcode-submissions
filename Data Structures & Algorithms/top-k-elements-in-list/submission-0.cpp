class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int i : nums) {
            freq[i]++;
        }
        
        vector<pair<int,int>> vec(freq.begin(), freq.end());
        sort(vec.begin(), vec.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.second < b.second; 
        });
        
        vector<int> ans;
        for(int i = vec.size() - 1; i >= (int)vec.size() - k; i--) {
            ans.push_back(vec[i].first);
        }
        
        return ans;
    }
};