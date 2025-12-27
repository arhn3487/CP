#pragma GCC optimize("O3")
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

#define ll long long
const ll INFLL = (1LL<<60);

struct Tree {
    int x, y, v, l;
};

static ll cross(const pair<ll,ll> &a,const pair<ll,ll> &b,const pair<ll,ll> &c){
    return (b.first-a.first)*(c.second-a.second)-(c.first-a.first)*(b.second-a.second);
}
static double dist(const pair<ll,ll> &a,const pair<ll,ll> &b){
    double dx=(double)a.first-b.first,dy=(double)a.second-b.second;
    return sqrt(dx*dx+dy*dy);
}

static double hull_perimeter(vector<pair<ll,ll> > pts){
    if(pts.empty()) return 0.0;
    sort(pts.begin(),pts.end());
    pts.erase(unique(pts.begin(),pts.end()),pts.end());
    int n=(int)pts.size();
    if(n==1) return 0.0;
    if(n==2) return 2.0*dist(pts[0],pts[1]);
    vector<pair<ll,ll> > lower, upper;
    for(int i=0;i<n;i++){
        while(lower.size()>=2 && cross(lower[lower.size()-2],lower.back(),pts[i])<=0)
            lower.pop_back();
        lower.push_back(pts[i]);
    }
    for(int i=n-1;i>=0;i--){
        while(upper.size()>=2 && cross(upper[upper.size()-2],upper.back(),pts[i])<=0)
            upper.pop_back();
        upper.push_back(pts[i]);
    }
    lower.pop_back(); upper.pop_back();
    vector<pair<ll,ll> > hull=lower;
    hull.insert(hull.end(),upper.begin(),upper.end());
    double per=0.0;
    for(int i=0;i<(int)hull.size();i++){
        per+=dist(hull[i],hull[(i+1)%hull.size()]);
    }
    return per;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; int tc=0;
    while(cin>>n && n){
        ++tc;
        vector<Tree> t(n);
        for(int i=0;i<n;i++) cin>>t[i].x>>t[i].y>>t[i].v>>t[i].l;

        ll bestCost=INFLL;
        int bestCnt=1000000000;
        vector<int> bestCut;
        double bestExtra=0.0;

        int N=1<<n;
        for(int mask=0;mask<N;mask++){
            ll cost=0,wood=0;
            vector<pair<ll,ll> > remain;
            vector<int> cutIds;
            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    cost+=t[i].v;
                    wood+=t[i].l;
                    cutIds.push_back(i+1);
                }else{
                    remain.push_back(make_pair(t[i].x,t[i].y));
                }
            }
            double need=hull_perimeter(remain);
            if((double)wood+1e-9<need) continue;

            int cnt=(int)cutIds.size();
            bool better=false;
            if(cost<bestCost) better=true;
            else if(cost==bestCost && cnt<bestCnt) better=true;
            else if(cost==bestCost && cnt==bestCnt && cutIds<bestCut) better=true;

            if(better){
                bestCost=cost;
                bestCnt=cnt;
                bestCut=cutIds;
                bestExtra=(double)wood-need;
            }
        }

        cout<<"Forest "<<tc<<"\n";
        cout<<"Cut these trees: ";
        sort(bestCut.begin(),bestCut.end());
        for(int i=0;i<(int)bestCut.size();i++) cout<<bestCut[i]<<" ";
        cout<<"\n";
        cout.setf(ios::fixed); cout<<setprecision(2);
        cout<<"Extra wood: "<<bestExtra+1e-9<<"\n\n";
    }
    return 0;
}
