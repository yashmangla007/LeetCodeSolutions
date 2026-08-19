class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        // For each reserved row, store which seats are reserved
        unordered_map<int, int> rows;

        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            rows[row] |= (1 << col);
        }

        // Every completely unreserved row can accommodate 2 families
        int ans = 2 * (n - rows.size());

        // Bit masks for:
        // seats 2,3,4,5
        // seats 4,5,6,7
        // seats 6,7,8,9
        int left  = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int middle = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int right = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        for (auto &[row, mask] : rows) {

            bool b1 = (mask & left) == 0;
            bool b2 = (mask & middle) == 0;
            bool b3 = (mask & right) == 0;

            if (b1 && b3) {
                ans += 2;
            }
            else if (b1 || b2 || b3) {
                ans += 1;
            }
        }

        return ans;

    }
};