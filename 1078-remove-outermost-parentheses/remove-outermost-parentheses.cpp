class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int d = 0;
        for (char c : s) {
            if (c == '(') {
                if (d++) res += c;
            } else {
                if (--d) res += c;
            }
        }
        return res;
    }
};
