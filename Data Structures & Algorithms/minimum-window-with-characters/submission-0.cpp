class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>need(128,0);
        vector<int>window(128,0);
        int required=0;
        int formed=0;
        for(char c:t)
        {
            if(need[c]==0) required++;
            need[c]++;
        }
        int left=0;
        int minlength=INT_MAX,startIdx=0;
        for(int right=0;right<s.length();right++)
        {
            char c= s[right];
            window[c]++;
            if(need[c]>0 && window[c]==need[c])
            {
                formed++;
            }
            while(left<=right&&formed==required)
            {
                if(right-left+1<minlength)
                {
                    minlength=right-left+1;
                    startIdx=left;
                }
                char lc=s[left];
                window[lc]--;
                if(need[lc]>0&&window[lc]<need[lc])
                {
                    formed--;
                }
                left++;
            }
        }
        return minlength==INT_MAX? "": s.substr(startIdx,minlength);
    }
};
