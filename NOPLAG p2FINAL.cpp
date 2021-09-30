#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> >adj_mat[100];
unordered_map<int,int>short_ans;
int shorter_dist(int newb,int expt);

int main(){
    int members,member_id,edges,x,y,total_dist,newb,expt;
    
    cin >> members;
    
    for(int i=0;i<members;++i){
        cin >> member_id;
        short_ans[member_id]=INT_MAX;
    }
    
    cin >> edges;
    
    for(int i=0;i<edges;++i)
    {
        cin >> x >> y >> total_dist;
        adj_mat[x].push_back({y,total_dist});
    }
    
    cin >> newb >> expt;
    shorter_dist(newb,expt);
   
    return 0;
}

int shorter_dist(int newb,int expt){
 set<pair<int,int>> to_check;
    short_ans[newb]=0;
    to_check.insert({0,newb});
    while(!to_check.empty())
    {
        pair<int,int>flag=*(to_check.begin());
        to_check.erase(to_check.begin());
        int node_first = flag.second;
        for(auto j = adj_mat[node_first].begin(); j!= adj_mat[node_first].end();j++){
            int node2 = (*j).first;
            int dis = (*j).second;
            if(short_ans[node2]>short_ans[node_first]+dis){
                if(short_ans[node2]!=INT_MAX)
                to_check.erase(to_check.find({short_ans[node2],node2}));
                short_ans[node2]=short_ans[node_first]+dis;
                to_check.insert({short_ans[node2],node2});
            }
        }
    }
    if(short_ans[expt])
    cout<<short_ans[expt]<<endl;
    return 0;
}
