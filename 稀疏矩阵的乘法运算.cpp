#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=10000+10;
int num[maxn],ctmp[maxn];
typedef struct node{
	int x,y,val;
}node;
node a[maxn],c[maxn];
typedef struct Matrix{
	int n,m,k;
	node a[maxn];
}Matrix;
Matrix A,B;
Matrix Multi(Matrix Y,Matrix X){
	Matrix tmp;
	tmp.n=Y.n; tmp.m=X.m; tmp.k=0;
	int l=0,r=0;
	for(int i=1; i<=Y.n; i++){
		memset(ctmp,0,sizeof(ctmp));
		while(Y.a[l].x<i && l<Y.k) l++;
		while(Y.a[r].x<=i && r<=Y.k) r++;
		if(Y.a[l].x<i || l>=r) continue;
		int ll=0,rr=0;
		for(int j=l; j<r; j++){
			while(X.a[ll].x<Y.a[j].y && ll<X.k) ll++;
			while(X.a[rr].x<=Y.a[j].y && rr<=X.k) rr++;
			if(X.a[ll].x<Y.a[j].y || ll>=rr) continue;
			for(int u=ll; u<rr; u++){
				ctmp[X.a[u].y]+=Y.a[j].val*X.a[u].val;
			}
		}
		for(int j=1; j<=X.m; j++){
			if(ctmp[j]){
				tmp.a[++tmp.k]=node{i,j,ctmp[j]};
			}
		}
	}
	return tmp;
}
Matrix input(){
	Matrix t;
	cin>>t.n>>t.m>>t.k;
	for(int i=1; i<=t.k; i++){
		scanf("%d %d %d",&t.a[i].x,&t.a[i].y,&t.a[i].val);
	}
	return t;
}
	
void output(Matrix t){
	cout<<t.n<<endl<<t.m<<endl<<t.k<<endl;
	for(int i=1; i<=t.k; i++){
		printf("%d,%d,%d\n",t.a[i].x,t.a[i].y,t.a[i].val);
	}
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	A=input(); B=input();
	Matrix C=Multi(A,B);
	output(C);
	return 0;
}
