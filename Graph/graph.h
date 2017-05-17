
#ifndef LIB_GRAPH
#define LIB_GRAPH

#include <iostream>
#include <algorithm>
#include <map>
#include "vertex.h"
#include "compound.h"

namespace Lib
{
	// N - node. W - edge weight.
	template <typename N = int, typename W = unsigned>
	class Graph
	{
	public:

        enum Exceptions {
            NON_EXISTING_VALUE,
            ALREADY_EXIST
        };

		// Default constructor.
		Graph() : m_vertices(), verticesCount(0),
            edgesCount(0)
		{ }

		// A copy constructor.
		/*Graph(const Graph& other)
		{

		}*/

		// Destructor.
		/*~Graph()
		{ }*/

        // Add.
		void addVertex(const N& value);
		void addEdge(const N source, N dest,
					 const W& weight);
        // Remove.
        void removeVertex(const N& value);
        void removeEdge(const N source, N dest);
        
        // Dijkstra's shortest path algorithm.
        size_t DijkstraSAlgorithm(const N source, const N dest);

        void depthFirstSearch() const;


	private:

		std::list< GVertex<N, W> > m_vertices;

		size_t verticesCount;
        size_t edgesCount;
	};



    // Add vertex. If the vertex already
    // exist, then throws an exception:
    // Exception::ALREADY_EXIST
	template<typename N, typename W>
	void Graph<N, W>::addVertex(const N& value)
	{
        auto sourceIter = std::find(m_vertices.begin(),
            m_vertices.end(),
            GVertex<N, W>(value));

        if (sourceIter != m_vertices.end())
        {
            throw Exceptions::ALREADY_EXIST;
        }

		m_vertices.push_back(GVertex<N, W>(value));
		++verticesCount;
	}



    // If source or dest was not found or
    // already exists throw an exception: 
    // Exceptions::NON_EXISTING_VALUE
	template<typename N, typename W>
	void Graph<N, W>::addEdge(const N source, N dest, 
							  const W& weight)
	{
        // Looking for the beginning and the end of the edge.
        auto sourceIter = std::find(m_vertices.begin(),
									 m_vertices.end(),
									 GVertex<N, W>(source));
			
		auto destIter = std::find(m_vertices.begin(),
								   m_vertices.end(),
								   GVertex<N, W>(dest));
			
		if (sourceIter == m_vertices.end() || 
            destIter == m_vertices.end())
		{
            throw Exceptions::NON_EXISTING_VALUE;
		}

		// If edge does not exist, make it.
		(*sourceIter).edges.push_back(GEdge<N, W>(*destIter, weight));
        ++edgesCount;
	}



    // Removes vertex, and all edges associated with it.
    template<typename N, typename W>
    void Graph<N, W>::removeVertex(const N & value)
    {
        // Find vertex.
        auto valueIter = std::find(m_vertices.begin(),
                                    m_vertices.end(),
                                    GVertex<N, W>(value));
        
        if (valueIter != m_vertices.end())
        {
            // Remove vertex.
            m_vertices.remove(*valueIter);
            --verticesCount;

            // Find and remove edges in our graph.
            for (auto &i : m_vertices)
            {
                for (auto &j : i.edges)
                {
                    if (j.direction.node == value)
                    {
                        i.edges.remove(j);
                        --edgesCount;
                    }
                }
            }
        }
    }



    // Removes edge. If source or
    // dest not found throw an exception:
    // Exception::NON_EXISTING_VALUE
    template<typename N, typename W>
    void Graph<N, W>::removeEdge(const N source, N dest)
    {
        // Get edge ptr.
        auto sourceIter = std::find(m_vertices.begin(),
                                    m_vertices.end(),
                                    GVertex<N, W>(source));
        GEdge<N, W>* edgePtr = nullptr;
        for (auto &i : (*sourceIter).edges)
        {
            if (i.direction.node == dest)
            {
                edgePtr = &i;
            }
        }

        if (sourceIter == m_vertices.end() ||
            edgePtr == nullptr)
        {
            throw Exceptions::NON_EXISTING_VALUE;
        }

        // Remove edge.
        (*sourceIter).edges.remove(*edgePtr);
        --edgesCount;
    }



    template<typename N, typename W>
    void Graph<N, W>::depthFirstSearch() const
    {
        //std::list< std::pair<const GVertex<N, W>*, bool> > allVertices;

        //for (const auto &i : m_vertices)
        //{
       //     allVertices.push_back(std::pair<const GVertex<N, W>* bool>(&i, false));
       //}


    }
}

#endif // !LIB_GRAPH

