class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> preProduct(n);
        vector<int> postProduct(n);

        preProduct[0] = 1;
        postProduct[n - 1] = 1;

        for (int i = 1; i < n; i++)
        {
            preProduct[i] = nums[i - 1] * preProduct[i - 1];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            postProduct[i] = nums[i + 1] * postProduct[i + 1];
        }

        vector<int> result(n);
        for (int i = 0; i < n; i++)
        {
            result[i] = preProduct[i] * postProduct[i];
        }

        return result;
    }
};
