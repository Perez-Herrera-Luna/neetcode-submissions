class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // Pair position and speed
        vector<pair<int, int>> positionSpeed(position.size());
        for (int i = 0; i < position.size(); i++)
        {
            positionSpeed[i] = {position[i], speed[i]};
        }

        // Sort on position in reverse
        // By default, sort() will sort on the first value of a pair. Ties are broken with the second value
        sort(positionSpeed.rbegin(), positionSpeed.rend());

        std::stack<double> fleets;
        for (pair<int, int>& ps : positionSpeed)
        {
            // Calculate finish time
            double finishTime = (double)(target - ps.first) / ps.second;

            // If the time we calculated is greater than the existing time, push it onto the stack
            // Cars with a smaller finish time will catch up to the fleet ahead of them
            if (fleets.empty() || finishTime > fleets.top())
            {
                fleets.push(finishTime);
            }
        }

        // The number of elements is number of unique fleets
        return fleets.size();
    }
};
