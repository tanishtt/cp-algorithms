//multiply 1e18 and 1e18


///chech this

#include <bits/stdc++.h>
using namespace std;
long long int M=1e18+1;
long long int russianPeasant(long long int a,long long int b) {
    if (M <= 1000000009) return a * b % M;
 
    long long int res = 0;
    while (a > 0) {
        if (a & 1) {
            res += b;
            if (res >= M) res -= M;
        }
        a >>= 1;
        b <<= 1;
        if (b >= M) b -= M;
    }
    return res;
}
//which works in O(log(min(A,B))) time .


int main() {
   cout << russianPeasant(12455555550000, 270345678950000) << endl;
   cout << russianPeasant(7, 6) << endl;
   return 0;
}