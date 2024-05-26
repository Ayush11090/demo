#include<iostream>
#include <vector>
#include<limits.h>
using namespace std;


vector<int> board = {2,2,2,2,2,2,2,2,2};
vector<vector<int>> win ={{0,1,2},{3,4,5},{6,7,8},{0,4,8},{2,4,6},{0,3,6},{1,4,7},{2,5,8}};




int isWin(int x){
    
    for (int i = 0; i < 8; i++)
    {   
        int count =0;
        for (int j = 0; j < 3; j++)
        { 
            if(board[win[i][j]] == x) count ++;
        }
        if(count == 3) return 1;
    }
    return 0;
}
int draw(){
    int count =0;
    for (int j = 0; j < 9; j++)
    {
        if (board[j]==2) return 0;
    }
    return 1;
}

void print(){
    for (int i = 0; i < 9; i++)
    {
        cout<<board[i]<<"|";
        if((i+1)%3 == 0)cout<<"\n";
    }
}

void player(){
    int pos;
    cout<<"Player Turn"<<endl;
    cin>>pos;
    if(board[pos]==2) board[pos] =3;
    else player();
}

int minmax(bool maximizing){
    if(isWin(5)) return 1000;
    else if(isWin(3)) return -1000;
    else if(draw()) return 0;

    if(maximizing){
        int best = INT_MIN;
        for (int i = 0; i < 9; i++)
        {
            if(board[i]==2){
                board[i] = 5;
                int score = minmax(false);
                best = max(score,best);
                board[i] = 2;
            }
        }
        return best;
        
    }else{
        int best = INT_MAX;
        for (int i = 0; i < 9; i++)
        {
            if(board[i]==2){
                board[i] = 3;
                int score = minmax(true);
                best = min(score,best);
                board[i] = 2;
            }
        }
        return best;
    }
    

}

void bot(){
    int bestScore= INT_MIN;
    int bestIndex=0;
    for (int i = 0; i < 9; i++)
    {
        if(board[i]==2){
            board[i] = 5;
            int score = minmax(false);
            if(score>bestScore){
                bestScore = score;
                bestIndex = i;
            }
            board[i] = 2;
        }
    }
    board[bestIndex] =5;    
}
int main(){
    while (1)
    {
        player();
        print();
        if(isWin(3)){
            printf("Player wins!\n");
            return 0;
        }
        if(draw()){
            printf("Draw\n");
            return 0;
        } 
        cout<<"Bot Turn:"<<endl;
        bot();
        print();
        if(isWin(5)){
            printf("Bot wins!\n");
            return 0;
        }
        if(draw()){
            printf("Draw\n");
            return 0;
        } 
    }
    
    return 0;
}