class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> s;

        // Build set
        for(const int& num: nums)
        {
            s.insert(num);
        }

        // Search set for longest run
        int longestRun = 0;
        for(const int& num: nums)
        {
            if (s.count(num - 1))
            {
                continue;
            }

            int j = 1;
            while(s.count(num + j))
            {
                j += 1;
            }

            longestRun = std::max(longestRun, j);
        }

        return longestRun;
    }
};
