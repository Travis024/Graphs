#include "Assignment8Graph.h"

using namespace std;

//Adds a vertex with name 'name' to the vertices vector of the graph
void Graph::addVertex(std::string name){

    //Check to see if the vertex already exists in the list
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == name){
            found = true;
            cout<<vertices[i].name<<" already in the graph."<<endl;
        }
    }

    //If not found, create a new vertex and push it onto the vertices vector
    if(!found){
        vertex newVertex;
        newVertex.name = name;
        vertices.push_back(newVertex);
    }
}


//Adds an edge between two vectors with a given weight
void Graph::addEdge(std::string v1, std::string v2, int weight){

    //Check to make sure both vertices exist and aren't the same.
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){

                    //Create a pointer and put it in the list of adjacent vertices
                    adjVertex adjacent;
                    adjacent.v = &vertices[j];
                    adjacent.weight = weight;
                    vertices[i].adj.push_back(adjacent);

                }
            }
        }
    }

}


//A function to display every vertex and the vertices it is adjacent to
void Graph::displayEdges(){

    //Go through every vertex
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].name<<"-->";

        //Go through every adjacent vertex
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout<<vertices[i].adj[j].v -> name;
            if(j != vertices[i].adj.size() - 1){
                cout<<"***";
            }
        }

        cout<<endl;
    }

}

//A function to check if two vertices are adjacent.
//Return 1 if true, 0 if false
int Graph::isAdjacent(std::string v1, std::string v2){

    //First, find the position of the first city passed through
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){

            //then, check it's adjacency list to see if the two vertices are adjacent
            for(int j = 0; j < vertices[i].adj.size(); j++){
                if(vertices[i].adj[j].v -> name == v2){
                    return 1;
                }
            }
        }
    }

    return 0;

}
