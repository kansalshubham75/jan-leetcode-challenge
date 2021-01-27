#define ll long long
#define s second
ll n,m;
vector<ll> par;
vector<ll> sz;
ll find(ll u){
    return par[u]=par[u]==u?u:find(par[u]);
}
void merge(ll p1,ll p2){
    if(sz[p2]>sz[p1])swap(p1,p2);
    par[p2]=p1;
    sz[p1]+=sz[p2];
}
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        n=heights.size(),m=heights[0].size();
        par.resize(n*m,0);
        sz.resize(n*m,1);
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                sz[(i*m)+j]=1;
                par[(i*m)+j]=(i*m)+j;
            }
        }
        vector<vector<ll>> edges;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                if(j!=m-1){
                    edges.push_back({(i*m)+j,(i*m)+j+1,abs((heights[i][j]*1LL)-heights[i][j+1])});
                }
                if(i!=n-1){
                    edges.push_back({(i*m)+j,(i*m)+j+m,abs((heights[i][j]*1LL)-heights[i+1][j])});
                }
            }
        }
        sort(edges.begin(),edges.end(),[](auto& e1,auto& e2){
            return e1[2]<e2[2];
        });
        ll i=0,k=edges.size();
        while(i<k){
            ll u=edges[i][0],v=edges[i][1],w=edges[i][2];
            ll p1=find(u),p2=find(v);
            if(p1!=p2)merge(p1,p2);
            if(find(0)==find((n*m)-1))return w;
            i++;
        }
        return 0;
    }
};