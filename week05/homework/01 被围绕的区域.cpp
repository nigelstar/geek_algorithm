
// 题解链接：https://leetcode.cn/problems/surrounded-regions/solutions/1966029/by-nigel-4-lhwj/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        range_y_ = board.size();
        range_x_ = board.front().size();  // 保证board.length >= 0
        // 访问第一行和最后一行
        array<int, 2> row_index{0, range_y_ - 1};
        for (int y : row_index) {
            for (int x = 0; x < range_x_; ++x) {
                if (board[y][x] == 'O') {
                    dfs(board, y, x);
                }
            }
        }

        // 访问第一列和最后一列
        array<int, 2> col_index{0, range_x_ - 1};
        for (int x : col_index) {
            for (int y = 0; y < range_y_; ++y) {
                if (board[y][x] == 'O') {
                    dfs(board, y, x);
                }
            }
        }

        // 对board进行遍历循环，如果节点为O，则将其修改为X，如果节点为Y，则将其修改为O
        for (int y = 0; y < range_y_; ++y) {
            for (int x = 0; x < range_x_; ++x) {
                if (board[y][x] == 'O') {
                    board[y][x] = 'X';
                } else if (board[y][x] == 'Y') {
                    board[y][x] = 'O';
                }
            }
        }
    }

private:
    void dfs(vector<vector<char>>& board, int y, int x) {
        board[y][x] = 'Y';
        for (int i = 0; i < DIRECTION_NUM; ++i) {
            int next_y = y + AXIS_Y[i];
            if ((next_y < 0) || (next_y >= range_y_)) {
                continue;
            }
            int next_x = x + AXIS_X[i];
            if ((next_x < 0) || (next_x >= range_x_)) {
                continue;
            }
            if (board[next_y][next_x] == 'O') {
                dfs(board, next_y, next_x);
            }
        }
    }

    int range_y_;
    int range_x_;

    static constexpr int DIRECTION_NUM = 4;
    static constexpr array<int, DIRECTION_NUM> AXIS_X = {0, 1, 0, -1};
    static constexpr array<int, DIRECTION_NUM> AXIS_Y = {1, 0, -1, 0};
};

