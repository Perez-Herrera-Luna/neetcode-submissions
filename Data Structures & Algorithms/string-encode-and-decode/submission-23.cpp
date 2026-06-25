class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";

        // Encode each string as string_size + "," + original_string
        for (const string& str : strs)
        {
            int n = str.length();
            result += (to_string(n) + "," + str);
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;

        // Extract string sizes and pull out the appropriate substring.
        int i = 0;
        string stringLength = "";
        while (i < s.length())
        {
            if (s[i] == ',')
            {
                int stringLengthInt = stoi(stringLength);
                result.push_back(s.substr(i + 1, stringLengthInt));
                stringLength = "";
                i += (stringLengthInt + 1);
            }

            stringLength += s[i];
            i++;
        }

        return result;
    }
};
