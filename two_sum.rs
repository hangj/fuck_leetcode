// 1. 两数之和
// https://leetcode-cn.com/problems/two-sum/

use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map = HashMap::new();
        for i in 0 .. nums.len() {
            let sub = target - nums[i];
            if map.contains_key(&nums[i]) {
                let j = map[&nums[i] ];
                return vec![j as i32, i as i32];
            }else{
                map.insert(sub, i);
                // println!("sub:{},i:{}", sub,i);
            }
        }
        return vec![0i32, 0i32];
    }
    
}
