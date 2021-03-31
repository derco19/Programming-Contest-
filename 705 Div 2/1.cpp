int getPowerCouple2021(int friends_nodes, int friends_edges, vector<int> friends_from, vector<int> friends_to, vector<int> friends_weight) {
    vector <int> inter[friends_nodes+1];
    for(int i=0;i<friends_edges;i++)
    {
        inter[friends_from[i]-1].push_back(friends_weight[i]);
        inter[friends_to[i]-1].push_back(friends_weight[i]);
    }
    for(int i=0;i<friends_nodes;i++)
    {
        for(int j=i+1;j<friends_nodes;j++)
        {
            for(int k=0;k<inter[i].size();k++)
            {
                
            }
        }
    }

}
