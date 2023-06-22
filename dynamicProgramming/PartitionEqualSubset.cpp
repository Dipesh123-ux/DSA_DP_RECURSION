bool canPartition(vector<int> &v, int n)
{
	int s = 0;
	for(auto i : v){
		s += i;
	}
	if(s%2 != 0) return false;
	int k = s/2;
	vector<vector<bool>> dp(n,vector<bool>(k+1,0));
	for(int i = 0; i < n; i++){
		dp[i][0] = true;
	}
	dp[0][v[0]] = true;
	for(int i = 1 ; i < n; i++){
		for(int t = 1; t <= k; t++){
			bool nt = dp[i-1][t];
			bool ta = false;
			if(v[i] <= t){
				ta = dp[i-1][t-v[i]];
			}
			dp[i][t] = nt | ta;
		}
	}

	return dp[n-1][k];
}
