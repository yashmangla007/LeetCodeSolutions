class Solution {
public:

    int digitSum(int n){
        int ans =0;;
        while(n!=0){
            ans += n%10;
            n/=10;
        }
        return ans;
    }
    int digitProd(int n){
        int ans =1;;
        while(n!=0){
            ans = ans*(n%10);
            n/=10;
        }
        return ans;
    }

    bool checkDivisibility(int n) {
        int sum = digitSum(n)+digitProd(n);
        if( n%sum==0) {
            return true;
        }

        else return false;
    }
};