struct Solution;

impl Solution {
    pub fn min_path_sum(grid: Vec<Vec<i32>>) -> i32 {
        let mut dp = vec![vec![0; grid[0].len()]; grid.len()];
        for x in 0..grid.len() {
            for y in 0..grid[0].len() {
                dp[x][y] = grid[x][y] + if x == 0 && y == 0 {
                    0
                } else if x == 0 {
                    dp[x][y-1]
                } else if y == 0 {
                    dp[x-1][y]
                } else {
                    std::cmp::min(
                        dp[x-1][y],
                        dp[x][y-1],
                    )
                }
            }
        }
        *dp.last().unwrap().last().unwrap()
    }
}

#[test]
fn test() {
    let x = Solution::min_path_sum(vec![
        vec![1,3,1],
        vec![1,5,1],
        vec![4,2,1]
    ]);
    assert_eq!(x, 7);
}
