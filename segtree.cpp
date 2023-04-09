#include<bits/stdc++.h>
using namespace std;
#define int long long

int build(int node,vector<int>&v,vector<int>&segtree,int start,int end){
     if(start==end){
        segtree[node]=v[start];
        return segtree[node];
     }
     int mid=(start+end)/2;
     int left=build(2*node,v,segtree,start,mid);
     int right=build(2*node+1,v,segtree,mid+1,end);
     segtree[node]=left+right;
     return segtree[node];
}

int query(int node,vector<int>&segtree,int start,int end,int l,int r){
 if(l>end || start>r)return INT_MIN;
  if(l<=start && r>=end){
    return segtree[node];
  }
  int mid=(start+end)/2;
  int left=query(2*node,segtree,start,mid,l,r);
  int right=query(2*node+1,segtree,mid+1,end,l,r);
  return left+right;
}

void update(int node,vector<int>&v,vector<int>&segtree,int start,int end,int pos,int val){
    if(start==end){
        v[pos]=val;
        segtree[node]=val;
        // return val;
    }
    int mid=(start+end)/2;
    if(pos>=start && pos<=mid){
    update(2*node,v,segtree,start,mid,pos,val);
    }else{
    update(2*node+1,v,segtree,mid+1,end,pos,val);
    }
   
    segtree[node]=segtree[node*2]+segtree[node*2+1];
}

signed main(){
    int n;cin>>n;
    vector<int>v(n);
    vector<int>segtree(4*n);
    for(int i=0;i<n;i++)cin>>v[i];
    build(1,v,segtree,0,n-1);
    int q;cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        cout<<query(1,segtree,0,n-1,l,r)<<endl;
    }
    return 0;
}

