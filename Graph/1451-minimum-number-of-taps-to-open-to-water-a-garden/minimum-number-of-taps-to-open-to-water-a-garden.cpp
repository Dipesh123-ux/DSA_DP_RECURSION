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
        vector<int> range(n+1,0);
        for(int i = 0; i < ranges.size();i++){
            int l = max(0,i-ranges[i]);
            int r = min(n,i+ranges[i]);
            range[l] = max(range[l],r);
        }

        int maxEnd = 0;
        int currEnd = 0;
        int t = 0;

        for(int i = 0; i < range.size();i++){
             if(i > maxEnd){
                 return -1;
             }

             if(i > currEnd){
                 t++;
                 currEnd = maxEnd;
             }

             maxEnd = max(maxEnd,range[i]);
        }

        return t;

        // sort(range.begin(),range.end());

        // int res = solve(0,0,range,n);


        // return (res == 1e9 ? -1 : res);

    }
};