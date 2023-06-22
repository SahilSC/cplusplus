#include <iostream>
#include <vector>
//#include "Account.h"

using namespace std;

vector<vector<int>> adj;
vector<long> bales;
vector<vector<long>> ans;
vector<vector<long>> ans2;
vector<long> subtree;
vector<bool> visited;
vector<bool> visiteda;

void dfs(int f){
    visited[f]=true;
    subtree[f] = bales[f];
    for (int o : adj[f]){
        if (!visited[o]){
            dfs(o);
            subtree[f] += subtree[o];
        }
    }
}

void move_haybales(int f){
    visiteda[f] = true;
    for (int o: adj[f]) {
        if(!visiteda[o]){
            move_haybales(o);
            if (subtree[o] > 0) {
                ans.push_back(vector<long>{o, f, subtree[o]});
            }
            if (subtree[o] < 0) {
                ans.insert(ans.begin(),(vector<long>{f, o, -subtree[o]}));
            }
            subtree[o]=0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin >> a;
    adj.resize(a, vector<int>{});
    bales.resize(a);
    subtree.resize(a);
    visited.resize(a, false);
    visiteda.resize(a, false);
    long each = 0;
    for(int i = 0; i < a; i++){
        cin >> bales[i];
        each += bales[i];
    }
    each /= a;
    for (int i = 0; i < a; i++) {
        bales[i] -= each;
    }
    for (int i = 0; i < a - 1; i++) {
        int c, b;
        cin >> c >> b;
        adj[c-1].push_back(b-1);
        adj[b-1].push_back(c-1);
    }
    dfs(0);
//    dfstreep(0);
//    dfstreen(0);
    move_haybales(0);
    cout << ans.size() +ans2.size()<< endl;
    for (vector<long> t: ans) {
        for (int i = 0; i < t.size() - 1; i++) {
            cout << t[i]+1 << " ";
        }
        cout << t[t.size()-1] << endl;
    }
    for (vector<long> t: ans2) {
        for (int i = 0; i < t.size() - 1; i++) {
            cout << t[i]+1 << " ";
        }
        cout << t[t.size()-1] << endl;
    }
    return 0;
}