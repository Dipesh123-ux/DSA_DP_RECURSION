Array.prototype.last = function() {
   let n = this.length;
   let nums = this;
   return  n > 0 ? nums[n-1] : -1;
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */