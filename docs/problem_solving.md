## Function: insertAt

### Problem Understanding
- Input:  arr[] — the array, *size — current element count,
          index — position to insert at, value — element to insert
- Output: returns 0 on success, -1 on error; modifies arr[] and *size
- Edge cases: index out of bounds, array full (size >= MAX_1D)

### Algorithm
1. Check that index is within [0, *size] and size < MAX_1D
2. Shift all elements from position index rightward by one slot
3. Place value at arr[index] and increment *size

## Function: deleteAt

### problem understanding
- Input:  arr[] — the array, *size — current element count,
          index — position to delete at
- Output: returns 0 on success, -1 on error; modifies arr[] and *size
- Edge cases: index out of bounds, array full (size >= MAX_1D)

### Algorithm
1. Check that index is within [0, *size] and size < MAX_1D
2. Shift all elements from after position index left by one slot
3. Overwrites any previous data at position index
