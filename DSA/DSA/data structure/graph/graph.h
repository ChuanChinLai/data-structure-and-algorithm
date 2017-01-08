#pragma once

#include <list>
#include <general\Assert.h>

class Graph
{
public:
	/*
	Graph(int i_numVertex): m_numVertex(i_numVertex)
	{
		ASSERT(i_numVertex > 0);
		adj = new std::list<int>[m_numVertex];
	}
	~Graph()
	{
		if (adj != nullptr)
		{
			delete[] adj;
			adj = nullptr;
		}
	}
	*/
	Graph(int i_numVertex);
	~Graph();

	void addEdge(int Vertex_1, int Vertex_2);

	void destroy();

	void BFS(int i_Vertex);
	void BFS();

	void DFS(int i_Vertex);
	void DFS();

private:
	int m_numVertex;
	std::list<int> *adj;
};