class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> anagramMap;

        for (const string& s : strs)
        {
            // Compute character frequency count
            vector<int> count(26, 0);
            for (char c : s)
            {
                count[c - 'a']++;
            }

            // Form a string representing the character frequency count for use as a key
            string key = to_string(count[0]);
            for (int i = 1; i < 26; i++)
            {
                key += ',' + to_string(count[i]);
            }

            anagramMap[key].push_back(s);
        }

        // Form result and return
        vector<vector<string>> result;
        for (const std::pair<string, vector<string>>& keyValue : anagramMap)
        {
            result.push_back(keyValue.second);
        }

        return result;
    }
};
