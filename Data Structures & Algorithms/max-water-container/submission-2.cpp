class Solution {
public:
    int maxArea(vector<int>& heights) {
        int lp = 0;
        int rp = heights.size() - 1;

        int maxWater = 0;
        while (lp < rp)
        {
            int water = std::min(heights[lp], heights[rp]) * (rp - lp);
            maxWater = std::max(maxWater, water);

            if (heights[lp] < heights[rp])
            {
                lp++;
            }
            else
            {
                rp--;
            }
        }

        return maxWater;
    }
};
