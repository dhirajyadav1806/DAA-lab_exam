int V = 4;
int INT_MAX = 2147483647;

int min(int a, int b)
{
	return (a < b) ? a : b;
}


int primMST(int graph[V][V], int V)
{
	int i;

	int key[V], res = 0;
	for(i = 0; i < V; i++)
	{
		key[i] = INT_MAX;
	}
    key[0] = 0;


    int mSet[V];
	for(i = 0; i < V; i++)
	{
		mSet[i] = 0;
	}


    for(int count = 0; count < V; count++)
    {
        int u = -1;
        for(i = 0; i < V; i++)
        {
            if(!mSet[i] && (u == -1 || key[i] < key[u]))
            {
                u = i;
            }
        }

        mSet[u] = 1;
		res += key[u];

		int v;
        for(v = 0; v < V; v++)
        {
            if(graph[u][v] != 0 && !mSet[v])
            {
                key[v] = min(key[v], graph[u][v]);
            }
        }
    }


	return res;
}


int main()
{
	int graph[4][4] =
		{
			{0, 5, 8, 0},
			{5, 0, 10, 0},
			{8, 10, 0, 20},
			{0, 15, 20, 0}
		};



	int dist = primMST(graph, V);

	printf("cost of this MST is - %d \n", dist);

	return 0;
}
