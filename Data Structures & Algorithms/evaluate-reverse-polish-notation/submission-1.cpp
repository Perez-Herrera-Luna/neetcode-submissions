class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> operands;
        std::set<string> operators = {"+", "-", "*", "/"};

        for (string token : tokens)
        {
            // If token is an operator
            if (operators.count(token))
            {
                // Pop off last two operands
                int operand2 = operands.top();
                operands.pop();
                int operand1 = operands.top();
                operands.pop();

                string op = token;

                // Perform operation and push result to stack
                if (op == "+")
                    operands.push(operand1 + operand2);
                else if (op == "-")
                    operands.push(operand1 - operand2);
                else if (op == "*")
                    operands.push(operand1 * operand2);
                else if (op == "/")
                    operands.push(operand1 / operand2);
            }
            else // If token is an operand
                operands.push(std::stoi(token));
        }

        return operands.top();
    }
};
