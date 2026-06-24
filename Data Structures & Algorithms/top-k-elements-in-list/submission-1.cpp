class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> counts;
        std::vector<vector<int>> frequency(nums.size() + 1);

        // Count the frequency of each element in nums
        for (const int& num : nums)
        {
            counts[num]++;
        }

        // Create buckets
        for (const std::pair<int, int> entry : counts)
        {
            frequency[entry.second].push_back(entry.first);
        }

        // Assemble result
        vector<int> result;
        for (int i = frequency.size() - 1; i > 0; --i)
        {
            for (int n : frequency[i])
            {
                result.push_back(n);
                if (result.size() == k)
                {
                    return result;
                }
            }
        }

        return result;
    }
};
