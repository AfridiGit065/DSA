#include<iostream>
using namespace std;

int P[100];
int W[100];
int memo[20][20];
char pTable[20][20];

void initializeMemo(int r,int c){
    for(int i=0;i<=r;i++){
        for(int j=0;j<=c;j++){
            if(i==0){
                memo[i][j]=0;
            }else if(j==0){
                memo[i][j]=0;
            }else{
                memo[i][j]=-1;
            }

        }
    }

}


void printMemo(int r, int c){
    cout<<"**************memo******************"<<endl;
    for(int i=0;i<=r;i++){
        for(int j=0;j<=c;j++){
            cout<<memo[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\n********************************"<<endl;

}

void printPTable(int r, int c){
    cout<<"**************pTable******************"<<endl;
    for(int i=0;i<=r;i++){
        for(int j=0;j<=c;j++){
            cout<<pTable[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\n********************************"<<endl;

}

int Knapsack(int C, int i){
    if(C==0 || i==0){
        return 0;
    }

    if(memo[C][i]!=-1){
        return memo[C][i];
    }

    int notTakenValue;
    int takenValue;

    notTakenValue = 0 + Knapsack(C,i-1);
    if(C>=W[i]){
        takenValue=P[i]+Knapsack(C-W[i],i-1);
    }else{
        takenValue=0;
    }

    if(notTakenValue>=takenValue){
        pTable[C][i]='N';
        memo[C][i]=notTakenValue;
        return notTakenValue;
    }else{
        pTable[C][i]='T';
        memo[C][i]=takenValue;
        return takenValue;
    }


}

void bottomUp(int C, int N){
    for(int i=1;i<=C;i++){
        for(int j=1;j<=N;j++){
            Knapsack(i,j);
        }
    }

}

void printItems(int C, int i){
    if(C==0||i==0){
        return;
    }
    if(pTable[C][i]=='N'){
        cout<<"item "<<i<<" was NOT taken"<<endl;
        printItems(C,i-1);
    }else if(pTable[C][i]=='T'){
        cout<<"item "<<i<<" was taken"<<endl;
        printItems(C-W[i],i-1);
    }

}


int main(){
    int C;
    int N;
    cout<<"Enter the capacity"<<endl;
    cin>>C;
    cout<<"Enter the number of items"<<endl;
    cin>>N;
    cout<<"Enter the prices"<<endl;
    for(int i=1;i<=N;i++){
        cin>>P[i];
    }
    cout<<"Enter the weights"<<endl;
    for(int i=1;i<=N;i++){
        cin>>W[i];
    }
    initializeMemo(C,N);
    printMemo(C,N);

    int result = Knapsack(C,N);
    cout<<"result = "<<result<<endl;
    //bottomUp(C,N);
    printMemo(C,N);
    printPTable(C,N);

    printItems(C,N);

    return 0;
}

/*

5
4
3 4 5 6
2 3 4 5


4 3
7 5 10
1 3 2
*/
