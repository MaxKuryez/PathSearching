#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int bfSearch( vector<vector<int>> &maze , int currPosish, int exit);

class tournament{
    vector<vector<int>> maze;
public:
    void createMaze(vector<vector<int>> myMaze);
    void competition(int firstPos, double firstVel,  int secondPos, double secondVel, int thirdPos, double thirdVel, int exit);
       };

void tournament::createMaze(vector<vector<int>> myMaze){
    maze = myMaze;
}

void tournament::competition(int firstPos, double firstVel,  int secondPos, double secondVel, int thirdPos, double thirdVel, int exit){
    double firstTravTime = bfSearch(maze, firstPos, exit)/firstVel;
    double secondTravTime = bfSearch(maze, secondPos, exit)/secondVel;
    double thirdTravTime = bfSearch(maze, thirdPos, exit)/thirdVel;
    cout<<"First time: "<<firstTravTime<<"  Second Time: "<<secondTravTime<<"   Third Time: "<<thirdTravTime;
}

int bfSearch( vector<vector<int>> &maze, int currPosish,int exit){
    queue<int> myQue;
    myQue.push(currPosish);
    bool marked[maze.size()];
    int level[maze.size()];
    level[currPosish] = 0;
    for (int i = 0; i < maze.size(); i++){
        marked[i] = false;
    }
    marked[currPosish] = true;
    while (!myQue.empty()){
        int vertex = myQue.front();
        myQue.pop();
        //cout<<"we are popping: "<<vertex<<endl;
        for (int i = 0; i < maze[vertex].size(); i++){
            if (marked[maze[vertex][i]] == false){
                //cout<<"we are pushing: "<<maze[vertex][i]<<endl;
                myQue.push(maze[vertex][i]);
                marked[maze[vertex][i]] = true;
                level[maze[vertex][i]] = level[vertex] + 1;
            }
        }
    }
    cout<<"The start point is: "<<currPosish<<endl;
    for (int i = 0; i < maze.size(); i++){
        cout<<"Level of "<<i<<" element is: "<<level[i]<<endl;

    }
    cout<<endl;
    return level[exit];
}

int main(){
    tournament myTournament;
    myTournament.createMaze({{1,2},{0,3},{0,4},{1,4},{2,3,5},{4}});
    myTournament.competition(1,1,3,2,2,3,4);
}
