Djikstra Algorithm (Finding the Shortest Path Between Two Vertices in a Graph with Positive Weights)

1. Initialize an array of distances from the source to itself to zero, and to other vertices - to infinity.
2. Create a priority queue for greedily processing the closest vertex
3. Push the source vertex to the queue
4. Process vertices by checking if the distance to each neighbor can be relaxed (shortened). If yes, relax it and push that neighbor to the queue.
5. The queue becomes empty when there're no vertices left to be processed, and the distance array is finished. If the distance to the target is still infinity, no path exists.

Time Complexity: O(VlogV)

Bellman-Ford Algorithm (Finding the Shortest Path Between Two Vertices in any Graph)

1. Initialize an array of distances from the source to itself to zero, and to other vertices - to infinity.
2. Initialize an array for storing predecessors of each vertex in the shortest path
3. Iterate over all edges V-1 times, where V is the number of vertices
4. At each iteration, relax edges from a vertex to all its neighbors
5. The steps 1-4 produce a final version of the distance array in a graph with no negative cycles. This means that now, if we iterate over all edges and find an edge to relax, there's a negative cycle in the graph because the shortest path over a negative cycle is -infinity. If there're no negative cycles, we have nothing to update.

Time Complexity: O(VE)