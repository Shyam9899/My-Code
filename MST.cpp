// TC = O(N+E)logN

#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base:: sync_with_stdio(0);
cin.tie(0);
int n=5,m;
vector<pair<int,int>> adj[n];
int a,b,wt;
adj[0].push_back({1,2});
adj[1].push_back({0,2});
adj[2].push_back({1,3});
adj[1].push_back({2,3});
adj[0].push_back({3,6});
adj[3].push_back({0,6});
adj[3].push_back({1,8});
adj[1].push_back({3,8});
adj[4].push_back({1,5});
adj[1].push_back({4,5});
adj[2].push_back({4,7});
adj[4].push_back({2,7});

vector<int> key(n,INT_MAX);
vector<bool> mstset(n,false);
vector<int> parent(n,-1);

priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;

key[0]=0;
pq.push({0,0});  // value,index
parent[0]=-1;

for(int count=0;count<n-1;count++){

//  int mn=INT_MAX,ind;
  
  /*
  for(int i=0;i<n;i++){
  if(mstset[i]==false && key[i]<mn){
  mn=key[i];
  ind=i;
  } }
  */
 int ind=pq.top().second; 
 pq.pop();
  mstset[ind]=true;

  for(auto it : adj[ind]){
  int node= it.first;
  int dis=it.second;
  if(mstset[node]==false &&  dis<key[node]){
  	parent[node]=ind; key[node]=dis; pq.push({key[node],node});
   }
  }

}

 for(int i=0;i<n;i++){
  cout<<parent[i]<<" - "<<i<<"\n";
   }

return 0;
}

/*
// TC = O(N^2)
#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base:: sync_with_stdio(0);
cin.tie(0);
int n=5,m;
vector<pair<int,int>> adj[n];
int a,b,wt;
adj[0].push_back({1,2});
adj[1].push_back({0,2});
adj[2].push_back({1,3});
adj[1].push_back({2,3});
adj[0].push_back({3,6});
adj[3].push_back({0,6});
adj[3].push_back({1,8});
adj[1].push_back({3,8});
adj[4].push_back({1,5});
adj[1].push_back({4,5});
adj[2].push_back({4,7});
adj[4].push_back({2,7});

vector<int> key(n,INT_MAX);
vector<bool> mstset(n,false);
vector<int> parent(n,-1);

key[0]=0;
parent[0]=-1;

for(int count=0;count<n-1;count++){

  int mn=INT_MAX,ind;
  
  for(int i=0;i<n;i++){
  if(mstset[i]==false && key[i]<mn){
  mn=key[i];
  ind=i;
  } }
  
  mstset[ind]=true;

  for(auto it : adj[ind]){
  int node= it.first;
  int dis=it.second;
  if(mstset[node]==false &&  dis<key[node]){
  	parent[node]=ind; key[node]=dis;
   }
  }

}

 for(int i=0;i<n;i++){
  cout<<parent[i]<<"-"<<i<<"\n";
   }

return 0;
}*/
