#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
class graph{
    private:
    vector<string> nodes;
    int **graph1;
    int nodecount;
    public:

    graph(int maxnodes){
        nodecount = 0;
        graph1 = new int*[maxnodes];
        for(int i=0;i<maxnodes;i++){
            graph1[i] = new int[maxnodes];
        }
    }
    void addnode(const string& v){
        if(find(nodes.begin(),nodes.end(),v)!= nodes.end()){
            cout<< v<< "is already present"<<endl;
        }else{
            nodes.push_back(v);
            nodecount++;
        }
    }
    void addedge(const string& v1,const string& v2){
        int index1 = getindex(v1);
        int index2 = getindex(v2);
        if(index1 == -1 || index2 == -1){
            cout<<"one or both vertices";
        }else
        {
            graph1[index1][index2]=1;
            graph1[index2][index1]=1;
        }
        
    }
    void addedgeweight(const string& v1,const string& v2,int weight){
        int index1= getindex(v1);
        int index2= getindex(v2);
        if (index1 == -1 || index2 ==-1){
            cout<<" one or both";
        }else{
            graph1[index1][index2] =weight;
            graph1[index2][index1] =weight;
        }
        
    }
    void printgraph1(){
        for (int i = 0; i < nodecount; i++){
            for (int j = 0;j< nodecount; j++){
                graph1[i][j]=0;
            }
        }
    }
    void printgraph(){
        cout<< "\t";
        for(int i=0;i<nodecount;i++){
            cout<<nodes[i]<<"\t";
        }
        cout<<"\n";
        for (int i = 0; i < nodecount; i++)
        {
            cout<<nodes[i]<<" : ";
            for (int j = 0;j< nodecount; j++)
            {
                cout<<"\t"<<graph1[i][j];
            }
            cout<<endl;
        }
        
    }
    int getindex(const string& v){
        vector<string>::iterator it = find(nodes.begin(),nodes.end(),v);
        if(it != nodes.end()){
            return distance(nodes.begin(),it);
        }
        return -1;
    }
    void deletenode(const string& v){
        int index =getindex(v);
        if(index==-1){
            cout<<v << "is not present"<<endl;
        }else
        {
            nodes.erase(nodes.begin() + index);
            delete[] graph1[index];
            for (int i = 0; i < nodecount; i++)
            {
                graph1[i]=graph1[i+1];
            }
            nodecount--;
            
        }
        
    }
};
int main(){
    graph obj(10);
    int choice;
    string v1,v2;
    int weight;
    while (true)
    {
        cout<<" 1 add a node"<<endl;
        cout<<" 2 add a edge"<<endl;
        cout<<" 3 add a weighted edge"<<endl;
        cout<<" 4 print graph"<<endl;
        cout<<" 5 print graph with 0"<<endl;
        cout<<" 6 delete a node"<<endl;
        cout<<" 0 exit"<<endl;
        cout<<" Enter your choice"<<endl;
        cin>>choice;
        switch(choice){
            case 1 :
                    cout<<"Enter the value of the vertex:";
                    cin>>v1;
                    obj.addnode(v1);
                    break;
            case 2 :
                    cout<<"Enter the value of the vertex:";
                    cin>>v1;
                    cout<<"Enter the value of the vertex2:";
                    cin>>v2;
                    obj.addedge(v1,v2);
                    break;
            case 3 :
                    cout<<"Enter the value of the vertex:";
                    cin>>v1;
                    cout<<"Enter the value of the vertex2:";
                    cin>>v2;
                    cout<<"Enter the value of the weight:";
                    cin>>weight;
                    obj.addedgeweight(v1,v2,weight);
                    break;
            case 4:
                    obj.printgraph();
                    break;
            case 5: obj.printgraph1(); break;
            case 6:
                    cout<<" enter node/vertex to delete: ";
                    cin>>v1;
                    obj.deletenode(v1);
                    break;
            default :
                    return 0;
        }
    }
}