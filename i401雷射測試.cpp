#include<bits/stdc++.h>
using namespace std;

#define pb push_back

vector<map<int,int>,int> val;
vector<int> x[70000],y[70000];
vector<int> rx[70000],ry[70000];
int ans=0,N=35000;

void move(int X,int Y){
	
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
} 
