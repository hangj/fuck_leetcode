// LCP 01. 猜数字
// https://leetcode-cn.com/problems/guess-numbers/

int game(int* guess, int guessSize, int* answer, int answerSize){
    answerSize = 0;
    for(int i=0; i < guessSize; i++)
        answerSize += guess[i] == answer[i] ? 1 : 0;
    return answerSize;
}
