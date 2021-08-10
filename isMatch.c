// 10. 正则表达式匹配
// https://leetcode-cn.com/problems/regular-expression-matching/


bool isMatch(char * s, char * p){
    for(int i=0; p[i]; ++i){
        if(p[i] == '.'){
            if(!p[i+1]){ // .
                s++;
                return !*s;
            }else if(p[i+1] != '*'){ // .c
                if(!*s++)return false;
            }else{
                // p[i+1] == '*'
                i += 2;
                char c = p[i];
                if(!c) return true; // .*
                for(; *s && *s != c; s++); // .*c
                if(!*s++) return false; // 找到就近 c 就可以
            }
        }else{
            // c || c. || cc
            if(p[i+1] != '*'){
                if(*s++ != p[i]) return false;
            }else{
                // c*

            }
        }
    }
}
