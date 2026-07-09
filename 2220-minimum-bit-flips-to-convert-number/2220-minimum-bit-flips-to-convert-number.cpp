class Solution {
public:
    int minBitFlips(int start, int goal) {
        int target = start^goal;
        int count = 0;
        while(target>0){
            target = target&(target-1);
            count++;
        }
        return count;
    }
};