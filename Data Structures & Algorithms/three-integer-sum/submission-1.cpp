class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i++)
        {
            int a = nums[i];

            if (a > 0)
                break;
            if (i > 0 && a == nums[i - 1])
                continue;

            int lp = i + 1;
            int rp = nums.size() - 1;
            while(lp < rp)
            {
                int threeSum = a + nums[lp] + nums[rp];

                if (threeSum > 0)
                    rp--;
                else if (threeSum < 0)
                    lp++;
                else
                {
                    result.push_back({a, nums[lp], nums[rp]});
                    lp++;
                    rp--;
                    while(lp < rp && nums[lp] == nums[lp - 1])
                    {
                        lp++;
                    }
                }
            }
        }

        return result;
    }
};
