class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> preProduct;
        vector<int> postProduct;

        preProduct.push_back(1);
        postProduct.push_back(1);

        for (int i = 0; i < nums.size(); i++)
        {
            preProduct.push_back(nums[i] * preProduct[i]);
        }

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            postProduct.insert(postProduct.begin(), nums[i] * postProduct[0]);
        }

        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            result.push_back(preProduct[i] * postProduct[i + 1]);
        }

        return result;
    }
};
