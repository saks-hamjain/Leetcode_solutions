class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) 
    {
        int n= buildings.size();
        vector<pair<int,int>> events;
        for(auto &b : buildings)
        {
            events.emplace_back(b[0],-b[2]);
            events.emplace_back(b[1],b[2]);
        }
        sort(events.begin(),events.end());

        multiset<int> mt = {0};
        int prev_height =0;
        vector<vector<int>> res;
        for(auto &x : events)
        {
            if(x.second < 0)
            mt.insert(-x.second);
            else
            mt.erase(mt.find(x.second));

            int curr = *mt.rbegin();
            if(curr != prev_height)
            {
              res.emplace_back(vector<int>{x.first,curr});
              prev_height = curr;
            }
        }
        return res;
    }
};