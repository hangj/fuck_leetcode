

// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Option<Box<ListNode>>
}

impl ListNode {
  #[inline]
  fn new(val: i32) -> Self {
    ListNode {
      next: None,
      val
    }
  }
}



struct Solution{}



impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut other = 0i32;
        let mut ret: Option<Box<ListNode>> = None;
        let mut tail: &mut Option<Box<ListNode>> = &mut ret;

        let mut p1: &Option<Box<ListNode>> = &l1;
        let mut p2: &Option<Box<ListNode>> = &l2;


        loop{
            if *p1 == None && *p2 == None && other==0 { break ret; }

            let v1 = match p1 {
                Some(ref node) => {p1 = &node.next; node.val},
                None => 0,
            };
            let v2 = match p2 {
                Some(node) => {p2 = &node.next; node.val},
                None => 0,
            };

            // println!("v1: {}, v2: {}", v1, v2);

            let sum = v1 + v2 + other;
            let v = sum % 10;
            other = sum / 10;

            match tail {
                Some(node) => {
                    node.next = Some(Box::new(ListNode::new(v)));
                    tail = &mut node.next;
                },
                None => {
                    *tail = Some(Box::new(ListNode::new(v)));
                },
            }
        }
    }
}


