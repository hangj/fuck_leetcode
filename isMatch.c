// 10. 正则表达式匹配
// https://leetcode-cn.com/problems/regular-expression-matching/

#define ispure(c) ((c)&&(c)!='.'&&(c)!='*')

int find(char* s, int sn, char* p, int pn){
    for(int i=0; i<sn; i++){
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
    if(sn <= 0 && pn <= 0) return true;
    if(sn <= 0 || pn <= 0) return false;

    int start = -1, stop = -1; // [start, stop)
    for(int i=0; i<pn; ++i){
        if(p[i] != '.' && p[i] != '*'){
            if(i+1 == pn){
                start=i; stop=i+1;
            }
            if(i+1 < pn && p[i+1] != '.' && p[i+1] != '*'){
                if(start == -1) start = i;
                stop = i+1;
                continue;
            }

            if(start==-1) continue;

            int j = -1;
            while((j=find(s, sn, p+start, stop-start)) != -1){
                if( check(s, j, p, start)
                    && check(s+j+(stop-start), sn-j-stop+start, p+stop, pn-stop))
                return true;
            }
            return false;
        }
    }

    int j=0;
    for(int i=0; i<pn && j<sn; i++){
        if(p[i] == '.'){
            if(i+1 == pn){ // .$
                return j+1 == sn;
            }
            if(p[i+1] == '*'){ // .*
                for(int k=j;k<sn;k++){
                    if(check(s+k, sn-k, p+i+2, pn-i-2)) return true;
                }
            }else{ // .c or ..
                j++;
            }
        }else{
            // p[i] == 'c' // c stand for character
        }
    }

    return false;
}

bool isMatch(char * s, char * p){
    return check(s, strlen(s), p, strlen(p));
}
