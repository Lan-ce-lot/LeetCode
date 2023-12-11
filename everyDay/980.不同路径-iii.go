/*
 * @lc app=leetcode.cn id=980 lang=golang
 *
 * [980] 不同路径 III
 */

// @lc code=start
var dir = [4][2]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}

func uniquePathsIII(grid [][]int) int {
    r, c := len(grid), len(grid[0])
    si, sj, n := 0, 0, 0
    for i := 0; i < r; i++ {
        for j := 0; j < c; j++ {
            if grid[i][j] == 0 {
                n++
            } else if grid[i][j] == 1 {
                n++
                si, sj = i, j
            }
        }
    }
    var dfs func(i int, j int, n int) int
    dfs = func(i int, j int, n int) int {
		if grid[i][j] == 2 {
            if n == 0 {
                return 1
            }

            return 0
        }
        t, res := grid[i][j], 0
        grid[i][j] = -1
        for k := 0; k < 4; k++ {
            ni, nj := i + dir[k][0], j + dir[k][1]
            if ni >= 0 && ni < r && nj >= 0 && nj < c &&
                (grid[ni][nj] == 0 || grid[ni][nj] == 2) {
                res += dfs(ni, nj, n - 1)
            }
        }
        grid[i][j] = t
        return res
	}
    return dfs(si, sj, n)
}
// tmp

// @lc code=end

/**
asad
asd
a
da
da
dad
a
das
d
asd
as
daasd
as
das
d
adas
d
asdasdda
d
a
dada
da
da

d
dsd
s
d
sd
sd

/