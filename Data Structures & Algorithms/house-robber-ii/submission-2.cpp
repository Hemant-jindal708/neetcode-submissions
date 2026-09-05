class Solution {
    int houseRober(vector<int>&nums,int left,int right)
    {
        if(left==right) return nums[left];
        vector<int>dp(right-left+1);
        dp[0]=nums[left];
        dp[1]=max(nums[left+1],nums[left]);
        for(int i=left+2;i<=right;i++)
        {
            dp[i-left]=max(dp[i-left-1],nums[i]+dp[i-left-2]);
        }
        return dp[right-left];
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        else if(n==2) return max(nums[0],nums[1]);
        return max(houseRober(nums,0,n-2),houseRober(nums,1,n-1));
    }
};
