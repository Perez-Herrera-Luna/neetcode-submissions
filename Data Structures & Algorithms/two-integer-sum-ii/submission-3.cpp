class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lp = 0;
        int rp = numbers.size() - 1;

        while (lp < rp)
        {
            int sum = numbers.at(lp) + numbers.at(rp);
            if (sum == target)
            {
                vector<int> result = {lp + 1, rp + 1};
                return result;
            }

            if (sum > target)
            {
                rp--;
                continue;
            }

            if (sum < target)
            {
                lp++;
                continue;
            }
        }

        return {};
    }
};
