#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <bits/stdc++.h>
int checkmain = -1;
using namespace std;

class edge{

public:

int dest_vertex_id;
int weight;

edge()
{
    dest_vertex_id = -1;
    weight = 0;
}

edge (int dv, int wt)
{dest_vertex_id = dv;
weight = wt;
}
void set_dest_vertex_id(int dvi){dest_vertex_id = dvi;}
void set_weight(int w){weight = w;}

int get_dest_vertex_id(){return dest_vertex_id;}
int get_weight(){return weight;}

};

class vertex{

public:

int vertex_id;
bool fire_val;

list<edge> edgelist;

vertex(){
vertex_id = 0;
fire_val = false;
}

void set_vertex_id(int v){vertex_id = v;}
void set_fire_val(bool fv){fire_val = fv;}

int get_vertex_id(){return vertex_id;}
bool get_fire_val(){return fire_val;}

list <edge> getedgelist()
{
    return edgelist;
}

void print_edge_list()
{
    cout<<"[";
    for( auto it = edgelist.begin(); it !=  edgelist.end(); it++)
    {
        cout<<it->get_dest_vertex_id()<<"("<<it->get_weight()<<") -->";
    }
    cout<<"]";
    cout<<endl;
}
};

class graph{

public:
vector <vertex> mygraph;


void addvertex(vertex verr)
{
mygraph.push_back(verr);
}

void addedge(int fv, int tv, int w)
{
    for (int i = 0; i < mygraph.size(); i++)
        {
        if(mygraph.at(i).get_vertex_id() == fv)
            {
            edge e(tv, w);
            mygraph.at(i).edgelist.push_back(e);
            }
        else
            {
                if (mygraph.at(i).get_vertex_id() == tv)
            {
             edge e(fv,w);
             mygraph.at(i).edgelist.push_back(e);
            }
            }
        }
}


 void deleteEdgeByID(int fromVertex, int toVertex) {
      for (int i = 0; i < mygraph.size(); i++) {
        if (mygraph.at(i).get_vertex_id() == fromVertex) {
          for (auto it = mygraph.at(i).edgelist.begin(); it != mygraph.at(i).edgelist.end(); it++) {
            if (it -> get_dest_vertex_id() == toVertex) {
              mygraph.at(i).edgelist.erase(it);
              break;
            }
          }


        if (mygraph.at(i).get_vertex_id() == toVertex) {

          for (auto it = mygraph.at(i).edgelist.begin(); it != mygraph.at(i).edgelist.end(); it++) {
            if (it -> get_dest_vertex_id() == fromVertex) {
              mygraph.at(i).edgelist.erase(it);

              break;
            }
          }
        }
      }
    }
  }


void deleteVertexByID(int vid) {
    int vIndex = 0;
    for (int i = 0; i < mygraph.size(); i++) {
      if (mygraph.at(i).get_vertex_id() == vid) {
        vIndex = i;
      }
    }
    for (int i = 0; i < mygraph.size(); i++) {
      for (auto it = mygraph.at(i).edgelist.begin(); it != mygraph.at(i).edgelist.end(); it++) {
        if (it ->get_dest_vertex_id() == vid) {
          mygraph.at(i).edgelist.erase(it);
          break;
        }
      }
        mygraph.erase(mygraph.begin() + vIndex);
    }
}

void print_graph()
{
    for(int i = 0; i<mygraph.size(); i++)
    {
        vertex temp;
        temp = mygraph.at(i);
        cout<<temp.get_vertex_id()<<" "<< temp.get_fire_val()<<"---->";
        temp.print_edge_list();
       cout<<endl;
    }

}


void setfire(int sid)
{

vector <int> edstore;
for (auto it: mygraph[sid-1].getedgelist()){
    edstore.push_back(it.get_dest_vertex_id());
}
for(int x = 0; x<edstore.size(); x++)
    {

        int y = edstore[x];
deleteEdgeByID(sid,y);
deleteEdgeByID(y,sid);
    }

}
};



class sol {
    public:

vector<int> dijkstra(int V, graph g, int S, int dv)
    {

        // Create a priority queue for storing the nodes as a pair {dist,node}
        // where dist is the distance from source to the node.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Initialising distTo list with a large number to
        // indicate the nodes are unvisited initially.
        // This list contains distance from source to the nodes.
        vector<int> distTo(V, INT_MAX);
        vector <int> parent(V+1);
        for (int i = 0;  i<= V; i++){parent[i] =i;}
            parent [0] =300;

        // Source initialised with dist=0.
        distTo[S] = 0;
        pq.push({0, S});

        // Now, pop the minimum distance node first from the min-heap
        // and traverse for all its adjacent nodes.

        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
              //--visited[i]= node;
            // Check for all adjacent nodes of the popped out
            // element whether the prev dist is larger than current or not.
            for (auto it : g.mygraph[node-1].getedgelist())

            {
                int v = it.dest_vertex_id;
                int w = it.weight;
                if (dis + w < distTo[v])
                {
                    distTo[v] = dis + w;

                    // If current distance is smaller,
                    // push it into the queue.

                    pq.push({dis + w, v});
                    parent[v] = node;
                }
            }
        }
        // Return the list containing shortest distances
        // from source to all the nodes.
        vector<int>path;
        int mynode  = dv;

        while (parent[mynode] != mynode)
        {path.push_back(mynode);
            mynode= parent[mynode];
        }
        path.push_back(S);

        reverse(path.begin(), path.end());
        if(checkmain == 100){
        return path;}
        else {return distTo;}
    }
};



int main(){

graph g1;
vertex v1;
vertex v2;
vertex v3;
vertex v4;
vertex v5;
vertex v6;
vertex v7;
vertex v8;
vertex v9;
vertex v10;
vertex v11;
vertex v12;
vertex v13;
vertex v14;
vertex v15;
vertex v16;
vertex v17;
vertex v18;
vertex v19;
vertex v20;
vertex v21;

v1.set_vertex_id(1);
v2.set_vertex_id(2);
v3.set_vertex_id(3);
v4.set_vertex_id(4);
v5.set_vertex_id(5);
v6.set_vertex_id(6);
v7.set_vertex_id(7);
v8.set_vertex_id(8);
v9.set_vertex_id(9);
v10.set_vertex_id(10);
v11.set_vertex_id(11);
v12.set_vertex_id(12);
v13.set_vertex_id(13);
v14.set_vertex_id(14);
v15.set_vertex_id(15);
v16.set_vertex_id(16);
v17.set_vertex_id(17);
v18.set_vertex_id(18);
v19.set_vertex_id(19);
v20.set_vertex_id(20);
v21.set_vertex_id(21);

g1.addvertex(v1);
g1.addvertex(v2);
g1.addvertex(v3);
g1.addvertex(v4);
g1.addvertex(v5);
g1.addvertex(v6);
g1.addvertex(v7);
g1.addvertex(v8);
g1.addvertex(v9);
g1.addvertex(v10);
g1.addvertex(v11);
g1.addvertex(v12);
g1.addvertex(v13);
g1.addvertex(v14);
g1.addvertex(v15);
g1.addvertex(v16);
g1.addvertex(v17);
g1.addvertex(v18);
g1.addvertex(v19);
g1.addvertex(v20);
g1.addvertex(v21);

g1.addedge(1,6,2);//1
g1.addedge(1,5,5);//2
g1.addedge(1,14,3);//3
g1.addedge(1,11,2);//4
g1.addedge(6,15,6);//5
g1.addedge(14,15,2);//6
g1.addedge(14,3,3);//7
g1.addedge(14,4,4);//8
g1.addedge(4,15,3);//9
g1.addedge(4,8,10);//10
g1.addedge(3,20,2);//11
g1.addedge(3,2,2);//12
g1.addedge(3,11,3);//13
g1.addedge(11,2,1);//14
g1.addedge(5,12,6);//15
g1.addedge(5,2,3);//16
g1.addedge(12,2,5);//17
g1.addedge(8,2,4);//18
g1.addedge(8,18,5);//19
g1.addedge(18,12,3);//20
g1.addedge(18,7,4);//21
g1.addedge(7,16,3);//22
g1.addedge(21,16,2);//23
g1.addedge(7,21,5);//24
g1.addedge(8,7,4);//25
g1.addedge(20,21,3);//26
g1.addedge(20,9,2);//27
g1.addedge(9,21,3);//28
g1.addedge(9,4,4);//29
g1.addedge(9,13,6);//30
g1.addedge(13,19,4);//32
g1.addedge(9,19,9);//33
g1.addedge(19,17,6);//34
g1.addedge(9,17,5);//35
g1.addedge(21,17,4);//36
g1.addedge(13,4,5);//37
g1.addedge(16,17,5);//38
g1.addedge(16,10,9);//39
g1.addedge(17,10,4);//40


sol obj;
g1.print_graph();


int o1 =0;
int o2 = 0;
int o3 =0;

bool c1 = 0, c2 = 0, c3 = 0;
do{
c1 = c2 = c3 = 0;
cout<<"Please enter the three offices on fire"<<endl;
cin>>o1;
cin>>o2;
cin>>o3;

if (o1 == 10 || o1 == 15 || o1 == 5){
c1 = 1;
}
if (o2 == 10 || o2 == 15 || o2 == 5){
c2 = 1;12
}
if (o3 == 10 || o3 == 15 || o3 == 5){
c3 = 1;
}

if (c1 == 1 || c2 == 1 || c3 == 1){
cout <<endl<< "Exit cannot be on fire. Please try again."<<endl<<endl;
}
}while(c1 == 1 || c2 == 1 || c3 == 1);



g1.setfire(o1);
g1.setfire(o2);
g1.setfire(o3);





int ul;
cout<<"Please enter user location."<<endl;
cin>>ul;

int r5 = obj.dijkstra(22, g1, ul, 5)[5];
int r10 = obj.dijkstra(22, g1, ul, 10)[10];
int r15 = obj.dijkstra(22, g1, ul, 15)[15];

checkmain = 100;


int rf = r5;
if (r10 < r5){
        if(r10<r15){rf = r10;}}
else if (r15 < r10){
        if(r15<r5){rf = r15;}
}


int fin = 0;

if(rf == r5){fin =5;}
if(rf == r10){fin =10;}
if(rf == r15){fin =15;}

int s = -1;
int i = 0;

while(s != fin){
 s = obj.dijkstra(22,g1,ul,fin)[i];
 i++;
cout<<s<< " ---> ";
}
cout<<"exit";
cout<<endl<<endl;


    return 0;
}

