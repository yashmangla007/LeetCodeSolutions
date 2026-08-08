class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if (m > n) return {};

        vector<int> exact(n + 1, 0), oneOff(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            exact[i] = exact[i + 1];
            if (exact[i] < m && word1[i] == word2[m - 1 - exact[i]]) {
                exact[i]++;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            oneOff[i] = oneOff[i + 1];
            int L = oneOff[i];
            if (L < m) {
                if (word1[i] == word2[m - 1 - L]) {
                    oneOff[i] = L + 1;             
                } 
                else if (exact[i + 1] >= L) {
                    oneOff[i] = L + 1;
                }
            }
        }

        vector<int> result(m, -1);
        bool usedMismatch = false;
        int i = 0;

        for (int k = 0; k < m; k++) {
            int need = m - k - 1;
            bool placed = false;

            while (i < n) {
                if (word1[i] == word2[k]) {
                    int requiredRem = usedMismatch ? exact[i + 1] : oneOff[i + 1];
                    if (requiredRem >= need) {
                        result[k] = i++;
                        placed = true;
                        break;
                    }
                } else if (!usedMismatch && exact[i + 1] >= need) {
                    result[k] = i++;
                    usedMismatch = true;
                    placed = true;
                    break;
                }
                i++;
            }

            if (!placed) return {};
        }

        return result;
    }
};