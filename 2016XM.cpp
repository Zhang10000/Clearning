class Solution {
public:
    /**
     * 返回git树上两点的最近分割点
     * 
     * @param matrix 接邻矩阵，表示git树，matrix[i][j] == '1' 当且仅当git树中第i个和第j个节点有连接，节点0为git树的跟节点
     * @param indexA 节点A的index
     * @param indexB 节点B的index
     * @return 整型
     */
    int getSplitNode(vector<string> matrix, int indexA, int indexB) {
        int n =matrix.size();
        vector<int> father(n,-1);
        father[0]=0;//构造父节点数组，初始假设0为根节点
        int no_parent = n - 1;
        for (int i = 0; i < n; ++i)
        {
            if (matrix[0][i] == '1')
            {
                --no_parent;
                father[i] = 0;
            }
        }
        while(no_parent>0)
        {
             for (int i = 1; i < n; ++i)
             {
                 if( father[i] == -1 )
                 {
                     for (int j = 0; j < n; ++j)
                    {
                        if (matrix[i][j] == '1' && father[j] != -1)
                        {
                            father[i] = j;
                            --no_parent;
                            break;
                        }
                    }
                 }
             }
        }
        vector<bool> visited(n, false);
        visited[indexA] = true;
        while (indexA > 0)
        {
            indexA = father[indexA];
            visited[indexA] = true;
        }
        if (visited[indexB]) return indexB;
        while (indexB > 0)
        {
            indexB = father[indexB];
            if (visited[indexB]) return indexB;
        }
        return 0;
    }
};
