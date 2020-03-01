// ----------------------------------------------------------------------------
// -                        Open3D: www.open3d.org                            -
// ----------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2018 www.open3d.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// ----------------------------------------------------------------------------

#include <iostream>
#include <memory>
#include <thread>
#include <list>
#include <Open3D/Open3D.h>
#include <vector>
#include <stdio.h>


using namespace open3d;
using namespace std;

	class Graph 
	{ 
	    int V;    // No. of vertices 
	  
	    // Pointer to an array containing adjacency lists 
	    list<int> *adj; 
	  
	    // A function used by DFS 
	    void DFSUtil(int v, bool visited[], int c, int *color); 
	public: 
	    Graph(int V);   // Constructor 
	    void addEdge(int v, int w); 
	    void IdenticallyColoredConnectedComponents(int *color); 
	}; 
	  
	// Method to print connected components in an 
	// undirected graph 
	void Graph::IdenticallyColoredConnectedComponents(int *color) 
	{ 
	    // Mark all the vertices as not visited 
	    bool *visited = new bool[V]; 
	    for(int v = 0; v < V; v++) 
	        visited[v] = false; 
	  	
	    for (int v=0; v<V; v++) 
	    { 
	        if (visited[v] == false) 
	        { 
	            int c=color[v];
	            // print all reachable vertices 
	            // from v 
	            DFSUtil(v, visited, c, color); 
	 			 
	            cout << "\n"; 
	        } 
	    } 
	} 
	  
	void Graph::DFSUtil(int v, bool visited[], int c, int *color) 
	{ 
	    // Mark the current node as visited and print it 
	    visited[v] = true; 
	    cout << v << " "; 
        
        // Iterate through all the vertices adjacent to vertex[v] 

	    list<int>::iterator i; 

	    for(i = adj[v].begin(); i != adj[v].end(); ++i) 
	        if(!visited[*i])
	        	if(c==color[*i]) 
		            DFSUtil(*i, visited, c, color); 
	} 
	  
	Graph::Graph(int V) 
	{ 
	    this->V = V; 
	    adj = new list<int>[V]; 
	} 
	  
	// method to add an undirected edge 
	void Graph::addEdge(int v, int w) 
	{ 
	    adj[v].push_back(w); 
	    adj[w].push_back(v); 
	}

int main(int argc, char *argv[]) {
    
	int p, q, r;
    utility::SetVerbosityLevel(utility::VerbosityLevel::Debug);
    if (argc < 3) {
        return 0;
    }

    
    
    std::string option(argv[1]);
    if (option == "mesh") {
        auto mesh_ptr = std::make_shared<geometry::TriangleMesh>();
        //auto triangle_ptr = std::make_shared<geometry::TriangleMesh::triangles_>();
        if (io::ReadTriangleMesh(argv[2], *mesh_ptr)) {
            utility::LogInfo("Successfully read {}\n", argv[2]);
        } else {
            utility::LogWarning("Failed to read {}\n\n", argv[2]);
            return 1;
        }

        auto triangle_mat=mesh_ptr->triangles_;
        auto mesh_vertices=mesh_ptr->vertices_;
        int vertex_size = mesh_vertices.size();
        auto input_color=mesh_ptr->vertex_colors_;
        int numrows = triangle_mat.size();
        printf("Number of vertices: ");
        cout << vertex_size << endl;
        printf("Number of Triangles: ");
        cout << numrows << endl;
        /*
        printf("Vertex List\n");
        
        for (int i=0; i < vertex_size; i++){
        	for (int j=0; j<3; j++){
        		printf("%f ", mesh_vertices[i][j]);
        	}
        	printf("\n");
        }
		*/
		int vertex_color[vertex_size];
		/*
        for (int i=0; i < vertex_size; i++){
        	for (int j=0; j<3; j++){
        		printf("%d ", int(input_color[i][j]));
        	}
        	printf("\n");
        }
		*/
		// RED==1 BLUE=2 and GREEN =3
        for (int i=0; i<vertex_size; i++){
        	if(input_color[i][0]==1){
        		vertex_color[i]=1;
        	}
        	if(input_color[i][1]==1){
        		vertex_color[i]=2;
        	}
        	if(input_color[i][2]==1){
        		vertex_color[i]=3;
        	}
        }
        /*
        printf("Vertex Color\n");
        for(int i=0; i<vertex_size; i++){
        	printf("%d ",vertex_color[i]);
        }
        /*
        printf("Triangle List\n");
        for (int i=0; i < numrows; i++){
        	for (int j=0; j<3; j++){
        		printf("%d ", triangle_mat[i][j]);
        	}
        	printf("\n");
        }
        */
        Graph g(vertex_size);

        for(int i=0; i<numrows; i++){
        	int j=0;
        	while(j<3){
        		p=triangle_mat[i][j];
        		q=triangle_mat[i][j+1];
        		r=triangle_mat[i][j+2];
        		j=j+3;
        		g.addEdge(p,q);
        		g.addEdge(p,r);
        		g.addEdge(q,r);
        	}
        }
    
        cout << "Following are connected components \n"; 
	    g.IdenticallyColoredConnectedComponents(vertex_color); 

        mesh_ptr->ComputeVertexNormals();
        //visualization::DrawGeometries({mesh_ptr}, "Mesh", 1600, 900);
    }

    return 0;
}
