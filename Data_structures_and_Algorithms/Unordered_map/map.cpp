#include<bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<string, int> umap;
    umap.insert({"Alice", 25});
    umap.insert({"Bob", 30});
    umap.insert({"Charlie", 35});
    auto a = umap.insert({"Charlie", 325});
    cout << a.second << endl;
    for(const auto &x : umap)
    {
        cout << x.first << " " << x.second << endl;
    }
    //use iterator
    for(auto it = umap.begin(); it != umap.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
    for(unordered_map<string,int>::iterator it = umap.begin(); it != umap.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}