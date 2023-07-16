/**
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */

var flat = function (arr, n) {
    if(n == 0){
       return arr;
    }

    let ans=[];
    
    for(let i = 0; i < arr.length;i++){
        if(n > 0 && typeof arr[i] == 'object'){
           ans.push(...flat(arr[i],n-1));
        }
        else{
            ans.push(arr[i])
        }
    }

    return ans;
    
};