const long long MOD = 1e9+7;
class Solution {

    long long power(int x, long long n){
        if(n==0) return 1;
         long long half = power(x, n / 2);
        half = (half * half) % MOD;

        if (n % 2 == 1)
            half = (half * x) % MOD;

        return half;
    }


public:
    int countGoodNumbers(long long n) {
        long long oddind = n/2, evenind=0;
        
        if(n%2==0) evenind = n/2;
        else evenind = n/2 + 1;

        return (power(4, oddind)*power(5, evenind))%MOD;
    }
};