class Solution {
    int maxCrossingSum(vector<int>& nums, int left, int mid, int right) {
        int leftSum = INT_MIN;
        int currentSum = 0;
        for (int i = mid; i >= left; i--) {
            currentSum += nums[i];
            leftSum = max(leftSum, currentSum);
        }
        int rightSum = INT_MIN;
        currentSum = 0;
        for (int i = mid + 1; i <= right; i++) {
            currentSum += nums[i];
            rightSum = max(rightSum, currentSum);
        }
        return leftSum + rightSum;
    }

    int helper(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];
        int mid = left + (right - left) / 2;
        int leftMax = helper(nums, left, mid);
        int rightMax = helper(nums, mid + 1, right);
        int crossMax = maxCrossingSum(nums, left, mid, right);
        return max({leftMax, rightMax, crossMax});
    }

public:
    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};
