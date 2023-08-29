class Solution {
public:
    int bestClosingTime(string cus) {
        int idx = -1;
        int ans = INT_MAX;

        int cy = 0;
        int cn = 0;

        for(auto i : cus){
            if(i == 'Y'){
                cy++;
            }
        }

       int i;

        for(i = 0; i < cus.size();i++){
            int c = 0;
            
            if(cus[i] == 'N'){
                if(cy + cn < ans){
                    ans = cy + cn;
                    idx = i;
                }
                cn++;
            }
            else{
                   if(cy + cn < ans){
                    ans = cy + cn;
                    idx = i;
                }
                cy--;
            }
             
        }

        if(cy+cn < ans){
            ans = cy + cn;
            idx = i;
        }

        return idx;
    }
};