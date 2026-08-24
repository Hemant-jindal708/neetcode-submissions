class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i:nums)
        {
            if(freq[i]!=0)
            {
                return true;
            }
            else
                freq[i]++;
        }
        return false;
    }
};