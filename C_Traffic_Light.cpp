// OM NAMAY SHIVAYEE
// Author-Ashutosh Gupta
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define int long long
#define ld long double
#define vi vector<int>
#define si set<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define mi map<int, int>
#define pp pop_back
#define all(a) a.begin(), a.end()
#define vb vector<bool>
#define pb(i) push_back(i)
#define sortv(v) sort(v.begin(), v.end())
#define at(i, mp) for (auto i : mp)
#define all(a) a.begin(), a.end()
#define fl(i, a, b) for (int i = a; i < b; i++)
#define fn(a, b, n) for (int i = a; i < b; i = i + n)
#define lt 1000000000
#define e endl;
#define rt return;
const int32_t mod = 1e9 + 7;

bool bin(vi &a, int o, int r, int k)
{
    while (o <= r)
    {
        int m = o + (r - o) / 2;
        if (a[m] < k)
        {
            o = m + 1;
        }
        else if (a[m] > k)
        {
            r = m - 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}

void SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p;
}

// D.S.U start

int find(int i, vector<int> &parent)
{
    if (parent[i] == i)
    {
        return i;
    }
    else
    {
        return parent[i] = find(parent[i], parent);
    }
}

void Union(int x, int y, vector<int> &parent, vector<int> &rank)
{
    int xset = find(x, parent);
    int yset = find(y, parent);
    if (xset != yset)
    {
        if (rank[xset] > rank[yset])
        {
            swap(xset, yset);
        }
        parent[xset] = yset;
        rank[yset] += rank[xset];
    }
    return;
}

// D.S.U finish

// Tree Structure

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool is_prime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int pow(int a, int b)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int lcm(int a, int b)
{
    return a / __gcd(a, b) * b;
}

void en(vi &a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int sum_ele(vi &v)
{
    int s = 0;
    fl(i, 0, v.size())
    {
        s += v[i];
    }
    return s;
}

void sol()
{
    int n;
    char c;
    string s;
    cin >> n >> c;
    cin>>s;
    if(c=='g')
    {
        cout<<0<<e
        rt
    }

    vi cc;
    vi g;
    for(int i=0;i<n;i++)
    {
        if(s[i]==c)
        {
            cc.pb(i);
        }
        else if(s[i]=='g')
        {
            g.push_back(i);
        }
    }

    int ans=0;

    // for(auto i:cc)
    // {
    //     cout<<i<<" ";
    // }
    // cout << e for (auto i : g)
    // {
    //     cout << i << " ";
    // }
    // cout << e

        for (auto i : cc)
    {
        auto itr=lower_bound(g.begin(),g.end(),i)-g.begin();
        int v1=INT_MAX,v2=INT_MAX;
        if(itr>0)
        {
            v1=g[itr-1]-i+n;
        }
        if(itr!=g.size())
        {
            v2=g[itr]-i;
        }
        else
        {
            v2=g[0]-i+n;
        }
        // cout<<v1<<" "<<v2<<" "<<itr<<e

        ans=max(ans,min(v1,v2));


    }

    cout<<ans<<e
    rt
}

signed main()
{
    // You can do it!!.Just Focus,you can and you will.
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        sol();
    }

    return 0;
}