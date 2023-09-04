class Solution {
public:
    int minimumOperations(string num) {
       
       if(num.size() == 1){
           if(num[0] == '0'){
               return 0;
           }
           else{
               return 1;
           }
       }

    //    if(num.size() == 2){
    //        string k = std::string(1, num[0]) + std::string(1, num[1]);
    //        int n = stoi(k);
    //        if(n % 25 == 0){
    //            return 0;
    //        }
    //        else if(num[1] == '0'){
    //            return 1;
    //        }
    //        else{
    //            return 2;
    //        }
    //    }



        int c = 0;
        int ans = INT_MAX;
        int final = INT_MAX;
       for(int i = num.size()-1; i >= 0; i--){
           for(int j = i-1; j >= 0; j--){
                string k = std::string(1, num[j]) + std::string(1, num[i]);
                int n = stoi(k);
               if(n % 25 == 0){
                   int temp = (num.size()-i-1) + i-j-1;
                   final = min(final,temp);
               }
               else if(num[i] == '0'){
                   int temp = (num.size() - 1);
                   final = min(final,temp);
               }
               else{
                   int temp = num.size();
                   final = min(final,temp);
               }
           }
       }
        
       return final;
    }
};