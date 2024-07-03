struct Solution;

impl Solution {
    /// f(m, n) = f(m-1, n) + f(m, n-1)
    /// f(1, n) = 1
    /// f(m, 1) = 1
    pub fn unique_paths(m: i32, n: i32) -> i32 {
        if m == 1 || n == 1 { return 1; }
        // Self::unique_paths(m-1, n) + Self::unique_paths(m, n-1)
        let mut dp = vec![vec![0; n as usize]; m as usize];
        for x in 0..m as usize {
            for y in 0..n as usize {
                dp[x][y] = if x == 0 || y == 0 {
                    1
                } else {
                    dp[x-1][y] + dp[x][y-1]
                };
            }
        }

        dp[m as usize - 1][n as usize - 1]
    }
}

#[test]
fn test() {
    assert_eq!(Solution::unique_paths(3, 2), 3);
}
