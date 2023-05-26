#include <bits/stdc++.h>
using namespace std;

class transitionState{

    public:
    int toState;
    char readVal;
    char writeVal;
    char dir;

    transitionState(char readVal, int b, char writeVal, char dir){
        this -> readVal = readVal;
        this -> toState = b;
        this -> writeVal = writeVal;
        this -> dir = dir;
    }

};

static unordered_map< int, vector<transitionState> > adj;

void turingMachine(string &input, int &countTrans, int &headPointer, int &currentState){

    char c1 = input[headPointer];
    for(auto i : adj[currentState]){
        char c2 = i.readVal;
        if(c1 == c2){
            currentState = i.toState;
            char ch = i.writeVal;
            input[headPointer] = ch;
            if(i.dir == 'L'){
                headPointer--;
            }else{
                headPointer++;
            }
        }
    }
}

void program()
{
    cout<<endl;
    int states, startState, finalState, countFinal, countSymbol, countTrans;
    cout<<"Enter the number of states : ";
    cin>>states;

    cout<<"Enter the Start State : ";
    cin>>startState;

    cout<<"Enter the number of final states : ";
    cin>>countFinal;
    vector<int> finalArray;
    cout<<"Enter all the final states : ";
    for(int i = 0; i < countFinal; i++){
        int x;
        cin>>x;
        finalArray.push_back(x);
    }
    
    cout<<"Enter the number of transitions : ";
    cin>>countTrans;

    cout<<"\nEnter all the transitions --> "<<endl;
    for(int i = 0; i < countTrans; i++){
        int a, b; char readVal, writeVal, dir;
        cin>>a>>readVal>>b>>writeVal>>dir;
        adj[a].push_back(transitionState(readVal, b, writeVal, dir));
    }

    cout<<"\nEnter the input tape : ";
    string input;
    cin>>input;

    int headPointer = 1;
    int currentState = startState;

    std::vector<int>::iterator it;

    while(true){
        turingMachine(input, countTrans, headPointer, currentState);
        it = std::find(finalArray.begin(), finalArray.end(), currentState);
        if (it != finalArray.end()){
            break;
        }
    }

    cout<<"\nThe output tape : "<<input<<endl;
}

int main(){

    program();

    return 0;
}