class Solution {
    bool isAlphanumeric(char c)
    {
        if(c>='0'&&c<='9'||c==' ')
        return true;
        else if(tolower(c)>='a'&&tolower(c)>='z')
        return true;
        else return false;
    }
public:
    bool isPalindrome(string s) {
        for(char&c:s)
        {
            c=tolower(c);
            s.erase(remove_if(s.begin(), s.end(), [](char c) {
            return !isalnum(c);
            }), s.end());
        }
        string temp=s;
        reverse(temp.begin(),temp.end());
        return temp==s;
    }
};
