class Solution {
    bool checkCycle(int n,vector<vector<int>>&adjList,vector<bool>&visited,vector<bool>&inPath)
    {
        visited[n]=true;
        inPath[n]=true;

        for(int ne:adjList[n])
        {
            if(!visited[ne])
            {
                if(checkCycle(ne,adjList,visited,inPath))
                {
                    return true;
                }
            }
            else if(inPath[ne])
            {
                return true;
            }
        }
        inPath[n]=false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adjList(numCourses);
        for(auto p:prerequisites)
        {
            adjList[p[1]].push_back(p[0]);
        }
        vector<bool>visited(numCourses);
        vector<bool>inPath(numCourses);

        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                if(checkCycle(i,adjList,visited,inPath))
                    return false;
            }
        }
        return true;
    }
};
