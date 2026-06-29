class Solution {
public:
    bool isPalindrome(string s) {
        int lp = 0;
        int rp = s.length() - 1;

        while (lp < rp)
        {
            if (!isalnum(s[lp]))
            {
                lp++;
                continue;
            }

            if (!isalnum(s[rp]))
            {
                rp--;
                continue;
            }

            if (tolower(s[lp]) != tolower(s[rp]))
            {
                return false;
            }

            lp++;
            rp--;
        }

        return true;
    }
};
