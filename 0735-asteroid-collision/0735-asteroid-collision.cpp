class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;

        for (int i = 0; i < asteroids.size(); i++) {
            bool destroyed = false;

            while (!st.empty() &&
                   st.top() > 0 &&
                   asteroids[i] < 0) {

                if (st.top() < -asteroids[i]) {
                    st.pop();                      // Stack asteroid destroyed
                }
                else if (st.top() == -asteroids[i]) {
                    st.pop();                      // Both destroyed
                    destroyed = true;
                    break;
                }
                else {
                    destroyed = true;             // Current asteroid destroyed
                    break;
                }
            }

            if (!destroyed) {
                st.push(asteroids[i]);
            }
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};