/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let newArray = [];

    arr.forEach((ele,i)=>{
        newArray.push(fn(ele,i));
    })

    return newArray;
};