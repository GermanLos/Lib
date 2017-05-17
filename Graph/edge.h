
#ifndef LIB_GRAPH_EDGE
#define LIB_GRAPH_EDGE

namespace Lib
{
	template <typename N, typename W>
	struct GVertex;

	// K - key. W - edge weight.
	template <typename N, typename W>
	struct GEdge
	{
		GVertex<N, W>& direction;
		W weight;

		// A constructor with two arguments.
		GEdge(GVertex<N, W>& directionTo, const W& _weight) :
			direction(directionTo), weight(_weight)
		{ }

		// A copy constructor.
		GEdge(const GEdge<N, W>& other) : 
			direction(other.direction), weight(other.weight)
		{ }

		// Destructor.
		~GEdge()
		{ }

		//
		bool operator==(const GEdge<N, W>& other)
		{
			return (direction.node == other.direction.node);
		}

		bool operator!=(const GEdge<N, W>& other)
		{
			return !(*this == other);
		}
	};
}

#endif // !LIB_GRAPH_EDGE

