class Solution {
public:
    int trap(vector<int>& height) {
        int lp = 0;
        int rp = height.size() - 1;

        int waterSum = 0;
        int wallHeight = 0;
        while (lp < rp)
        {
            if(height[lp] > wallHeight && height[rp] > wallHeight)
            {
                wallHeight = std::min(height[lp], height[rp]);
            }

            if (height[lp] <= height[rp])
            {
                waterSum += wallHeight - height[lp];
                lp++;
            }
            else
            {
                waterSum += wallHeight - height[rp];
                rp--;
            }
        }

        return waterSum;
    }
};
