
#ifndef LIB_GRAPH_VERTEX
#define LIB_GRAPH_VERTEX

#include <list>
#include "edge.h"

namespace Lib
{
	template <typename N, typename W>
	struct GVertex
	{
		N node;
		std::list<GEdge<N, W>> edges;

		// Default constructor.
		GVertex() : node(), edges()
		{ }

		// A constructor with one argument.
		GVertex(const N& otherNode) : 
			node(otherNode), edges()
		{ }

		// A copy constructor.
		GVertex(const GVertex<N, W>& other)
		{
			node = other.node;
			edges.clear();

			for (auto iter = other.edges.cbegin();
				 iter != other.edges.cend(); ++iter)
			{
				edges.push_back(*iter);
			}
		}

		// Destructor.
		~GVertex()
		{ }

		//
		bool operator==(const GVertex<N, W>& other)
		{
			return (node == other.node);
		}

		bool operator!=(const GVertex<N, W>& other)
		{
			return !(*this == other);
		}
	};
}


#endif // !LIB_GRAPH_VERTEX

