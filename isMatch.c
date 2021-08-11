// 10. 正则表达式匹配
// https://leetcode-cn.com/problems/regular-expression-matching/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 绞尽脑汁，想了两天才搞定
// 以确定性的字符串为分界，分而治之。
// 比如 p = "a*.*c*abcd*e*c*."; s = "ijpqabcxyz";，其中 abc 即为确定性字符串，找到目标字符串 s 中的 abc 出现的位置
// 也就是把 isMatch("ijpqabcxyz", "a*.*c*abcd*e*c*.") 转换成了 isMatch("ijpq", "a*.*c*") 和 isMatch("xyz", "d*e*c*.")

typedef int bool;
#define true 1
#define false 0


int find(char* s, int start_pos, int sn, char* p, int pn){
    printf("find => s: %s, start_pos: %d, sn: %d, p: %s, pn: %d\n",s,start_pos,sn,p,pn);
    for(int i=start_pos; i<sn; i++){
        if(s[i] != *p) continue;
        int j=1;
        for(; i+j<sn && j<pn; j++){
            if(s[i+j] != p[j]) break;
        }
        if(j != pn) continue;
        return i;
    }
    return -1;
}

bool check(char* s, int sn, char* p, int pn){
    printf("check => s: %s, sn: %d, p: %s, pn: %d\n", s, sn, p, pn);
    if(sn <= 0 && pn <= 0) return true;
    // if(sn <= 0 || pn <= 0) return false;

    int start = -1, stop = -1; // [start, stop)
    for(int i=0; i<pn; ++i){
        if(p[i] != '.' && p[i] != '*'){
            if(i+1 == pn){
                start=i; stop=i+1;
            }
            if(i+1 < pn && p[i+1] != '*'){
                if(start == -1) start = i;
                stop = i+1;
                continue;
            }

            if(start==-1) continue;

            int j = -1;
            int start_pos = 0;
            while((j=find(s, start_pos, sn, p+start, stop-start)) != -1){

                if( check(s, j, p, start)
                    && check(s+j+(stop-start), sn-j-stop+start, p+stop, pn-stop))
                return true;
                start_pos = j + 1;
            }
            return false;
        }else{
            if(start != -1){
                int j = -1;
                int start_pos = 0;
                while((j=find(s, start_pos, sn, p+start, stop-start)) != -1){

                    if( check(s, j, p, start)
                        && check(s+j+(stop-start), sn-j-stop+start, p+stop, pn-stop))
                    return true;
                    start_pos = j + 1;
                }
                return false;
            }
        }
    }

    int j=0;
    for(int i=0; i<pn; i++){
        if(p[i] == '.'){
            if(i+1 == pn){ // .$
                return j+1 == sn;
            }
            if(p[i+1] == '*'){ // .*
                // if(j==sn)return true;
                for(int k=j;k<=sn;k++){
                    if(check(s+k, sn-k, p+i+2, pn-i-2)) return true;
                }
                return false;
            }else{ // .c or ..
                j++;
                // if(j >= pn) return false;
            }
        }else{
            // p[i] == 'c' // c stand for character
            // p[i+1] == '*'
            char c = p[i];
            // if(j==sn) return true;
            for(int k=j;k<=sn;k++){
                if(check(s+k, sn-k, p+i+2, pn-i-2)) return true;
                if(s[k] != c) return false;
            }
            return false;
        }
    }

    return false;
}

bool isMatch(char * s, char * p){
    return check(s, strlen(s), p, strlen(p));
}




int main(void) {
    
    int arr[] = {1,2,3,4,9, 15,};
    int value = 0;

    printf("b: %d\n", isMatch("aaa", "a*a"));
    printf("b: %d\n", isMatch("aaa", "a*"));
    printf("b: %d\n", isMatch("aa", "a"));
    printf("b: %d\n", isMatch("ab", ".*"));
    printf("b: %d\n", isMatch("aaa", "ab*ac*a"));
    printf("b: %d\n", isMatch("aa", "b*ac*a"));
    printf("b: %d\n", isMatch("a", "b*a"));
    printf("b: %d\n", isMatch("", "b*"));
    printf("b: %d\n", isMatch("a", "a."));
    printf("b: %d\n", isMatch("a", "c*a"));
    printf("b: %d\n", isMatch("bbcbbcbcbbcaabcacb", "a*.*ac*a*a*.a..*.*"));
    // printf("b: %d\n", isMatch("bbcbbcbcbbc", "a*.*"));
    // printf("b: %d\n", isMatch("abcacb", "c*a*a*.a..*.*"));
    // printf("b: %d\n", isMatch("", "c*a*a*."));
    // printf("b: %d\n", isMatch("bcacb", "..*.*"));


    return 0;
}
