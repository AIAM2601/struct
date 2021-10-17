#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

class Graph
{
    int V; 
    map<pair<string,string>,int> city ;
    vector<string> city1;
    vector<string> city2;
    public:
    Graph(int start_V)
    {
        V = start_V;
    }
    void addEdge(string start,string end,int wt);
    void display();
};
void Graph::addEdge(string start,string end,int wt)
{   
   city[make_pair(start,end)] = wt;
}
void Graph::display()
{   
    int flag=0;
    for(auto it:city)
    {
        city1.push_back(it.first.first);
        city2.push_back(it.first.second);
    }

    sort(city1.begin(), city1.end()); 
    auto last = unique(city1.begin(), city1.end());
    city1.erase(last, city1.end());

    sort(city2.begin(), city2.end()); 
    auto last2 = unique(city2.begin(), city2.end());
    city2.erase(last2, city2.end());

    for(auto col:city2)
    {
        cout<<"\t"<<col;
    }
    cout<<"\n";

    for(auto row:city1)
    {
    int flag =0;   //for printing row for once 
    for(auto col:city2)
    {
        if (!flag)
            cout<<row;
        cout<<"\t"<<city[make_pair(row,col)];
        flag = 1;
    }

    cout<<"\n";
    }

}
int main()
{
    Graph g(2);

    // g.addEdge("A","B",1);
    // g.addEdge("C","A",1);
    // g.addEdge("D","E",1);
    // g.addEdge("E","A",1);
    // g.addEdge("D","B",1);
    // g.addEdge("D","L",1);
    // g.addEdge("W","L",1);

    g.addEdge("SJ", "L", 1);
    g.addEdge("SJ", "C", 1);
    g.addEdge("SJ", "P", 1);
    g.addEdge("SJ", "G", 1);
    g.addEdge("SJ", "H", 1);
    g.addEdge("SJ", "C", 1);
    g.addEdge("G", "A", 1);
    g.addEdge("H", "A", 1);

    g.display();
    return 0;
}