class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftMost(n, -1);
        vector<int> rightMost(n, n);
        stack<int> heightStack;

        // Build up leftMost
        for (int i = 0; i < n; i++)
        {
            while (!heightStack.empty() && heights[heightStack.top()] >= heights[i])
                heightStack.pop();

            if (!heightStack.empty())
                leftMost[i] = heightStack.top();

            heightStack.push(i);
        }

        // Clear stack
        while (!heightStack.empty())
            heightStack.pop();

        // Build up rightMost
        for (int i = n - 1; i >= 0; i--)
        {
            while (!heightStack.empty() && heights[heightStack.top()] >= heights[i])
                heightStack.pop();

            if (!heightStack.empty())
                rightMost[i] = heightStack.top();
                
            heightStack.push(i);
        }

        // Compute area for each rectangle and keep max
        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            leftMost[i] += 1;
            rightMost[i] -= 1;

            maxArea = max(maxArea, heights[i] * (rightMost[i] - leftMost[i] + 1));
        }

        return maxArea;
    }
};
