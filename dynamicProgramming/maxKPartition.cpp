// Problem Name: Max Sum K-Partition
// Problem Difficulty: 2
// Problem Constraints: 1 ≤ N ≤ 2∗10^6 

// 1 ≤ K ≤ N 

// −10^9 ≤ Ai ≤ 10^9
// Problem Description:
// Agarwal has a habit of creating Ajeeb Samasya as usual and Shubham always comes to his rescue. 
// This is time he has created another samasya which is as follows. Read carefully! 
// Shubham has an array of N integers and an integer K. He wants to create a subsequence of this
//  array with some conditions applied. He builds ceil(N/K) blocks of this array with size of e
//  ach block as [i∗K+1,min((i+1)∗k,N)] for 0≤i≤N/K. For two consecutive integers in this subsequence, 
//  he wants the integers to be of two different blocks. (It is not a compulsion to have one integer from each block).
//   Also, lets say the indexes of any two integers of this subsequence be i and j, then he wants |i−j| != K. 
//   Shubham takes the sum of integers in the subsequence. He wonders what can be the maximum sum obtained? 
//   Help shubham in this samasya.

// Input Format: First line contains two space separated integers : N and K 
// Second line contains N space separated integers : A1, A2,…, AN
// Sample Input: 6 5
// 5 4 3 2 1 -1
// Output Format: print a single integer describing maximum sum that can be obtained.
// Sample Output: 5



// =====Solution=====
// c++

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long> a(n);
    for(auto &i : a)
        cin >> i;
    long maxSum = 0;
    vector<long> dp = a;
    for(int i = k; i < n; i += k) {
        int max_i = i - k, smax_i = -1;
        for(int j = i - k + 1; j < i; j++) {
            if(dp[j] > dp[max_i]) {
                smax_i = max_i;
                max_i = j;
            }
            else if(smax_i == -1 or dp[j] > dp[smax_i]) {
                smax_i = j;
            }
        }
        for(int j = i; j < i + k and j < n; j++) {
			if(a[j] < 0) dp[j] = dp[max_i];
            else if(j - max_i != k) dp[j] = a[j] + dp[max_i];
            else dp[j] = a[j] + dp[smax_i];
            maxSum = max(maxSum, dp[j]);
        }
    }
    cout << maxSum;
}