class Solution {
public:

double power(double a , long long n){
    double ans = 1;

     if(n < 0){
            a = 1/a;
            n = -n;
        }

    while(n > 0){
        int l_b = (n&1);
        if(l_b){
            ans = ans*a;
        }

        a = a*a;
        n = n >> 1;
    }
    
    return ans;
}


    double myPow(double x, int n) {
        long long j = n;
        return power(x,j);
    }
};