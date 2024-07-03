//! https://leetcode.cn/problems/lru-cache/
//! 请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
//! 实现 LRUCache 类：
//! LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
//! int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
//! void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
//! 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
//! 
//! 
//! 示例：
//! 
//! 输入
//! ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//! [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//! 输出
//! [null, null, null, 1, null, -1, null, -1, 3, 4]
//! 
//! 解释
//! LRUCache lRUCache = new LRUCache(2);
//! lRUCache.put(1, 1); // 缓存是 {1=1}
//! lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
//! lRUCache.get(1);    // 返回 1
//! lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
//! lRUCache.get(2);    // 返回 -1 (未找到)
//! lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
//! lRUCache.get(1);    // 返回 -1 (未找到)
//! lRUCache.get(3);    // 返回 3
//! lRUCache.get(4);    // 返回 4
//! 
//! 
//! 提示：
//! 
//! 1 <= capacity <= 3000
//! 0 <= key <= 10000
//! 0 <= value <= 105
//! 最多调用 2 * 105 次 get 和 put


use std::collections::HashMap;
use std::fmt;
use std::fmt::Display;
use std::fmt::Debug;
use std::ptr::null_mut;
use std::iter;
use std::marker::PhantomData;

#[derive(Debug)]
pub struct Node<T: Debug> {
    pub data: T,

    pub prev: *mut Node<T>,
    pub next: *mut Node<T>,
}

impl<T: Debug> Node<T> {
    pub fn new(data: T) -> Self {
        Self {
            data,
            prev: null_mut(),
            next: null_mut(),
        }
    }
}

#[derive(Debug)]
pub struct List<T: Debug> {
    pub head: *mut Node<T>,
    pub tail: *mut Node<T>,
}

impl<T: Debug> List<T> {
    pub fn new() -> Self {
        Self {
            head: null_mut(),
            tail: null_mut(),
        }
    }

    pub fn push_back(&mut self, data: T) -> &mut Self {
        let mut p_node = Box::into_raw(Box::new(Node::new(data)));

        // empty list
        if self.tail == null_mut() {
            self.head = p_node;
            self.tail = p_node;
            return self;
        }

        unsafe {
            (*p_node).prev = self.tail;
            (*self.tail).next = p_node;
            self.tail = p_node;
        }

        self
    }

    // move node to tail
    pub fn repush_node(&mut self, node: *mut Node<T>) {
        // 1. unlink node
        // 2. push back

        // no need to do anything
        if self.tail == node {
            return;
        }

        unsafe {
            if self.head == node {
                self.head = (*self.head).next;
                (*self.head).prev = null_mut();
            } else {
                (*(*node).prev).next = (*node).next;
                (*(*node).next).prev = (*node).prev;
            }
            (*node).next = null_mut();
            (*node).prev = self.tail;
            (*self.tail).next = node;
        }

        self.tail = node;
    }
}

impl<T: Debug> Drop for List<T> {
    fn drop(&mut self) {
        for node in self.iter() {
            unsafe {let _ = Box::from_raw(node);}
        }
    }
}

pub struct NodeIter<'a, T: Debug>(*mut Node<T>, PhantomData<&'a List<T>>);

impl<T: Debug> List<T> {
    pub fn iter(&self) -> NodeIter<'_, T> {
        NodeIter(self.head, PhantomData)
    }
}

impl<'a, T: Debug> iter::Iterator for NodeIter<'a, T> {
    type Item = *mut Node<T>;

    // Required method
    fn next(&mut self) -> Option<Self::Item> {
        if self.0.is_null() {
            return None;
        }
        let p = self.0;
        self.0 = unsafe {(*p).next};
        Some(p)
    }
}

// impl<T: Display + Debug> fmt::Display for List<T> {
//     fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
//         write!(f, "List(")?;
//         let mut b = false;
//         for node in self.iter() {
//             if b {
//                 write!(f, ", ")?;
//             } else {
//                 b = true;
//             }
//             unsafe {
//                 write!(f, "{:?}", (*node).data)?;
//             }
//         }
//         write!(f, ")")
//     }
// }

#[derive(Debug, Clone)]
struct Value<T: Clone + Debug, K: Debug + Clone + Eq + PartialEq + std::hash::Hash> {
    key: K,
    value: T,
}

// impl<T: Clone + Debug, K: Debug + Clone + Eq + PartialEq + std::hash::Hash> Display for Value<T, K> {
//     fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
//         write!(f, "Value{{key:{:?}, value:{:?} }}", self.key, self.value)
//     }
// }

#[derive(Debug)]
pub struct RealLRUCache<T: Clone + Debug, K: Debug + Clone + Eq + PartialEq + std::hash::Hash> {
    capacity: usize,
    list: List<Value<T, K>>,
    key_value: HashMap<K, *mut Node<Value<T, K>>>,
}

impl<T: Clone + Debug, K: Debug + Clone + Eq + PartialEq + std::hash::Hash> RealLRUCache<T, K> {
    pub fn new(capacity: usize) -> Self {
        Self {
            capacity,
            list: List::new(),
            key_value: HashMap::with_capacity(capacity),
        }
    }

    pub fn get(&mut self, key: K) -> Option<T> {
        match self.key_value.get(&key) {
            Some(v) => unsafe {
                let node = *v;
                self.list.repush_node(node);

                Some((*node).data.value.clone())
            },
            None => None,
        }
    }

    pub fn put(&mut self, key: K, value: T) {
        match self.key_value.get(&key) {
            Some(v) => unsafe {
                let node = *v;
                (*node).data.value = value;
                self.list.repush_node(node);
            },
            None => unsafe {
                if self.key_value.len() >= self.capacity {
                    let node = self.list.head;
                    self.key_value.remove(&(*node).data.key);

                    (*node).data.key = key.clone();
                    (*node).data.value = value;

                    self.list.repush_node(node);
                    self.key_value.insert(key, node);
                } else {
                    self.list.push_back(Value {key: key.clone(), value});
                    let node = self.list.tail;
                    self.key_value.insert(key, node);
                }
            },
        }
    }
}

// impl<T, K> Display for RealLRUCache<T, K> 
// where
//     T: Clone + Debug,
//     K: Debug + Clone + Eq + PartialEq + std::hash::Hash,
// {
//     fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
//         write!(f, "RealLRUCache {{\n")?;
//         write!(f, "capacity: {capacity},\n", capacity=self.capacity)?;
//         write!(f, "list: {},\n", self.list)?;
//         write!(f, "key_value: {:?},\n", self.key_value)?;
//         write!(f, "}}")
//     }
// }

struct LRUCache {
    proxy: RealLRUCache<i32, i32>,
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl LRUCache {

    fn new(capacity: i32) -> Self {
        Self {
            proxy: RealLRUCache::new(capacity as usize),
        }
    }
    
    fn get(&mut self, key: i32) -> i32 {
        self.proxy.get(key).unwrap_or(-1)
    }

    fn put(&mut self, key: i32, value: i32) {
        self.proxy.put(key, value)
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * let obj = LRUCache::new(capacity);
 * let ret_1: i32 = obj.get(key);
 * obj.put(key, value);
 */
mod xx{}
