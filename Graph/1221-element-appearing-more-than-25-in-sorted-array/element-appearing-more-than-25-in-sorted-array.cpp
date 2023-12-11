class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int c = 0;
        int d = arr[0];
        for(auto i : arr){
            if(i == d){
                c++;
            }
            else{
                int k = 0.25*arr.size();
                if(c > k){
                    return d;
                }
                c = 0;
                d = i;
                c++;
            }
        }

        return d;
    }
};