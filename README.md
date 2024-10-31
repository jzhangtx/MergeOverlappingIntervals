Merge Overlapping Intervals


Given a list of intervals, merge them to get a list of non-overlapping intervals.

intervali = [starti, endi]

Example:
Intervals: [[1, 2], [2, 3], [1, 4], [5, 6]]

[1, 2] and [2, 3] can be merged to form [1, 3].
Now, [1, 3] and [1, 4] can be merged to form [1, 4].
[1, 4] and [5, 6] have no intersection.
Hence above intervals are merged to form:
[[1, 4], [5, 6]]

Note that the final list should be in ascending order.

Testing
Input format
First-line contains ‘T’, denoting the number of independent test-cases.

For each test-case,

The first line contains one integer ‘n’ denoting the number of intervals.
The next n line contains 2 integers ‘start’ and ‘end’ denoting the start and end value of the interval.
Output format
For each test-case,

The first line contains ‘m’, denoting the no of intervals after merging.
The next m line contains 2 integers ‘start’ and ‘end’ denoting the start and end value of the interval.
Sample Input
3
3
1 1
2 2
3 3
3
1 4
6 7
4 5
3
1 2
2 3
5 5
Expected Output
3
1 1
2 2
3 3
2
1 5
6 7
2
1 3
5 5