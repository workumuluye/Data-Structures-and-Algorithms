import heapq

def dijkstra(graph, start):
    # Initialize distances with infinity
    dist = {node: float('inf') for node in graph}
    dist[start] = 0

    # Priority queue: (distance, node)
    pq = [(0, start)]

    while pq:
        current_dist, current_node = heapq.heappop(pq)

        # If we already found a shorter path to this node
        if current_dist > dist[current_node]:
            continue

        for neighbor, weight in graph[current_node].items():
            distance = current_dist + weight
            if distance < dist[neighbor]:
                dist[neighbor] = distance
                heapq.heappush(pq, (distance, neighbor))

    return dist

# Run the example
graph = {
    'A': {'B': 2, 'C': 1},
    'B': {'A': 2, 'D': 3},
    'C': {'A': 1, 'D': 1, 'E': 1},
    'D': {'B': 3, 'C': 1, 'E': 1},
    'E': {'C': 1, 'D': 1}
}

distances = dijkstra(graph, 'A')
print("Shortest distances from A:", distances)
