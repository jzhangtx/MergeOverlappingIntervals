package main

import (
	"fmt"
	"slices"
)

func InInterval(interval []int, t int) bool {
	return t >= interval[0] && t <= interval[1]
}

func MergeInterval(intervals [][]int, index int) int {
	count := 0
	for i := index + 1; i < len(intervals); {
		if InInterval(intervals[i], intervals[index][0]) {
			intervals[index][0] = intervals[i][0]
			if InInterval(intervals[i], intervals[index][1]) {
				intervals[index][1] = intervals[i][1]
			}
		} else if InInterval(intervals[index], intervals[i][0]) {
			if !InInterval(intervals[index], intervals[i][1]) {
				intervals[index][1] = intervals[i][1]
			}
		} else {
			i++
			continue
		}
		intervals = slices.Delete(intervals, i, i+1)
		count++
	}

	return count
}

func MergeIntervals(intervals [][]int) [][]int {
	result := make([][]int, len(intervals))
	for i := 0; i < len(intervals); i++ {
		result[i] = make([]int, len(intervals[i]))
		copy(result[i], intervals[i])
	}

	sizeOfIntervals := len(intervals) - 1
	for i := 0; i < sizeOfIntervals; i++ {
		count := MergeInterval(result, i)
		if count != 0 {
			result = result[:len(result)-count]
			sizeOfIntervals -= count
		}
	}

	return result
}

func main() {
	intervals := [][]int{{1, 2}, {2, 3}, {5, 5}}
	inter := MergeIntervals(intervals)
	fmt.Println(inter)
}
