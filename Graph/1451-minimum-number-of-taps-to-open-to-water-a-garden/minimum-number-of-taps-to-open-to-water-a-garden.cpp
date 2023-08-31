class Solution {

map<pair<int,int>,int> m;

int solve(int i,int maxEnd,vector<pair<int,int>>&range,int n){
    if(i >= range.size()){
        if(maxEnd >= n){
            return 0;
        }
        else{
            return 1e9;
        }
    }

    if(range[i].first > maxEnd){
        return 1e9;
    }

    if(m.find({i,maxEnd}) != m.end()){
        return m[{i,maxEnd}];
    }


    int p =1 + solve(i+1,max(maxEnd,range[i].second),range,n);
    int np = solve(i+1,maxEnd,range,n);

    return m[{i,maxEnd}] = min(p,np);

}

public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>> range(n+1);
        for(int i = 0; i < ranges.size();i++){
            int l = max(0,i-ranges[i]);
            int r = min(n,i+ranges[i]);
            range.push_back({l,r});
        }

        sort(range.begin(),range.end());

        int res = solve(0,0,range,n);


        return (res == 1e9 ? -1 : res);

    }
};