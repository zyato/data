package main

import (
	"sort"
)

// 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
func permuteUnique(nums []int) [][]int {
	sort.Ints(nums)
	n := 1
	for i := len(nums); i > 1; i-- {
		n *= i
	}
	res := make([][]int, 0, n)
	res = append(res, append([]int{}, nums...))
	for nextPermutation(nums) {
		res = append(res, append([]int{}, nums...))
	}
	return res
}

// return hasNext
func nextPermutation(nums []int) bool {
	// 逆序找到第一个数值下降的下标记为idx，需要把此位置数值变大，以获取下一个排列
	// 显然，需要把idx之后的第一个大于nums[idx]的数移过来，才能满足下一个排列的条件(最小的大于nums排列的排列)，并交换两个位置数值
	// 交换之后同样满足nums[idx+1:]是非增序列，当nums[idx]变大后，需要让nums[idx+1:]变成非减的，即为下一个排列
	for i := len(nums) - 2; i >= 0; i-- {
		// 为了去重，这里需要取等于
		if nums[i] >= nums[i+1] {
			continue
		}
		idx := search(nums, i+1, len(nums)-1, nums[i])
		nums[i], nums[idx] = nums[idx], nums[i]
		reverse(nums, i+1, len(nums)-1)
		return true
	}
	// 走到这意味着nums逆序，没有下一个排列，或者从升序重新开始
	reverse(nums, 0, len(nums)-1)
	return false
}

func reverse(nums []int, i, j int) {
	for i < j {
		nums[i], nums[j] = nums[j], nums[i]
		i++
		j--
	}
}

// 找非增数组最后一个大于target的下标
func search(nums []int, l, r, v int) int {
	for l <= r {
		m := l + (r-l)/2
		if nums[m] <= v {
			r = m - 1
		} else {
			l = m + 1
		}
	}
	return r
}
