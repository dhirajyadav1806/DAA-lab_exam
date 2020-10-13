#define SIZE 10

void DFS(int graph[SIZE][SIZE], int numOfVertex, int startVertex, int visited[])
{
	printf("%d ", startVertex);
	visited[startVertex] = 1;

	for(int i = 0; i < numOfVertex; i++)
	{
		if(graph[startVertex][i] == 1 && visited[i] == 0)
		{
			DFS(graph, numOfVertex, i, visited);
		}
	}
}

int main()
{


	int graph[SIZE][SIZE] =
		{
		//	 0  1  2  3  4  5
			{0, 1, 1, 0, 0, 1}, // 0
			{1, 0, 0, 1, 0, 0}, // 1
			{1, 0, 0, 0, 1, 0}, // 2
			{0, 1, 0, 0, 0, 1}, // 3
			{0, 0, 1, 0, 0, 1}, // 4
			{1, 0, 0, 1, 1, 0}  // 5
		};

	int visited[6] = {0, 0, 0, 0, 0, 0};


	DFS(graph, 6, 0, visited);
}
