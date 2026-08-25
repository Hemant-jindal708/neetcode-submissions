class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0;
        int right=heights.size()-1;
        int maxWater=0;
        while(left<right)
        {
            int hight=min(heights[left],heights[right]);
            int wid=right-left;
            maxWater=max(maxWater,hight*wid);
            if(heights[left]<heights[right]) left++;
            else right--;
        }
        return maxWater;
    }
};
