#include<bits/stdc++.h>
using namespace std;

vector<map<int,int>,int> val;
vector<int> x[70000],y[70000];
vector<int> rx[70000],ry[70000];
int ans=-1,N=35000,dir=1;//1右 2下 3左 4上

void move(int X,int Y){
	bool op = true;
  while(op){
    op = false;
    ans++;
    if(dir == 1 or dir == 3){
      if (y[Y].size()) {
        auto it = (dir == 1)
        ? upper_bound(y[Y].begin(), y[Y].end(), X)
        : upper_bound(ry[Y].begin(), ry[Y].end(), X, greater<int>());
        if (it != y[Y].end() && it != ry[Y].end()) {
          if (val[{*it, Y}] == 1) {
            dir = (dir == 1) ? 2 : 4;
          } 
          else if (val[{*it, Y}] == 0) {
            dir = (dir == 1) ? 4 : 2;
          }
          X = *it;
          op = true;
          continue;
        }   
      }
    }
    else if(dir == 2 or dir == 4){
      if(x[X].size()){
        auto it = (dir == 2)
        ? upper_bound(x[X].begin(), x[X].end(), Y)
        : upper_bound(x[X].begin(), x[X].end(), Y, greater<int>());
        if(it != x[X].end() && it != rx[X].end()){
          if(val[{*it,X}] == 1){
            dir = (dir == 2) ? 1 : 3;
          }
          else if (val[{*it, Y}] == 0) {
            dir = (dir == 2) ? 3 : 1;
          }
          Y = *it;
          op = true;
          continue;
      }  
    }
  }
}

int main(){
	for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a += N, b += N;
    x[a].push_back(b);
    y[b].push_back(a);
    rx[a].push_back(b);
    ry[b].push_back(a);
    val[{a, b}] = c;
  }
  for (int i = 0; i < 70000; i++) {
    sort(x[i].begin(), x[i].end());
    sort(y[i].begin(), y[i].end());
    sort(rx[i].rbegin(), rx[i].rend());
    sort(ry[i].rbegin(), ry[i].rend());
  }
  move(N,N);
  cout << ans;
} 
