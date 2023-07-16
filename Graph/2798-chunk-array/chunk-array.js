/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function(arr, size) {
     const sub = [];
     for(let i = 0; i < arr.length; i += size){
          sub.push(arr.slice(i,i+size));
     }
     return sub;
};