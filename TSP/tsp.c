// A Dynamic Programming solution
// for TSP
#include <stdio.h>
#include <stdbool.h> 

int tour[10];
int cost;
int length = 0;

int
printtour()
{
	int i=0;
	
	printf("TOUR=");
	for (i = 0; i < length; i++)
		printf("%d->", tour[i]);
	printf("\n");
}

void TSP(int *node, int nelem, int nremain, int start_node)
{
	int i;

	/* if only start node is left then print the tour */
	if (nremain == 0)
	{
		tour[length++] = start_node;
		printtour();
		length--;
		return;
	}

	for (i = 0; i < nelem; i++)
	{
		int j;
		bool found = false;

		if (node[i] == start_node)
			continue;
		for (j = 0; j < length; j++)
		{
			if (node[i] == tour[j])
			{
				found = true;
				break;
			}
		}
		if (found)
			continue;
		/* add the element to the tour and recurse into TSP */
		tour[length++] = node[i];
		TSP(node, nelem, nremain-1, start_node);
		length--;
	}
	
}
 
// Driver code
int main()
{
    int node[]={1,2,3,4};
    //int path[][10] = {{0,10,15,20},{5,0,9,10}, {6,13,0,12},{8,8,9,0}};
    int n = sizeof(node) / sizeof(node[0]);

    tour[length++] = node[0];
    TSP(node, n, n-1, node[0]);
    return 0;
}
// This code is contributed by Arjun Tyagi.
