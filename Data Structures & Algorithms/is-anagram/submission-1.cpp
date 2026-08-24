class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        vector<int> sf(26,0);
        vector<int> tf(26,0);
        for(char c:s) sf[c-'a']++;
        for(char c:t) tf[c-'a']++;
        for(int i=0;i<26;i++) if(sf[i]!=tf[i]) return false;
        return true;
    }
};
