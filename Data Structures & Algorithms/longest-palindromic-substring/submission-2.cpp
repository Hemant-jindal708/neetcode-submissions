class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int n = s.length();
        int start = 0;
        int max_len = 1;
        vector<bool> dp(n, false);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= i; j--) {
                dp[j] = (s[i] == s[j]) && (j - i < 3 || dp[j - 1]);
                
                if (dp[j] && (j - i + 1 > max_len)) {
                    max_len = j - i + 1;
                    start = i;
                }
            }
        }
        
        return s.substr(start, max_len);
    }
};