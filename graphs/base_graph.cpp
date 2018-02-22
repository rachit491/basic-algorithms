#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<functional>
#include<cstdlib>

using namespace std;

struct vertex;

struct edge
{
    vertex *dest;
    double cost;
    edge(vertex *a=NULL, double b=0)
    {
        dest=a;
        cost=b;
    }
};

struct vertex
{
    string name;
    vector<edge> adj;
    vertex(string s)
    {
        name=s;
    }
};

class graph
{
    public:
        typedef map<string, vertex *,less<string> > vmap;
        vmap work;
        void addvertex(const string&);
        void viewvertex();
        void addedge(const string& from, const string& to, double cost);
        void viewcostofedge(const string &from, const string &to);
};

void graph::addvertex(const string &name)
{
    vmap::iterator itr=work.begin();
    itr=work.find(name);
    if(itr==work.end())
    {
        vertex *v;
        v= new vertex(name);
        work[name]=v;
        return;
    }
        cout<<"\nVertex already exists!";

}

void graph::viewvertex()
{
    vmap::iterator itr=work.begin();
    for(;itr!=work.end();itr++)
    {
        cout<<"\n"<<itr->first;
    }
}


void graph::addedge(const string& from, const string& to, double cost)
{
    vertex *f=(work.find(from)->second);
    vertex *t=(work.find(to)->second);
    edge added(t,cost);
    f->adj.push_back(added);
}


void graph::viewcostofedge(const string &from, const string &to)
{
    vmap::iterator itr=work.find(from);
    vector<edge> v=(itr->second)->adj;
    vector<edge>::iterator itr1=v.begin();
    vertex *p;
    for(;itr1!=v.end();itr1++)
    {
        if(((*itr1).dest)->name==to)
            cout<<"\nThe cost is:-"<<(*itr1).cost;
    }
}

int main()
{
    int ch;

    graph g;
    string name;
    string string1,string2;
    double cost;
    do
    {
        cout<<"\n\n\n1.Add Vertex\n2.View Vertex\n3.Add Edge\n4.View Cost\n5.Exit\nEnter choice:-\n\n\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"\nEnter the name of the vertex:-";
                cin>>name;
                g.addvertex(name);
                break;
            case 2:
                g.viewvertex();
                break;
            case 3:

                cout<<"\nEnter the spot:-";
                cin>>string1;
                cout<<"\nEnter the destination!";
                cin>>string2;
                cout<<"\nEnter cost:-";
                cin>>cost;
                g.addedge(string1,string2,cost);
                break;
            case 4:

                cout<<"\nEnter the spot:-";
                cin>>string1;
                cout<<"\nEnter the destination!";
                cin>>string2;
                g.viewcostofedge(string1,string2);
                break;
            case 5:
                exit(0);
            default:
                cout<<"\nWrong Choice!";
        }
    }while(1);
}