class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> complementMap;

        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];

            if (complementMap.count(complement))
            {
                return {complementMap[complement], i};
            }

            complementMap.insert({nums[i], i});
        }

        return {};
    }
};
