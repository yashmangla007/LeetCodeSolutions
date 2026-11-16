class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {

            string ans = "";
            int n = s.size();

            int st = 0;

            while (st < n) {
                int sum = 0;
                int cur = st;

                while (cur < n && cur < st + k) {
                    sum += s[cur] - '0';
                    cur++;
                }

                ans += to_string(sum);
                st = cur;
            }

            s = ans;
        }

        return s;
    }
};