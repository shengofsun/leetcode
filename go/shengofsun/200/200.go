package main

import "fmt"

func flood_fill(grid [][]byte, visit [][]bool, r int, c int) {
	if r<0 || r>=len(grid) || c<0 || c>=len(grid[0]) {
		return
	}
	if visit[r][c] || grid[r][c]!=1 {
		return
	}
	visit[r][c] = true
	flood_fill(grid, visit, r, c-1)
	flood_fill(grid, visit, r, c+1)
	flood_fill(grid, visit, r-1, c)
	flood_fill(grid, visit, r+1, c)
}

func numIslands(grid [][]byte) int {
	row_count := len(grid)
	col_count := len(grid[0])
	visit := make([][]bool, row_count)
	for i:=0; i<row_count; i++ {
		visit[i] = make([]bool, col_count)
		for j:=0; j<col_count; j++ {
			visit[i][j] = false
		}
	}

	result := 0
	for i:=0; i<row_count; i++ {
		for j:=0; j<col_count; j++ {
			if !visit[i][j] && grid[i][j]==1 {
				flood_fill(grid, visit, i, j)
				result++
			}
		}
	}
	return result
}

func main() {
	grid_map := [][]byte {
		{1, 1, 1, 1, 0},
		{1, 1, 0, 1, 0},
		{1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0},
	}
	fmt.Println(numIslands(grid_map))

	grid_map2 := [][]byte {
		{1, 1, 0, 0, 0},
		{1, 1, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 1, 1},
	}
	fmt.Println(numIslands(grid_map2))
}
