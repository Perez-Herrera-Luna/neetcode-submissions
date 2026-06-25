class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for (const string& str : strs)
        {
            int n = str.length();
            result += (to_string(n) + "," + str);
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        string stringLength = "";

        while (i < s.length())
        {
            if (s[i] == ',')
            {
                int stringSize = stoi(stringLength);
                result.push_back(s.substr(i + 1, stringSize));
                stringLength = "";
                i += (stringSize + 1);
            }

            stringLength += s[i];
            i++;
        }

        return result;
    }
};
