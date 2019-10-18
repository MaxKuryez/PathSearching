#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class party{
    vector<vector<int>> hatredList;
public:
    void createParty(vector<vector<int>> myHatredList);
    void distribution();
        };

void party::createParty(vector<vector<int>> myHatredList){
    hatredList = myHatredList;
}

void party::distribution(){
    stack<int> myStack;
    myStack.push(0);
    bool noTable = false;
    cout<<"We pushed 0\n";
    bool marked[hatredList.size()];
    int tables[hatredList.size()];
    int currentTable = 1;
    for (int i = 0; i < hatredList.size(); i++){
        marked[i] = false;
        tables[i] = -1;
    }
    marked[0] = true;
    tables[0] = currentTable;
    while (!myStack.empty()){
        if (noTable == true){
            break;
        }
        int vertex = myStack.top();
        myStack.pop();
        currentTable = (tables[vertex] + 1) % 2;
        cout<<"We poped "<<vertex<<"\n";
        for(int i = 0; i < hatredList[vertex].size(); i++){
            if (marked[hatredList[vertex][i]] == false){
                myStack.push(hatredList[vertex][i]);
                tables[hatredList[vertex][i]] = currentTable;
                for(int j =  0; j < hatredList[hatredList[vertex][i]].size(); j++){
                    if (tables[hatredList[vertex][i]] == tables[hatredList[hatredList[vertex][i]][j]]){
                        noTable = true;
                    }
                }
                cout<<"We pushed "<<hatredList[vertex][i]<<"\n";
                marked[hatredList[vertex][i]] = true;
            }
        }
    }
    if (noTable == true){
        cout<<"They cannot sit together";
    }else{
    for (int i = 0; i < hatredList.size(); i++){
        cout<<tables[i];
    }
    }
}

int main(){
    party myParty;
    myParty.createParty({{1,2},{0,10},{0,4},{4,10},{2,3,5,7},{4,6},{5},{4,8},{7,9},{8},{1,3}});
    myParty.distribution();
}
