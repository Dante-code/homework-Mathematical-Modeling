#include <iostream>
#include <vector>
#include <cstdio>
#define size_mp 8
using namespace std;
vector<int>G[10];
int degree[10],idx,dfn;
bool vis[10];
int track[10000][2],history[10000][8][8];
void dfs(int v){
  if(vis[v]==true){
    for (auto e : G[v]){ 
      if(degree[e]>1 && vis[e]==false){
        dfs(e);
      }
    }
    
  }
  else
  {
    for (auto e : G[v]){
      if(degree[e]>1 && vis[e]==false){
        degree[e]--;
        degree[v]--;
        vis[v] = true;
        vis[e] = true;
        dfn++;
        track[dfn][0] = v;
        track[dfn][1] = e;
        dfs(e);
        vis[e] = false;
        vis[v] = false;
        track[dfn][0] = 0;
        track[dfn][1] = 0;
        dfn--;
        degree[e]++;
        degree[v]++;
      }
    }
  }
  int cnt = 0;
  for(int i=1;i<=size_mp;i++){
    if(vis[i] == true) cnt++;
  }

  if(cnt == 8){
    for(int k=1;k<=idx;k++){
      int flag = 0;
      for(int i=1;i<=dfn;i++){
        if(history[k][track[i][0]-1][track[i][1]-1] != 0){
          flag++;
        }
        if(flag == dfn) goto here;
      }
    }
    idx++;
    if(idx == 4){
      cout<<"hello world"<<endl;
    }
    for(int i=1;i<=dfn;i++){
      cout<<track[i][0]<<"<----->"<<track[i][1]<<endl;
      history[idx][track[i][0]-1][track[i][1]-1] = 1;
      history[idx][track[i][1]-1][track[i][0]-1] = 1;
    }
    printf("-----------condition%d---------\n",idx);
  }
  here:{}
}

bool check(int x,int y,int m,int maxidx){
  int upperlimit = 10,cnt = 0;
  history[m][x][y] = 1;
  history[m][y][x] = 1;
  for(int k=idx+1;k<=maxidx;k++){
    for(int i=0;i<size_mp;i++){
      for(int j=0;j<size_mp;j++){
        if(history[k][i][j]==history[m][i][j]) cnt++;
        if(cnt>=upperlimit) return false;
      }
    }
  }
  history[m][x][y] = 0;
  history[m][y][x] = 0;
  return true;
}

void copymp(int m,int x,int y){
  for(int i=0;i<size_mp;i++){
    for(int j=0;j<size_mp;j++){
      history[idx][i][j] = history[m][i][j];
    }
  }
  history[idx][x][y] = 1;
  history[idx][y][x] = 1;
}


int main(){
  int mp[8][8]={
    {0,1,1,1,0,0,0,0},
    {1,0,0,0,1,1,0,0},
    {1,0,0,1,0,0,1,0},
    {1,0,1,0,1,0,1,0},
    {0,1,0,1,0,1,1,0},
    {0,1,0,0,1,0,0,1},
    {0,0,1,1,1,0,0,1},
    {0,0,0,0,0,1,1,0}
  };
  for(int i=0;i<size_mp;i++){
    for(int j=0;j<size_mp;j++){
      if(mp[i][j]==1){
        G[i+1].push_back(j+1);
        degree[i+1]++;
      }
    }
  }

  dfs(1);
  int tail = idx;
  for(int k=1;k<=tail;k++){
    for (auto e : G[7]){
      if(history[k][6][e-1] == 0 && check(6,e-1,k,idx)){
        idx++;
        if(idx == 16){
          cout<<"hello world"<<endl;
        }
        copymp(k,6,e-1);
      }
    }
  }
  for(int k=tail+1;k<=idx;k++){
    if(k == 16){
      cout<<"hello world"<<endl;
    }
    for(int i=0;i<size_mp;i++){
      for(int j=i+1;j<size_mp;j++){
        if(history[k][i][j]!=0){
          cout<<i+1<<"<------>"<<j+1<<endl;
        }
      }
    }
    cout<<"-----condition"<<k<<"------"<<endl;
  }
  cout<<"hello world"<<endl;
  return 0;
}