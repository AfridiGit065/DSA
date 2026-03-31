#include<iostream>
using namespace std;
int P[100];
int memo[100];
int pTable[100];

void printCuts(int L){
    if(L==0)return;

    cout<<pTable[L]<<" m was taken"<<endl;
    printCuts(L-pTable[L]);

}

void initMemo(int L){
    memo[0]=0;
    for(int i=1;i<=L;i++){
        memo[i]=-1;
    }
}

void printMemo(int L){
    cout<<"**************memo***********"<<endl;
    for(int i=0;i<=L;i++){
        cout<<memo[i]<<" ";
    }
    cout<<"\n**************memo***********"<<endl;
}

void printPTable(int L){
    cout<<"**************memo***********"<<endl;
    for(int i=0;i<=L;i++){
        cout<<pTable[i]<<" ";
    }
    cout<<"\n**************memo***********"<<endl;
}

void bottomUp(){
    //do it yourself using loop

}

int RodCutting(int L){
    if(L==0){
        return 0;
    }
    if(memo[L]!=-1){
        return memo[L];
    }

    int maxValue = INT_MIN;
    int maxValueLength;
    for(int i=1;i<=L;i++){
        int value = P[i]+RodCutting(L-i);
        if(value>maxValue){
            maxValue=value;
            maxValueLength=i;
        }
    }
    pTable[L] = maxValueLength;
    memo[L]=maxValue;
    return maxValue;

}
int main(){
    int L;
    cout<<"Enter the rod length"<<endl;
    cin>>L;
    cout<<"Enter the market prices of different rod lengths:"<<endl;
    for(int i=1;i<=L;i++){
        cin>>P[i];
    }

    initMemo(L);
    printMemo(L);

    int result = RodCutting(L);
    cout<<"result = "<<result<<endl;
    printMemo(L);
    printPTable(L);
    printCuts(L);

    return 0;
}

/*
7
1 5 8 9 10 17 17
*/

