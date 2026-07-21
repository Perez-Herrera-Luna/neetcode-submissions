class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        // Pair position and speed and then sort on position and then reverse
        vector<pair<int, int>> positionSpeed(n);

        for (int i = 0; i < n; i++)
        {
            positionSpeed[i] = {position[i], speed[i]};
        }

        sort(positionSpeed.rbegin(), positionSpeed.rend());

        std::stack<double> fleets;

        for (pair<int, int>& ps : positionSpeed)
        {
            double finishTime = (double)(target - ps.first) / ps.second;
            if (fleets.empty() || finishTime > fleets.top())
            {
                fleets.push(finishTime);
            }
        }

        return fleets.size();

        // n = len(position)

        // position_speed = []
        // for i in range(n):
        //     position_speed.append((position[i], speed[i]))
        
        // position_speed.sort()
        // position_speed.reverse()
        
        // stack = []
        // for i in range(n):
        //     destination_time = (target - position_speed[i][0]) / position_speed[i][1]

        //     if not stack or destination_time > stack[-1]:
        //         stack.append(destination_time)

        // return len(stack)
    }
};
