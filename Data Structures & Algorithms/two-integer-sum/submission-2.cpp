class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> complementMap;

        for (int i = 0; i < nums.size(); i++)
        {
            if (complementMap[nums[i]] != 0)
            {
                std::vector<int> result = {complementMap[nums[i]] - 1, i};
                return result;
            }

            complementMap[target-nums[i]] = i + 1;
        }
    }
};
