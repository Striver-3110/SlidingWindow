# Sliding Window Algorithm

## Introduction

The sliding window algorithm is a commonly used technique in computer science to solve problems involving arrays or lists. It is especially useful for problems that require analyzing subarrays or sublists of a given size within a larger array or list. This technique helps in optimizing the performance by reducing the time complexity compared to naive approaches.

## How It Works

The basic idea behind the sliding window algorithm is to maintain a window that slides over the array or list. This window can be of fixed or variable size. As the window slides, the algorithm processes the elements within the window to solve the problem at hand.

### Fixed-Size Window

In a fixed-size window, the window size remains constant throughout the process. The window slides from the beginning of the array to the end, one element at a time.

### Variable-Size Window

In a variable-size window, the window size can change dynamically based on the problem's requirements. The window can expand or contract as needed while traversing the array.

## Common Use Cases

1. **Maximum or Minimum of All Subarrays of Size K**:
   Find the maximum or minimum values in all subarrays of a given size K.

2. **Longest Substring Without Repeating Characters**:
   Find the length of the longest substring without repeating characters in a string.

3. **Anagram Finding**:
   Find all the starting indices of anagram substrings in a given string.

4. **Subarray Sum Equals K**:
   Find the number of subarrays that sum up to a given value K.

## Pseudocode

### Fixed-Size Sliding Window

```python
def sliding_window_fixed_size(arr, k):
    n = len(arr)
    window_sum = sum(arr[:k])
    max_sum = window_sum

    for i in range(n - k):
        window_sum = window_sum - arr[i] + arr[i + k]
        max_sum = max(max_sum, window_sum)

    return max_sum
```