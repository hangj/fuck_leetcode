// 1. 两数之和
// https://leetcode-cn.com/problems/two-sum/

use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map= HashMap::new();
        for (i,v) in nums.iter().enumerate() {
            let sub = target - v;
            if map.contains_key(v) {
                let j = map[v];
                return vec![j as i32, i as i32];
            }else{
                map.insert(sub, i);
            }
        }
        return vec![0, 0];
    }
    
}
