struct Solution;
impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        use std::collections::HashMap;
        let mut hm = HashMap::<char, usize>::new();
        let mut start = 0usize;
        let mut stop = start;
        let mut longest = 0usize;
        for (i, c) in s.chars().enumerate(){
            match hm.get(&c) {
                Some(j) => {
                    if *j >= start {
                        start = j + 1;
                    }
                },
                None => (),
            }
            hm.insert(c, i);
            stop = i;

            // println!("start: {}, stop: {}", start, stop);

            // if start >= stop { return 0; }
            if stop - start + 1 > longest {
                longest = stop - start + 1;
            }
        }

        longest as i32
    }
}
