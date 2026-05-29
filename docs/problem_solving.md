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

## function: linearSearch

### problem understanding
- Input:  arr[] — the array, size — current element count,
          value — element to search for
- output: returns index on success, -1 when not found;

### ALgorithm
1. loops through all elements of the array until it finds an element that
   matches the wanted value
2. when found, the loop returns the index of the matching value
3. when not found, function returns an error code (-1)

## Function: binarySearch

### Problem Understanding
- Input: `arr[]` (sorted), `size` — number of elements, `value` — target to find
- Output: index of `value` if found; `-1` if not found
- Edge cases: empty array, duplicates (returns any matching index)

### Algorithm
1. Maintain `left` and `right` indexes; compute `mid` = floor((left+right)/2)
2. If `arr[mid]` equals `value` return `mid`; otherwise shrink the search interval
3. Repeat until `left > right`, then return `-1`

## Function: bubbleSort

### Problem Understanding
- Input: `arr[]`, `size`
- Output: sorts `arr[]` in ascending order in-place; returns 0
- Edge cases: `size <= 1` (no-op)

### Algorithm
1. Repeatedly scan array swapping adjacent out-of-order elements
2. Continue passes until a full pass performs no swaps

## Function: selectionSort

### Problem Understanding
- Input: `arr[]`, `size`, `minpos` (working index)
- Output: sorts `arr[]` in-place

### Algorithm
1. For each position `i` from 0 to `size-2` find the minimum in `i..size-1`
2. Swap the minimum into position `i`

## Function: insertionSort

### Problem Understanding
- Input: `arr[]`, `size`
- Output: sorts `arr[]` in-place

### Algorithm
1. Build a sorted prefix by inserting each element into its correct spot by shifting

## Function: mergeSort

### Problem Understanding
- Input: `arr[]`, `left`, `right`
- Output: sorts `arr[left..right]` in-place

### Algorithm
1. Recursively split the range into halves until single-element ranges
2. Merge adjacent sorted halves using temporary buffers

## Function: quickSort

### Problem Understanding
- Input: `arr[]`, `low`, `high`
- Output: sorts `arr[low..high]` in-place

### Algorithm
1. Partition the range around a pivot (Lomuto partition) and recursively sort subranges

## Function: sumArray

### Problem Understanding
- Input: `arr[]`, `size`
- Output: integer sum of all elements (0 for empty)

### Algorithm
1. Iterate elements accumulating into `sum` and return it

## Function: findMax

### Problem Understanding
- Input: `arr[]`, `size`
- Output: maximum element (returns 0 if `size <= 0`)

### Algorithm
1. Initialize `max = arr[0]` then scan to update `max`

## Function: findMin

### Problem Understanding
- Input: `arr[]`, `size`
- Output: minimum element (returns 0 if `size <= 0`)

### Algorithm
1. Initialize `min = arr[0]` then scan to update `min`

## Function: averageArray

### Problem Understanding
- Input: `numbers[]`, `size`
- Output: `double` average (0.0 if `size == 0`)

### Algorithm
1. Sum elements and divide by `size`, returning a `double`

## Function: reverseArray

### Problem Understanding
- Input: `numbers[]`, `size`
- Output: array reversed in-place

### Algorithm
1. Swap elements `numbers[i]` and `numbers[size-1-i]` for `i` from 0 to `size/2 - 1`

## Function: rotateLeft

### Problem Understanding
- Input: `arr[]`, `size`, `k` — number of left rotations
- Output: `arr[]` rotated left by `k` positions (in-place)

### Algorithm
1. Reduce `k` modulo `size`; perform `k` left-shift operations (simple O(k*size) method)

## Function: mergeSortedArrays

### Problem Understanding
- Input: sorted `a[]` (na), sorted `b[]` (nb), output `out[]`
- Output: `out[]` filled with merged sorted elements

### Algorithm
1. Use two pointers `i` and `j` to merge the two arrays into `out[]`

## Function: initMatrix

### Problem Understanding
- Input: `matrix[MAX_ROWS][MAX_COLS]`, pointers `rows`, `cols`
- Output: reads dimensions and values from stdin into `matrix`; updates `rows` and `cols`

### Algorithm
1. Prompt for `rows` and `cols`, validate ranges, then read `rows*cols` integers

## Function: printMatrix

### Problem Understanding
- Input: `matrix`, `rows`, `cols`
- Output: prints matrix rows to stdout

### Algorithm
1. Iterate rows and columns printing elements with separators

## Function: transposeMatrix

### Problem Understanding
- Input: `matrix[rows][cols]`, `rows`, `cols`, `transposed[][]`
- Output: fills `transposed` with the transpose of `matrix`

### Algorithm
1. For each `i,j` set `transposed[j][i] = matrix[i][j]`

## Function: addMatrices

### Problem Understanding
- Input: `matrix1`, `matrix2`, `result`, `rows`, `cols`
- Output: element-wise sum stored in `result`

### Algorithm
1. For each cell `(i,j)` compute `result[i][j] = matrix1[i][j] + matrix2[i][j]`

## Function: multiplyMatrices

### Problem Understanding
- Input: square matrices `MatA`, `MatB`, `result`, dimension `n`
- Output: `result` = `MatA * MatB`

### Algorithm
1. Standard triple-loop multiplication accumulating `result[i][j]`

## Function: isSymmetric

### Problem Understanding
- Input: `matrix`, `rows`, `cols`
- Output: `1` if matrix is symmetric and square, else `0`

### Algorithm
1. If `rows != cols` return 0; else compare `matrix[i][j]` and `matrix[j][i]` for upper triangle

## Function: sortRows

### Problem Understanding
- Input: `matrix`, `rows`, `cols`
- Output: each row sorted ascending in-place

### Algorithm
1. For each row run a simple row-level bubble sort

## Function: sumDiagonal_antiDiagonal

### Problem Understanding
- Input: square matrix `m[][n]`, `n`
- Output: prints and returns sum of main diagonal and anti-diagonal; avoids double-counting center

### Algorithm
1. Sum `m[i][i]` and `m[i][n-1-i]` for `i` in `0..n-1`; subtract middle if `n` odd

## Function: merge (static)

### Problem Understanding
- Input: `arr[]`, `left`, `mid`, `right`
- Output: merges two sorted subarrays `arr[left..mid]` and `arr[mid+1..right]`

### Algorithm
1. Allocate temporary `L` and `R` buffers, copy ranges, then merge back into `arr`

## Function: partition (static)

### Problem Understanding
- Input: `arr[]`, `low`, `high`
- Output: rearranges range and returns pivot final index (Lomuto scheme)

### Algorithm
1. Use `arr[high]` as pivot, move smaller elements to left and place pivot at correct position

## File utilities (file_utils.c)

### Function: writeRecord
- Input: `filename`, `Record* r`
- Output: appends `r` to file; returns 0 on success or -1 on error

### Algorithm
1. Open file in `ab`, `fwrite` record, close file

### Function: createBinaryFile
- Input: `filename`
- Output: creates/truncates binary file; 0 on success

### Function: readRecord
- Input: `filename`, `index`, `Record* r`
- Output: reads record at position `index` into `r`; returns 0 on success

### Algorithm
1. Open `rb`, `fseek` to `index * sizeof(Record)`, `fread` into `r`, close

### Function: countRecords
- Input: `filename`
- Output: number of `Record`s in file or -1 on error

### Algorithm
1. `fseek` to end, use `ftell` divided by `sizeof(Record)`

### Function: appendRecord
- Input/Output: same as `writeRecord` (explicit return handling)

### Function: searchRecordById
- Input: `filename`, `id`, `Record* result`
- Output: index of first matching record or -1 if not found

### Algorithm
1. Scan file sequentially with `fread`, compare `temp.id` to `id`

### Function: updateRecord
- Input: `filename`, `index`, `Record newData`
- Output: overwrites record at `index`; returns 0 on success

### Algorithm
1. Open `r+b`, `fseek` to position, `fwrite` new data, close file

### Function: copyBinaryFile
- Input: `src`, `dest`
- Output: copies all records from `src` to `dest`; returns 0 on success

### Algorithm
1. Open `src`/`dest`, loop `fread` then `fwrite` until EOF

## Singly linked list functions (linked_lists.c)

### Function: initArrayList
- Input: pointer to `ArrayList`
- Output: sets `head=NULL`, `size=0`

### Function: insertAtHead / insertAtTail / insertAtIndex
- Input: `ArrayList*`, index/value as appropriate
- Output: insert node (returns 0 success, -1 on allocation/invalid index)

### Algorithm
1. Allocate a `Node`, link into list head/tail or traverse to index then insert

### Function: deleteAtHead / deleteAtTail
- Input: `ArrayList*`
- Output: removes node, returns its value or -1 on error

### Algorithm
1. Adjust `head`/`tail` pointers (by traversal for tail) and `free` removed node

### Function: displayList
- Input: `ArrayList*`
- Output: prints node values and size

### Function: reverseList
- Input: `ArrayList*`
- Output: reverses list in-place by pointer rewiring

### Algorithm
1. Iterate, reversing `next` pointers, update `head` to new first node

### Function: sortListBubble
- Input: `ArrayList*`
- Output: sorts list by swapping node `data` fields

### Algorithm
1. Repeatedly sweep until no swaps, comparing adjacent `data`

### Function: mergeSortedLists
- Input: two sorted `ArrayList*` and `result` list
- Output: `result` contains merged elements (by repeated `insertAtTail`)

### Algorithm
1. Two-pointer traversal of lists, append smaller element until exhausted

## Doubly linked list functions (linked_lists.c)

### Function: initListDLL
- Input: `DLL*`
- Output: sets `head=tail=NULL`, `size=0`

### Function: insertAtHeadDLL / insertAtTailDLL / insertAtIndexDLL
- Input: `DLL*`, index/value as appropriate
- Output: insert node (returns 1 success, 0 on allocation/invalid index)

### Algorithm
1. Allocate `DNode`, set `prev`/`next` and fix neighbor pointers accordingly

### Function: deleteAtHeadDLL / deleteAtTailDLL / deleteAtIndexDLL
- Input: `DLL*`, index when required
- Output: removes node and returns value or -1 on error

### Algorithm
1. Fix neighbors' `prev`/`next`, update `head`/`tail`, `free` node

### Function: dllDisplayForward / dllDisplayBackward
- Input: `DLL*`
- Output: prints nodes in forward or reverse order

### Algorithm
1. Iterate from `head` (forward) or `tail` (backward) printing `data`

## String utilities (string_utils.c)

### Function: myStrLen
- Input: `const char* str`
- Output: integer length (excluding terminating null)

### Algorithm
1. Iterate until `\0` counting characters

### Function: myStrCpy / myStrNCpy
- Input: `dest`, `src` (and `n` for `myStrNCpy`)
- Output: copies string, returns number of copied characters

### Algorithm
1. Copy characters and null-terminate; stop at `n` or `\0` for `myStrNCpy`

### Function: myStrCat
- Input: `dest`, `src`
- Output: appends `src` to `dest`, returns new length

### Algorithm
1. Find end of `dest` then copy `src` characters and null-terminate

### Function: countWords
- Input: `const char* s`
- Output: number of whitespace-separated words

### Algorithm
1. Scan string toggling `inWord` flag when encountering non-whitespace

### Function: isPalindrome
- Input: `const char* s`
- Output: `1` if palindrome, else `0`

### Algorithm
1. Two-pointer compare from both ends towards center

### Function: substring
- Input: `src`, `start`, `len`, `dest`
- Output: writes substring into `dest` (null-terminated)

### Algorithm
1. Validate bounds then copy `len` characters starting at `start`

### Function: toLower / compareIgnoreCase
- Input/Output: lowercase a char; compare strings ignoring case

### Algorithm
1. Normalize characters to lower-case and compare sequentially

### Function: removeSpaces / removeChar
- Input: mutable string `s` (and `c` for `removeChar`)
- Output: edits `s` in-place to remove characters

### Algorithm
1. Two-index sweep copying kept characters forward and null-terminate

## Function: binarySearch

### Problem Understanding
- Input: arr[] — sorted array, size — element count, value — target
- Output: index of value if found, -1 otherwise
- Edge cases: empty array, value not present

### Algorithm
1. Maintain left/right bounds, compute mid each step
2. Compare mid with value and shrink bounds accordingly
3. Return mid when matched, -1 if bounds cross

## Function: bubbleSort

### Problem Understanding
- Input: arr[], size — number of elements
- Output: sorts arr[] in-place, returns 0 on success
- Edge cases: size <= 1 (no-op)

### Algorithm
1. Repeatedly sweep the array swapping adjacent out-of-order elements
2. Repeat passes until no swaps occur

## Function: selectionSort

### Problem Understanding
- Input: arr[], size, minpos (helper index)
- Output: sorts arr[] in-place
- Edge cases: size <= 1

### Algorithm
1. For each position i, find minimum element in remaining suffix
2. Swap minimum into position i

## Function: insertionSort

### Problem Understanding
- Input: arr[], size
- Output: sorts arr[] in-place

### Algorithm
1. Iterate elements, insert each into the sorted prefix by shifting

## Function: mergeSort

### Problem Understanding
- Input: arr[], left, right
- Output: sorts arr[left..right] in-place

### Algorithm
1. Recursively split into halves, sort each half, then merge

## Function: quickSort

### Problem Understanding
- Input: arr[], low, high
- Output: sorts arr[low..high] in-place

### Algorithm
1. Partition around pivot, recursively sort subranges

## Function: sumArray

### Problem Understanding
- Input: arr[], size
- Output: integer sum of elements (0 for empty)

### Algorithm
1. Accumulate elements in a running total and return it

## Function: findMax / findMin

### Problem Understanding
- Input: arr[], size
- Output: maximum / minimum element (0 if size <= 0)

### Algorithm
1. Iterate tracking current max/min, return result

## Function: averageArray

### Problem Understanding
- Input: numbers[], size
- Output: double average (0.0 if size == 0)

### Algorithm
1. Sum elements and divide by size, return double

## Function: reverseArray

### Problem Understanding
- Input: numbers[], size
- Output: array reversed in-place

### Algorithm
1. Swap symmetric elements from ends toward center

## Function: rotateLeft

### Problem Understanding
- Input: arr[], size, k — positions to rotate left
- Output: arr[] modified with left rotation

### Algorithm
1. Reduce k modulo size, perform k single-left rotations (simple but O(k*size))

## Function: mergeSortedArrays

### Problem Understanding
- Input: sorted a[], na, sorted b[], nb, out[] destination
- Output: out[] contains merged sorted sequence

### Algorithm
1. Two-pointer merge copying the smaller current element

## Function: initMatrix / printMatrix

### Problem Understanding
- Input: matrices and dimensions (rows, cols)
- Output: read matrix from stdin / print matrix to stdout

### Algorithm
1. `initMatrix` prompts for dimensions then reads values
2. `printMatrix` iterates rows/cols printing elements

## Function: transposeMatrix

### Problem Understanding
- Input: matrix[rows][cols], rows, cols, transposed[][]
- Output: writes transposed matrix into `transposed`

### Algorithm
1. For each i,j set transposed[j][i] = matrix[i][j]

## Function: addMatrices / multiplyMatrices

### Problem Understanding
- Input: two matrices and result buffer, plus dimensions
- Output: element-wise sum / matrix multiplication result

### Algorithm
1. `addMatrices`: pairwise add elements
2. `multiplyMatrices`: standard triple-loop multiplication

## Function: isSymmetric

### Problem Understanding
- Input: matrix, rows, cols
- Output: 1 if symmetric (square & a[i][j]==a[j][i]), else 0

### Algorithm
1. If rows!=cols return 0; compare upper triangle with lower

## Function: sortRows

### Problem Understanding
- Input: matrix, rows, cols
- Output: each row sorted in-place

### Algorithm
1. For each row, perform row-level bubble sort

## Function: sumDiagonal_antiDiagonal

### Problem Understanding
- Input: square matrix m[][n], n
- Output: prints and returns sum of main diagonal and anti-diagonal
- Edge cases: center element counted once for odd n

### Algorithm
1. Sum m[i][i] and m[i][n-1-i] across i, subtract middle if n odd

## Function: merge (static) / partition (static)

### Problem Understanding
- Helpers used by mergeSort / quickSort

### Algorithm
1. `merge`: allocate temp buffers and merge two sorted runs
2. `partition`: Lomuto partition using last element as pivot

## File utilities (file_utils.c)

### Function: writeRecord
- Problem understanding: append `Record` binary to `filename`
- Output: 0 on success, -1 on error

### Algorithm
1. Open file in `ab`, fwrite record, close file

### Function: createBinaryFile
- Creates (or truncates) a binary file; returns 0 on success

### Function: readRecord
- Reads record at given index into `r`; returns 0 on success else -1

### Function: countRecords
- Returns file size divided by sizeof(Record), or -1 if file can't open

### Function: appendRecord
- Alias of write in append mode with explicit return handling

### Function: searchRecordById
- Scans file sequentially returning index of first matching ID or -1

### Function: updateRecord
- Opens file r+b, seeks to index, overwrites record, returns 0 on success

### Function: copyBinaryFile
- Copies records from src to dest using fread/fwrite loop

## Singly linked list functions (linked_lists.c)

### Function: initArrayList
- Initialize `ArrayList` head and size

### Function: insertAtHead / insertAtTail / insertAtIndex
- Insert node at head, tail, or arbitrary index; return 0 on success

### Function: deleteAtHead / deleteAtTail
- Remove nodes and return removed value, -1 on error

### Function: displayList
- Print list elements in order

### Function: reverseList
- Reverse pointers in-place to reverse list order

### Function: sortListBubble
- Bubble-sort the linked list by swapping data values

### Function: mergeSortedLists
- Merge two sorted lists by repeatedly appending smaller head values

## Doubly linked list functions (linked_lists.c)

### Function: initListDLL
- Initialize `DLL` head/tail/size

### Function: insertAtHeadDLL / insertAtTailDLL / insertAtIndexDLL
- Insert into doubly-linked list at various positions

### Function: deleteAtHeadDLL / deleteAtTailDLL / deleteAtIndexDLL
- Remove and return values or -1 on error

### Function: dllDisplayForward / dllDisplayBackward
- Print DLL forward or backward

## String utilities (string_utils.c)

### Function: myStrLen / myStrCpy / myStrNCpy / myStrCat
- Basic string operations (length, copy, n-copy, concatenate)

### Function: countWords
- Count whitespace-separated words in a string

### Function: isPalindrome
- Returns 1 if string reads same forward/backward, else 0

### Function: substring
- Copy substring from source at `start` with length `len` into `dest`

### Function: toLower / compareIgnoreCase
- Lowercase a char; compare strings case-insensitively

### Function: removeSpaces / removeChar
- Remove spaces/tabs or a given char from the string in-place

