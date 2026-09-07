class Solution {
    vector<int>parent;
    int components;
    int find(int x)
    {
        if(parent[x]!=x)
        {
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    void unionSet(int x,int y)
    {
        int rootX=find(x);
        int rootY=find(y);

        if(rootX!=rootY)
        {
            components--;
            parent[rootY]=rootX;
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        components=n;
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        for(auto&e:edges)
        {
            unionSet(e[0],e[1]);
        }
        return components;
    }
};
