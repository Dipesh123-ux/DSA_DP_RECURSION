/**
 * @param {Function} fn
 * @return {Array}
 */
Array.prototype.groupBy = function(fn) {
    let mymap = {};
    for(let i = 0; i < this.length;i++){
        let key = fn(this[i]);
        if(key in mymap){
            mymap[key].push(this[i]);
        }
        else{
            mymap[key] = [this[i]];
        }

    }
    return mymap;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */