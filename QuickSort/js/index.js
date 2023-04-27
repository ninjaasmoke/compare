const fs = require('fs');

const inputPath = 'data.txt';
const outputPath = './output/javascript.txt';

const inputString = fs.readFileSync(inputPath, 'utf8');

const numbers = inputString
    .split(',')
    .map(numString => parseInt(numString.trim(), 10));

quicksort(numbers);

const outputString = numbers.join(' ');

fs.writeFileSync(outputPath, outputString);

function quicksort(arr, left = 0, right = arr.length - 1) {
    if (left >= right) {
        return;
    }

    let pivot = arr[left];
    let i = left;
    let j = right;

    for (let k = left + 1; k <= j;) {
        if (arr[k] < pivot) {
            [arr[k], arr[i]] = [arr[i], arr[k]];
            i++;
            k++;
        } else if (arr[k] > pivot) {
            [arr[k], arr[j]] = [arr[j], arr[k]];
            j--;
        } else {
            k++;
        }
    }

    quicksort(arr, left, i - 1);
    quicksort(arr, j + 1, right);
}
