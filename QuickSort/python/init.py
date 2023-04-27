def quicksort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quicksort(left) + middle + quicksort(right)

if __name__ == '__main__':
    with open('./data.txt', 'r') as f:
        arr = f.readline().strip().split(',')
        arr = [int(x) for x in arr]
    
    sorted_arr = quicksort(arr)
    
    with open('./python/output.txt', 'w') as f:
        f.write(' '.join(str(x) for x in sorted_arr))
