class Solution {
public:
    bool isPalindrome(string s) {
        auto p1 = s.begin();
        auto p2 = s.end() - 1;

        while (p1 < p2) {

            while (p1 < p2 && !isalnum(*p1))
                ++p1;

            while (p1 < p2 && !isalnum(*p2))
                --p2;

            if (tolower(*p1) != tolower(*p2))
                return false;

            ++p1;
            --p2;
        }

        return true;
    }
};