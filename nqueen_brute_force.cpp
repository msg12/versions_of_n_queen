/* -----KAUN_MEET--------*/

#include <bits/stdc++.h>
using namespace std;
#define int long long int
int mod = 1000000007;
#define P get<0>
#define D get<1>
#define T get<2>
#define C get<3>
#define PB push_back
#define MP make_pair
#define BS binary_search
#define LB lower_bound
#define UB upper_bound
#define F first
#define S second
#define gcd __gcd
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

void __print(int x)
{
    cerr << x;
}
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename Th, typename V>
void __print(const pair<Th, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename Th>
void __print(const Th &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename Th, typename... V>
void _print(Th t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

int n;
int countt;
vector <pair<int, int>> s;
void meet(int r)
{
    int i, j;

    if (r == n)
    {
        // for(auto it:s)
        // cout<<it.F<<" "<<it.S<<"  " <<" ";

        // cout<<endl;
        int ans = 1;

        for (auto it : s)
        {
            for (auto jt : s)
            {
                if (it == jt)
                    continue;

                int x1, y1, x2, y2;
                x1 = it.F, y1 = it.S;
                x2 = jt.F, y2 = jt.S;
                int xx=abs(x1-y1);
                int yy=abs(x2-y2);
                int xx1=x1+y1;
                int yy1=x2+y2;
                if ((x1 == x2) || (y1 == y1) || (xx==yy) || (xx1==yy1))
                {
                    ans = 0;
                    break;
                }
            }
            if(ans==0)
            break;
        }

        countt += ans;
        if(ans){
            int pri[10][10]={0};
            
            for(auto it:s){
                pri[it.F][it.S]=1;
            }
            // for(i=0;i<n;i++){
                // for(j=0;j<n;j++){
                    // cout<<pri[i][j]<<" ";
                // }
                // cout<<endl;
            // }
        }
        return;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            pair<int, int> p;
            p = {i, j};
            if (find(s.begin(),s.end(),p) == s.end())
            {
                s.PB(p);
                meet(r + 1);
                s.erase(s.size()-1+s.begin());
            }
        }
    }
}
void binary_rock()
{
    cin >> n;
    int i, j, k, l;
    meet(0);

    cout<<countt<<endl;
}

signed main()
{
    fastio
        clock_t t1 = clock();

    int t = 1;
    // cin >> t;
    while (t--)
    {
        binary_rock();
    }

    clock_t t2 = clock();
    // cout << "Time-Taken: " << ((t2 - t1) / (double)CLOCKS_PER_SEC) << endl;
    // cout << CLOCKS_PER_SEC << endl;
    return 0;
}