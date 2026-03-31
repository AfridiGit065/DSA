#include<iostream>
using namespace std;

int P[100];
int W[100];

int memo[100][100];
char pTable [100][100];

void initMemo(int C, int i){
    for(int r=0;r<=C;r++){
        for(int c=0;c<=i;c++){
            if(r==0 || c==0){
                memo[r][c]=0;
            }else{
                memo[r][c]=-1;
            }

        }
    }

}

void printMemo(int C, int i){
    cout<<"**************memo*****************"<<endl;
    for(int r=0;r<=C;r++){
        for(int c=0;c<=i;c++){
            cout<<memo[r][c]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\n**************memo*****************"<<endl;
}


int Knapsack(int C, int i){
    if(C==0 || i==0) return 0;

    if(memo[C][i]!=-1){
        return memo[C][i];
    }

    int notTakenValue, takenValue;

    notTakenValue = 0 + Knapsack( C , i-1);
    if(C>=W[i]){
        takenValue = P[i] + Knapsack( C-W[i] , i-1);
    }else{
        takenValue = 0;
    }

    if(notTakenValue>=takenValue){
        memo[C][i] = notTakenValue;
        pTable[C][i] = 'N';
        return notTakenValue;
    }else{
        memo[C][i] = takenValue;
        pTable[C][i] = 'T';
        return takenValue;
    }

}

void bottomUp(int C, int i){
    for(int r=1;r<=C;r++){
        for(int c=1;c<=i;c++){
            Knapsack(r,c);
        }
    }

}


void printPTable(int C, int i){
    cout<<"**************pTable*****************"<<endl;
    for(int r=0;r<=C;r++){
        for(int c=0;c<=i;c++){
            cout<<pTable[r][c]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\n**************pTable*****************"<<endl;
}

void printItems(int C, int i){
    if(C==0 || i==0){
        return ;
    }
    if (pTable[C][i]=='N'){
        cout<<"Item "<<i<<" was NOT taken"<<endl;
        printItems(C,i-1);
    }else{ // T
        cout<<"Item "<<i<<" was taken"<<endl;
        printItems(C-W[i],i-1);
    }
}

int main(){
    initMemo(99,99);


    cout<<"Enter the capacity and number of items\n"<<endl;
    int C,i;
    cin>>C;
    cin>>i;

    cout<<"Enter the prices"<<endl;
    for(int j=1;j<=i;j++){
        cin>>P[j];
    }
    cout<<"Enter the weights"<<endl;
    for(int j=1;j<=i;j++){
        cin>>W[j];
    }

    int result  = Knapsack(C,i);
    cout<<"Result = "<<result<<endl;
    //bottomUp(C,i);

    printMemo(C,i);
    printPTable(C,i);

    printItems(C,i);
    return 0;
}
