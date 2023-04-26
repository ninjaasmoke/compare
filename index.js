const fizzBuzz = (() => {
    const memo = [];

    const cacheIsDivisibleBy = (() => {
        const cache = new Map();
        return (n) => {
            if (cache.has(n)) {
                return cache.get(n);
            }
            const result = (x) => x % n === 0;
            cache.set(n, result);
            return result;
        };
    })();

    const isDivisibleBy3 = cacheIsDivisibleBy(3);
    const isDivisibleBy5 = cacheIsDivisibleBy(5);

    const fizzBuzz = (n) =>
        (isDivisibleBy3(n) ? "Fizz" : "") +
        (isDivisibleBy5(n) ? "Buzz" : "") ||
        n;

    for (let i = 1; i <= 10000000; i++) {
        memo.push(fizzBuzz(i));
    }

    return (n) => memo[n - 1];
})();

function run() {
    [...Array(10000000).keys()].map((x) => console.log(fizzBuzz(x + 1)));
}

run();
