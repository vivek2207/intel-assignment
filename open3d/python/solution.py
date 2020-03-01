# imported 2 library numpy and open3d 

import numpy as np
import open3d as o3d
import sys

#created a class named as graph, passed defined different function in that 
# vertex and vertex color as parameter for graph creation.


class Graph: 
	
	def __init__(self,V, C): 
		self.V = V
		self.color = C
		self.adj = [[] for i in range(V)] 

	# modified DFSUtil to find the connectedcomponents with same color 
	# recursive function untill adjacent of V is empty. 
	def DFSUtil(self, temp, v, color, visited): 

		# will be marked true when visited
		visited[v] = True
		# appending that vertex in array after visiting.
		# This array will be returned when this function will complete execution

		temp.append(v) 

		for i in self.adj[v]: 
			#checking if the visited is false for the adjacent vertex
			if visited[i] == False: #if true then
				#checking if the color is also same to the passed color in the parameter
				if color == self.color[i]: # if true then callinf modified DFS function again
					temp = self.DFSUtil(temp, i, color, visited) 
		return temp # return the array 

		#creating the adjacency matrix graph

	def addEdge(self, v, w): 
		self.adj[v].append(w) 
		self.adj[w].append(v) 

	# function to find out all the colored components

	def identically_colored_connected_components(self): 
		visited = [] 
		cc = [] 
		# setting all the visited[vertex]==false (only one time execution)
		for i in range(self.V): 
			visited.append(False)
		# this will lopp run for all the vertices 
		for v in range(self.V): 
			if visited[v] == False: 
				temp = []
				color = self.color[v]
				# function call will happen only when vertex is not visited. 
				cc.append(self.DFSUtil(temp, v, color, visited)) 
		return cc  # returning 2d array for each of the connected components

if __name__=="__main__": 
	
	#reading the file from the same directory where this code is placed.
	input_file = sys.argv[1]

	mesh = o3d.io.read_triangle_mesh(input_file)
	# details of mesh such as number of vertices and triangles 
	print(mesh)
	
	# finding the vertices in input_file
	vertices= np.asarray(mesh.vertices)
	
	# finding the vertices color in input_file [0 0 0]
	input_color=np.asarray(mesh.vertex_colors)
	
	# finding the vertices of triangle [v1 v2 v3] 
	input_mat = np.asarray(mesh.triangles)
	
	# number of triangles in the input_file
	numrows = len(input_mat)
	
	# number of vertices in the input_file
	vertex=len(vertices)

	# initializing vertex color for each vertex as None

	# for the sake of it I am considering folllowing format to allocate color
	# [1. 0 0] is RED
	# [1. 0 0] is BLUE
	# [1. 0 0] is GREEN
	vertex_color = [None]* vertex
	for i in range(0,vertex):
		if input_color[i][0]==1.:
			vertex_color[i]='RED' 
		if input_color[i][1]==1.:
			vertex_color[i]='BLUE'
		if input_color[i][2]==1.:
			vertex_color[i]='GREEN'

	# passing vertex size and vertex color to create graph
			
	g = Graph(vertex, vertex_color);
	for i in range(0,numrows):
		j=0
		while j<3:
			p=input_mat[i][j]
			q=input_mat[i][j+1]
			r=input_mat[i][j+2]
			g.addEdge(p, q) 
			g.addEdge(p, r) 
			g.addEdge(q, r) 
			j=j+3
	
	#opening a file to write the results
	output = open('result.txt', 'wb')

	#calling function to find the identically colored components
	cc = g.identically_colored_connected_components() 
	print("Total number of identical color Connceted components: ")
	print(len(cc))
	print("Following are connected components")
	if (len(cc)) > 0: # checking length
		for i in range(0, len(cc)):  
		#sorting each row so that data can be pushed in the desired format	
			cc[i].sort()
			print(cc[i])
	# saving data into the file
		with open("result.txt", "w") as f:
			f.write("'''")
			f.write("\n")
			for x in range(0, len(cc)):
				for y in range(0, len(cc[x])):
					f.write(str(cc[x][y]))
					f.write(" ")
				f.write("\n")
			f.write("'''")	

	if (len(cc)) == 0:
		with open("result.txt", "w") as f:
			f.write("'''")
			f.write("\n")
			f.write("'''")	
