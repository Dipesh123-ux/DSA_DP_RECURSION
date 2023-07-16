/**
 * @param {Function} fn
 */
function memoize(fn) {  

    var cache = {};

 
    return function(...args) {
        let keys = String(args);

        if(keys in cache) return cache[keys];

        return cache[keys] = fn(...args);

    }
    
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */