#include <iostream>
#include <vector>
#include <string>

void dfstreep(int f);

void dfstreen(int f);
//#include "Account.h"

using namespace std;

int n;
vector<vector<int>> adj;
vector<long> bales;
vector<vector<long>> ans;
vector<vector<long>> ans2;
vector<long> subtree;
vector<bool> visited;
vector<bool> visitedt;
vector<bool> visitedn;

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

void dfstreep(int f){
    visitedt[f] = true;
    for (int o: adj[f]) {
        if(!visitedt[o]){
            dfstreep(o);
            if (subtree[o] > 0) {
                ans.push_back(vector<long>{o, f, subtree[o]});
                subtree[o] = 0;
            }
        }
    }
}

void dfstreen(int f){
    visitedn[f] = true;
    for (int o: adj[f]) {
        if(!visitedn[o]){
            dfstreen(o);
            if (subtree[o] < 0) {
                ans2.insert(ans2.begin(),(vector<long>{f, o, -subtree[o]}));
                subtree[o] = 0;
            }
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
    visitedt.resize(a, false);
    visitedn.resize(a, false);
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
    dfstreep(0);
    dfstreen(0);
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