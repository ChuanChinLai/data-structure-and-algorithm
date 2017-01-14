#include <data structure\graph\graph.h>
#include <algorithm>
#include <queue>
#include <stack>

Graph::Graph(int i_numVertex) : m_numVertex(i_numVertex)
{
	adj = new std::list<int>[m_numVertex];
}

Graph::~Graph()
{
	if (adj != nullptr)
	{
		delete[] adj;
		adj = nullptr;
	}
}

void Graph::addEdge(int Vertex_1, int Vertex_2)
{
	ASSERT(Vertex_1 < m_numVertex);
	ASSERT(Vertex_2 < m_numVertex);
	ASSERT(adj != nullptr);
	
	adj[Vertex_1].push_back(Vertex_2);
}

void Graph::destroy()
{
	Graph::~Graph();
}

void Graph::BFS(int i_Vertex)
{
	ASSERT(adj != nullptr);

	bool* visited = new bool[m_numVertex];
	for (size_t i = 0; i < m_numVertex; i++)
		visited[i] = false;

	std::queue<int> searchQueue;
	searchQueue.push(i_Vertex);
	
	visited[i_Vertex] = true;

	while (!searchQueue.empty())
	{
		int current_vertex = searchQueue.front();
		searchQueue.pop();

		for (std::list<int>::iterator i = adj[current_vertex].begin(); i != adj[current_vertex].end(); i++)
		{
			if (visited[*i] == false)
			{
				searchQueue.push(*i);
				visited[*i] = true;
			}
		}
	}
	delete[] visited;
}

void Graph::DFS(int i_Vertex)
{
	ASSERT(adj != nullptr);

	bool* visited = new bool[m_numVertex];
	for (size_t i = 0; i < m_numVertex; i++)
		visited[i] = false;

	std::stack<int> searchStack;
	searchStack.push(i_Vertex);

	while (!searchStack.empty())
	{
		int current_vertex = searchStack.top();
		searchStack.pop();

		if (visited[current_vertex] == false)
		{
			visited[current_vertex] = true;
		}

		for (std::list<int>::iterator i = adj[current_vertex].begin(); i != adj[current_vertex].end(); i++)
		{
			if (visited[*i] == false)
			{
				searchStack.push(*i);
			}
		}
	}
	delete[] visited;
}
