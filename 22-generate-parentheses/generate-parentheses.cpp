class Solution {
public:
    vector<string> result;

    void backtrack(int n, int open, int close, string& current) {
        // Đã đủ 2*n ký tự
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Có thể thêm '(' nếu chưa dùng hết n cái
        if (open < n) {
            current.push_back('(');

            backtrack(n, open + 1, close, current);

            current.pop_back();
        }

        // Chỉ thêm ')' nếu số ')' chưa vượt số '('
        if (close < open) {
            current.push_back(')');

            backtrack(n, open, close + 1, current);

            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string current = "";

        backtrack(n, 0, 0, current);

        return result;
    }
};