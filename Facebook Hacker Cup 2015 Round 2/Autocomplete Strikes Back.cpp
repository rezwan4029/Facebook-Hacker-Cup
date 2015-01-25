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

const int MX = 20007;
const int INF = 1e9 ;

struct trie {
    trie * next[26];
    int level;
    int end;
}*root ;

trie M[MX];

int Node , N , K;
char Str[MX];
int dp[MX][111];


trie *newnode () {
    trie *p = &M[Node++];
    ms(p->next, NULL);
    p->end = p->level = 0;
    return p;
}

void Insert (trie *p) {
    for (int i = 0 ; Str[i] ; i ++) {
        int x = Str[i] - 'a';
        if( p->next[x] == NULL) p->next[x] = newnode();
        p = p->next[x];
        p->level = i + 1;
    }
    p->end = 1;
}

void go(int u , int pre) {
    dp[u][0] = 0;
    rep(i,26) {
        if( M[u].next[i] ) {
            int v = M[u].next[i] - M;
            go(v , u);
            rofba(j,0,K) forab(p,0,j) MIN ( dp[u][j] , dp[u][p] + dp[v][j - p]);
        }
    }
    if( M[u].end) {
        rofba(i,0,K-1) MIN ( dp[u][i+1] , dp[u][i] + M[u].level);
    }
    if( M[u].level ) MIN( dp[u][1], M[u].level);
}

void Reset(){
    rep(i,MX-2) rep(j,110) dp[i][j] = INF ;
    Node = 0;
    root = newnode ();
}

int main () {
    //freopen ("bin.txt" , "r" , stdin);
    freopen ("autocomplete_strikes_back.txt" , "r" , stdin);
    freopen ("bout.txt" , "w" , stdout);
    int T = II ;
    For(cs,T){
        Reset();
        N = II , K = II ;
        rep(i,N) {
            scanf("%s",Str);
            Insert(root);
        }
        go(0,-1);
        printf ("Case #%d: %d\n",cs,dp[0][K]);
    }
}
