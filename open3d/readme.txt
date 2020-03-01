1. Algorithm Used.
I have used DFS (Depth First Search Algorithm). This algorithm will give me all the connected components of graph if called iteratively. I modified this algorithm for the solution. 
	(I). Python Solution
		> For python solution I have created a Graph class where I have allocated color to each of the vertex which I retrived from the "test_mesh.ply" file.
		> Through the triangle I got to know whoch node is connected. I have created an addEdgefunction to make connection between each of the nodes/vertex.
		> Once I have all the connection and color allocated I called identically_colored_connected_components function. 
		>This function will call DFSUtil iteratively untill all the nodes are visited.
		> DFSUtil is a recursive function which will look for all the nodes who are connected and have same color. First I am checking whether they are connected/ adjacent and after that only I am looking if they have same color.
		
		> Run Time = O(V+E). 
		> Space Complexity = Extra O(V) to store the color. One stack will also be employed for recursive calls. 

	(II). C++ Solution
			> Same as python solution I have used the same algorithm to implement C++ solution as well. 

2. Python Solution:
	(I) I imorted open3d module directly and created a solution hence no requirement of build for this. 
	(II) I used python3 to develop the solution. I have created the output file as required in the same format
3. C++ Solution 
	(I) I have cloned the git repository and followed all the steps. In my system I created a folder named as open3d. There I placed my solution.cpp and created a build. I have made changes in CMakeLists.txt to incroporate those changes. 
	Build Creation: 
		(i) navigate to open3d/build
		(ii) make -j 
	Execution:	
		(i) ./solution mesh test_mesh.ply

	(II) In order to give other file as input hust pass different file to during execution it will generate the desired output. 





