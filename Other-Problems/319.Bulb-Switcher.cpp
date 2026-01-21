#include<bits/stdc++.h>
using namespace std;

//Brute force approach:
class Solution {
public:
    int bulbSwitch(int n) {
        vector<bool> bulbs(n + 1, false);

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                bulbs[j] = !bulbs[j];
            }
        }

        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (bulbs[i]) count++;
        }

        return count;
    }
};
//Optimal approach:
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};
//Because only the bulbs at positions of perfect squares remain on after all the toggling rounds.    