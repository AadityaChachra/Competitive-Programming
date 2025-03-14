#include <bits/stdc++.h>
using namespace std;
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define MOD 1000000007
#define INF 1000000000000000000
#define endl '\n'

vector<int> computeLPS(string& pattern)
{
    int m = pattern.length();
    
    vector<int> lps(m);
    lps[0] = 0;
    
    int len = 0;
    
    int j = 1;
    while(j < m)
    {
       if(pattern[j] == pattern[len])
       {
           len++;
           lps[j] = len;
           j++;
       }
       else
       {
           if(len != 0) len = lps[len-1];
           else lps[j++] = 0;
       }
    }
    
    return lps;
}

vector<int> kmp(string& pattern, string& text)
{
    // TC: O(n+m)
    // SC: O(m)
    int n = text.length();
    int m = pattern.length();
    
    // lps[i] stores the length of longest equal proper prefix and suffix till index 'i'
    vector<int> lps = computeLPS(pattern);
    
    vector<int> indices;
    
    int i = 0, j = 0;
    while(i < n)
    {
        if(text[i] == pattern[j]) i++, j++;
        if(j == m)
        {
            indices.push_back(i-m);
            j = lps[j-1];
        }
        else
        {
            if(text[i] != pattern[j])
            {
                if(j != 0) j = lps[j-1];
                else i++;
            }
        }
    }
    
    return indices;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    string text, pattern;
    cin >> text >> pattern;

    vector<int> indices = kmp(pattern, text);
    for(auto& idx: indices) cout << idx << " ";
    cout << endl;
}
 
int main() {
    fastio();
    //auto begin = std::chrono::high_resolution_clock::now();
    /*--------------------------------------------X--------------------------------------------*/
 
    int tt;
    cin >> tt;
    for(int t = 1; t <= tt; t++)
    {
        //cout << "Case #" << t << ": ";
        solve();
    }
 
    /*--------------------------------------------X--------------------------------------------*/
    //auto end = std::chrono::high_resolution_clock::now();
    //auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    //cout << "Time measured: " << setprecision(3) << fixed << (elapsed.count() * 1e-9) << "seconds" << endl;
 
    return 0;
}