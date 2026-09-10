class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int finish=0;
        vector<vector<int>>adjList(numCourses);
        vector<int> indeg(numCourses,0);
        for(auto& i:prerequisites)
        {
            adjList[i[1]].push_back(i[0]);
            indeg[i[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indeg[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>order;
        while(!q.empty())
        {
            int i=q.front();
            q.pop();
            for(int ne:adjList[i])
            {
                if(--indeg[ne]==0)
                {
                    q.push(ne);
                }
            }
            order.push_back(i);
            finish++;
        }
        return (finish==numCourses)? order : vector<int>();
    }
};
