class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        std::stack<std::pair<int, int>> temperatureStack; // {temp, index}

        for (int i = 0; i < temperatures.size(); i++)
        {
            int temp = temperatures[i];

            while (!temperatureStack.empty() && temp > temperatureStack.top().first)
            {
                std::pair<int, int> tempPair = temperatureStack.top();
                temperatureStack.pop();
                result[tempPair.second] = i - tempPair.second;
            }
            temperatureStack.push({temp, i});
        }

        return result;
    }
};
