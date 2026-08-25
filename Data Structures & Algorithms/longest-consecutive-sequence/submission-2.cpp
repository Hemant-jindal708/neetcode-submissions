class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int i:nums)
        {
            freq[i]++;
        }
        int longest=0;
        for(auto&[key,val]:freq)
        {
            if(freq.count(key - 1)==0)
            {
                int currentNum = key;
                int currentStreak = 1;
                
                while(freq.count(currentNum + 1) > 0) {
                    currentNum++;
                    currentStreak++;
                }
                
                longest = max(longest, currentStreak);
            }
        }
        return longest;
    }
};
