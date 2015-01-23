/*
    Rezwan_4029 , AUST
*/

#include <bits/stdc++.h>

#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL ({Long a; scanf("%lld", &a); a;})
#define DD ({double a; scanf("%lf", &a); a;})
#define ff first
#define ss second
#define mp make_pair
#define gc getchar
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

#define FI freopen ("ain.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)

typedef long long Long;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef set<int> si;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<string,int>psi;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;
typedef vector<pii> vpii;

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

#define __(args...) {dbg,args; cerr<<endl;}
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"\t"; return *this; }}dbg;
#define __1D(a,n) rep(i,n) { if(i) printf(" ") ; cout << a[i] ; }
#define __2D(a,r,c,f) forab(i,f,r-!f){forab(j,f,c-!f){if(j!=f)printf(" ");cout<<a[i][j];}cout<<endl;}

template<class A, class B> ostream &operator<<(ostream& o, const pair<A,B>& p){ return o<<"("<<p.ff<<", "<<p.ss<<")";} //Pair print
template<class T> ostream& operator<<(ostream& o, const vector<T>& v){ o<<"[";forstl(it,v)o<<*it<<", ";return o<<"]";} //Vector print
template<class T> ostream& operator<<(ostream& o, const set<T>& v){ o<<"[";forstl(it,v)o<<*it<<", ";return o<<"]";} //Set print
template<class T> inline void MAX(T &a , T b){ if (a < b ) a = b;}
template<class T> inline void MIN(T &a , T b){ if (a > b ) a = b;}

//Fast Reader
template<class T>inline bool read(T &x){int c=gc();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=gc();}for(x=0;~c&&'0'<=c&&c<='9';c=gc())x=x*10+c-'0';x*=sgn;return ~c;}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction
const int MX = 2e5 + 7 ;
vi edge[MX], path;
int N ,Pred[MX],Vis[MX],dp[MX][22];

void Reset(){
    rep(i,N+1) edge[i].clear();
    path.clear();
    ms(Vis,false);
    rep(i,N+1) rep(j,22) dp[i][j] = -1;
}
void Input(){
    N = II ;
    Reset();
    For(i,N){
        int x = II ;
        if( i == 1 ) continue ;
        edge[x].pb(i);
    }
}
void Bfs(int SRC){
	queue<int> Q;
	Q.push(SRC);
	path.pb(SRC);
	Vis[SRC] = true;
	while(!Q.empty()){
        int u = Q.front(); Q.pop();
        forstl(it,edge[u]) {
            if( Vis[*it] ) continue ;
            Q.push(*it);
            path.pb(*it);
            Vis[*it] = true;
            Pred[*it] = u ;
        }
	}
	reverse(all(path));
    //cout << pred << endl;
}
int solve(int u, int p, int c){
    int &ret = dp[u][c];
    if( ret != -1 ) return ret;
    ret = c;
    forstl(i,edge[u]){
        int v = *i;
        int add = INT_MAX;
        if(v == p) continue;
        For(j,21) if( c != j ) MIN( add,solve(v, u, j));
        ret += add;
    }
    return ret;
}
int main(){
    freopen("corporate_gifting.txt","r",stdin);
    freopen("dout.txt","w",stdout);
    int T = II ;
    For(cs,T){
        Input();
        Bfs(1);
        int Ans = INT_MAX;
        forstl(i,path){
            For(j,21) {
                int x = solve(*i,Pred[*i],j);
                if(*i == 1) MIN(Ans,x);
            }
        }
        printf("Case #%d: %d\n",cs,Ans);
    }
}
