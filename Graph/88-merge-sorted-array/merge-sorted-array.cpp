class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = max(nums1.size(),nums2.size());
        int arr[k];

        int i = 0, j = 0;

        int s = 0;

        while(i < m && j < n){
            if(nums1[i] < nums2[j]){
                arr[s] = nums1[i];
                i++;
            }
            else{
                arr[s] = nums2[j];
                j++;
            }
           s++;
        }

        while(i < m){
            arr[s] = nums1[i];
            i++;
            s++;
        }

        while(j < n){
        arr[s] = nums2[j];
        j++;
        s++;
        }


        for(int i = 0; i < k; i++){
            nums1[i] = arr[i];
        }



 
        
    }
};