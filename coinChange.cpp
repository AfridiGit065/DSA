#include<iostream>
using namespace std;

int Values[100];
int memo[100][100];
char pTable[100][100];

void initMemo(int M,int N){
    for(int i=0;i<=M;i++){
        for(int j=0;j<=N;j++){
            if(i==0) memo[i][j]=0;
            else if(j==0) memo[i][j]=INT_MAX;
            else memo[i][j]=-1;
        }
    }
}

void printMemo(int M,int N){
    cout<<"***********memo*********************"<<endl;
    for(int i=0;i<=M;i++){
        for(int j=0;j<=N;j++){
           cout<<memo[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\n***********memo*********************"<<endl;
}

int CoinChange(int M, int N){
    if(M<0){
        return INT_MAX;
    }
    if(M!=0 && N==0){
        return INT_MAX;
    }
    if(M==0){
        return 0;
    }

    if(memo[M][N]!=-1){
        return memo[M][N];
    }

    int notTaken, taken;

    notTaken = 0+CoinChange(M,N-1);



    //taken = 1+ CoinChange(M-Values[N],N-1);
    int returnValueForTakenFunctionCall = CoinChange(M-Values[N],N-1);

    if(returnValueForTakenFunctionCall==INT_MAX){
        taken = returnValueForTakenFunctionCall;
    }else{
        taken = 1+returnValueForTakenFunctionCall;
    }

    if(notTaken<=taken){
        memo[M][N]=notTaken;
        pTable[M][N]='N';
        return notTaken;
    }else{
        memo[M][N]=taken;
        pTable[M][N]='T';
        return taken;
    }


}


void printCoins(int M,int N){
        if(M==0 || N==0) return;

        if(pTable[M][N]=='N'){
            cout<<"Coin "<<N<<" (Tk"<<Values[N]<<") was not taken"<<endl;
            printCoins(M,N-1);
        }else{
            cout<<"Coin "<<N<<" (Tk"<<Values[N]<<") was  taken"<<endl;
            printCoins(M-Values[N],N-1);
        }


}

void bottomUp(int M, int N){
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            CoinChange(i,j);
        }
    }
}

int main(){
    cout<<"INT MAX or INF in our computer "<<INT_MAX<<endl;
    cout<<"Enter the amount and the number of coins\n";
    int M, N;
    cin>>M>>N;

    cout<<"Enter the coin values\n";
    for(int i=1;i<=N;i++){
        cin>>Values[i];
    }
    cout<<"You entered the coin values\n";
    for(int i=1;i<=N;i++){
        cout<<Values[i]<<" ";
    }

    initMemo(M,N);
    printMemo(M,N);
//    top down approach
//    int result = CoinChange(M,N);
//    cout<<"result = "<<result<<endl;

    //bottom up approach
    bottomUp(M,N);
    printMemo(M,N);
    printCoins(M,N);
    return 0;
}

/*
10
4
3 1 2 1
*/
