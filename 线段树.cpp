#include<cstdio>
#include<iostream>
#define maxn 100007

using namespace std;
int sum[maxn<<2],add[maxn<<2];
int a[maxn],n;

void pushup(int root){
	sum[root]=sum[root<<1]+sum[root<<1|1];
}
void build(int l,r,int root){
	if(l==r){
		sum[root]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,root<<1);
	build(mid,r,root<<1|1);
	pushup(root);
}

void update_node(int L,int c,int l,int r,int root){
	if(l==r){
		sum[root]+=c;
		return;
	}
	int mid=(l+r)>>1;
	if(L<=m)update_node(L,c,l,mid.rt<<1);
	else update_node(L,c,mid,r,rt<<1|1);
	pushup(root);
}
void pushdown(int root,int ln,int rn){
	if(add[root]){
		add[root<<1]+=add[root];
		add[root<<1|1]+=add[root];
		sum[root<<1]+=add[root]*ln;
		sum[root<<1|1]+=add[root]*rn;
		add[root]=0; 
	}
}
void update(int L,int R,int c,int l,int r,in root){
	if(L<=l&&r<=R){
		sum[root]+=(r-l+1)*c;
		add[rt]+=c;
		return; 
	}
	int mid=(l+r)>>1;
	pushdown(root,m-l+1,r-m);
	if(L<=m)update(L,R,c,l,m,root<<1);
	if(R>m)update(L,R,c,m,r,root<<1|1);
	pushup(root);
}
int query(int L,int R,int l,int r,int root){
	if(L<=l&&r<=R){
		return sum[root];
	}
	int mid=(l+r)<<1;
	pushdown(root,m-l+1,r-m);
	int ans=0;
	if(L<=m)ans+=query(L,R,l,m,rt<<1);
	if(R>m)ans+=query(L,R,m+1,r,rt<<1|1);
}
int main(){
	
} 
