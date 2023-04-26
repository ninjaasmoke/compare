const start = performance.now();

const fizzBuzz = (() => {
  const memo = new Map();

  const isDivisibleBy = (n) => (x) => x % n === 0;

  const fizzBuzz = (n) =>
    (isDivisibleBy(3)(n) ? "Fizz" : "") +
    (isDivisibleBy(5)(n) ? "Buzz" : "") ||
    n;

  return (n) => {
    if (memo.has(n)) {
      return memo.get(n);
    }
    const result = fizzBuzz(n);
    memo.set(n, result);
    return result;
  };
})();

const fizzBuzzNumbers = [...Array(100000).keys()].map(x => fizzBuzz(x + 1));

// console.log(JSON.stringify(fizzBuzzNumbers));

const end = performance.now();
console.log(`Execution time: ${end - start} ms`);


// const start = performance.now();

// const fizzBuzz = (() => {
//   const memo = new Map();

//   const isDivisibleBy = (n) => (x) => x % n === 0;

//   const fizzBuzz = (n) =>
//     (isDivisibleBy(3)(n) ? "Fizz" : "") +
//     (isDivisibleBy(5)(n) ? "Buzz" : "") ||
//     n;

//   return (n) => {
//     if (memo.has(n)) {
//       return memo.get(n);
//     }
//     const result = fizzBuzz(n);
//     memo.set(n, result);
//     return result;
//   };
// })();

// const fizzBuzzNumbers = [...Array(100000).keys()].map(x => fizzBuzz(x + 1));

// console.table(fizzBuzzNumbers);

// const end = performance.now();
// console.log(`Execution time: ${end - start} ms`);
