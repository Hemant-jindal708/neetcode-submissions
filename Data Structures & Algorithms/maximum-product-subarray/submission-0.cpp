class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        vector<int> max_dp(n);
        vector<int> min_dp(n);
        
        max_dp[0] = nums[0];
        min_dp[0] = nums[0];
        
        int result = nums[0];
        
        for (int i = 1; i < n; i++) {
            int choice1 = nums[i];
            int choice2 = nums[i] * max_dp[i - 1];
            int choice3 = nums[i] * min_dp[i - 1];
            
            max_dp[i] = max({choice1, choice2, choice3});
            min_dp[i] = min({choice1, choice2, choice3});
            
            result = max(result, max_dp[i]);
        }
        
        return result;
    }
};
