/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let start = init;
    return {
        increment : ()=>{
            return init += 1;
        },

        decrement : ()=>{
            return init -= 1;
        },

        reset : ()=>{
            init = start;
            return init;
        }


    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */