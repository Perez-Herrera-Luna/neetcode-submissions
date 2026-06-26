class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_map<int, std::unordered_set<char>> rows, cols;
        std::map<pair<int, int>, std::unordered_set<char>> squares;

        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] == '.')
                    continue;

                // Use integer division to determin sub-box 
                std::pair<int, int> squareKey = {row / 3, col / 3};

                // Check if char exists in sets
                if (rows[row].count(board[row][col]) ||
                    cols[col].count(board[row][col]) ||
                    squares[squareKey].count(board[row][col]))
                {
                    return false;
                }

                rows[row].insert(board[row][col]);
                cols[col].insert(board[row][col]);
                squares[squareKey].insert(board[row][col]);
            }
        }

        return true;
    }
};
