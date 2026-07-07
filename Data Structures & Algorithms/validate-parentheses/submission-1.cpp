class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;

        std::unordered_map<char, char> parenthesesMap = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            if (parenthesesMap.count(c))
            {
                if (!stack.empty() && stack.top() == parenthesesMap[c])
                {
                    stack.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                stack.push(c);
            }
        }

        return stack.empty();
    }
};
