#include<iostream>
#include<map>
#include<set>
using namespace std;
int disstance = 0;
map<int,int> n_relation;
map<int,set<int>> relation;
map<int,int> my_answer;
map<int,int> duplicate;
int root_it(int pos , int checker , int distac){
    distac++;
    my_answer[pos]  = distac ;
    if(duplicate[pos] != 1){
        for(int x : relation[pos]){
            if(x != checker) {
                root_it(x,pos,distac);
            }
        }
    }
    return 0;
}
int main(){
    int t;
    cin >> t;
    for (int zx = 1 ; zx <= t ; zx++){
        n_relation.clear();
        relation.clear();
        my_answer.clear();
        duplicate.clear();
        int n,x,y;
        cin >> n;

        for(int i = 0 ; i < n ; i++){
            cin >> x >> y;
            n_relation[x]++;
            n_relation[y]++;
            relation[x].insert(y);
            relation[y].insert(x);
        }
        duplicate = n_relation;
        int result[n+1] = {0};
        bool cker = true;
        while(cker){
            bool is_exhaust = true;
            for(int i = 1 ; i <= n ; i++){
                if(n_relation[i] == 1){
                    for(int j = 0 ; j < n ; j++){
                        if(relation[j].find(i) != relation[j].end() && j != i) n_relation[j]--;
                    }
                    n_relation[i] = -1;
                    is_exhaust = false;
                }
            }
            if(is_exhaust) cker = false;
        }
        set<int> m_circle;
        for(int i = 1 ; i <= n ; i++){
            if (n_relation[i] > 1) m_circle.insert(i);
        }
        for(int c : m_circle){
            disstance = 0;
            my_answer[c] = 0;
            for(int x : relation[c]){
                if(m_circle.find(x) == m_circle.end()){
                    root_it(x,c,0);
                }
            }
        }
        cout << "Case #" << zx << ": ";
        for(int i = 1 ; i <= n ; i++){
            cout  << my_answer[i] << " ";
        }
        cout << endl;
    }
}
