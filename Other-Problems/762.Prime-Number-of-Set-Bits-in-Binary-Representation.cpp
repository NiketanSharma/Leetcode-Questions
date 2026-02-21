// Approach:
// You iterate through every number from left to right. 
// For each number, you calculate the number of set bits (1s in its binary representation) using __builtin_popcount(i). 
// Then you check whether this count of set bits is a prime number using the helper function isPrime(). 
// If it is prime, you increment the counter. Finally, you return the total count.
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int countPrimeSetBits(int left, int right) {
        int count=0;
        for(int i=left;i<=right;i++){
            int setBits=__builtin_popcount(i);
            if(isPrime(setBits))count++;
        }
        return count;
    }
private:
    bool isPrime(int n){
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};