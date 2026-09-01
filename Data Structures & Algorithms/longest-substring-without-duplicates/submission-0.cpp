class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> seen(256, false); 
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); right++) {
            while (seen[s[right]]) {
                seen[s[left]] = false;
                left++;
            }
            
            seen[s[right]] = true;
            
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};