const fs = require('fs');

function quicksort(numbers) {
  if (numbers.length <= 1) {
    return numbers;
  }

  const pivotIndex = Math.floor(numbers.length / 2);
  const pivot = numbers[pivotIndex];
  const left = [];
  const right = [];

  for (let i = 0; i < numbers.length; i++) {
    if (i === pivotIndex) {
      continue;
    }

    if (numbers[i] < pivot) {
      left.push(numbers[i]);
    } else {
      right.push(numbers[i]);
    }
  }

  return [...quicksort(left), pivot, ...quicksort(right)];
}

const inputPath = 'data.txt';
const outputPath = './output/js.txt';
const inputBuffer = fs.readFileSync(inputPath);
const inputString = inputBuffer.toString('utf8');
const numbers = inputString
  .trim()
  .split(',')
  .map(str => parseInt(str, 10));
const sortedNumbers = quicksort(numbers);
const outputString = sortedNumbers.join(' ');
fs.writeFileSync(outputPath, outputString, 'utf8');
