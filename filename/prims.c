#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// adjMatrix is the adjacency matrix. Double the pointers,
// double the fun.
int **adjMatrix;

int main(int argc, char **argv) {
	// cheekily remove the pointless first argument we don't need.
	argc--; argv++;
	if (argc % 2 == 0) {
		// Set up adjacency matrix.
		int n = argc / 2;
		adjMatrix = calloc(n, sizeof(int *));
		for (int i = 0; i < n; i++) {
			adjMatrix[i] = calloc(n, sizeof(int));
		}
		
		// Now, let's populate the adjacency matrix.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i==j)  {
					// -1 means that this is not an edge.
					adjMatrix[i][j] = -1;
				}
				else {
					// EXAMPLE
					// X-----
					// ---X--
					// input: 0 1 3 0
					// adjacency matrix for [0][1]: |3 - 0| + |0 - 1|
					// abs() is the modulus function, short for absolute.
					// Not abdominals.
					adjMatrix[i][j] = abs(atoi(argv[2*j]) - atoi(argv[2*i])) + abs(atoi(argv[(2*j)+1]) - atoi(argv[(2*i)+1]));
				}
			}
		}

		// I make it Prim's o' clock!

		// sumDist = The total wire used thus far.
		int sumDist = 0;
		// MST. The minimum spanning tree. We probably
		// could do without this, but it's cool to have still.
		int MST[n][n];
		// isNodeDiscovered is the cool boolean array
		// I mentioned earlier. True if the given node
		// has been discovered.
		bool isNodeDiscovered[n];
		// Counting the number of nodes discovered,
		// so you don't have to.
		int nDiscovered = 1;
		
		// Initialising the MST 2d array.
		for (int i; i < n; i++) {
			for (int j; j < n; j++) {
				MST[i][j]=0;
			}
			isNodeDiscovered[i] = false;
		}
		// You discover the first node.
		isNodeDiscovered[0] = true;
		
		while (nDiscovered < n) {
			// cheapestNodeTo: Where we start.
			int cheapestNodeTo = -1;
			// cheapestNodeFrom: Where we end.
			int cheapestNodeFrom = -1;
			// shortestDist: the value of the shortest path.
			int shortestDist = 10000;
			// We look through all the discovered nodes to see where the next
			// closest one is.
			for (int i = 0; i < n; i++) {
				if (isNodeDiscovered[i]) {
					for (int j = 0; j < n; j++) {
						// If the node is node itself, and it is not discovered.
						if ((adjMatrix[i][j] >= 0) && (!isNodeDiscovered[j])) {
							// If the given edge is the shortest one yet.
							if (adjMatrix[i][j] < shortestDist) {
								cheapestNodeTo = j;
								cheapestNodeFrom = i;
								shortestDist = adjMatrix[i][j];
							}
						}
					}

				}
			}
			// If we actually found something:
			if (cheapestNodeTo>=0 && cheapestNodeFrom>=0) {
				// Add this to the MST, pronto.
				MST[cheapestNodeTo][cheapestNodeFrom] = shortestDist;
				// We have discovered this node now.
				isNodeDiscovered[cheapestNodeTo] = true;
				// We should also increase this value as well.
				nDiscovered++;
				// Increasing the sum of wire being used.
				sumDist+= shortestDist;
				// Print it at you.
				printf("ADDED: (%i -> %i), dist=%i\n",cheapestNodeFrom,cheapestNodeTo,shortestDist);
			}
		}
		
		// Should remove this. But I love spamming stdout,
		// so it shall stay.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%i\t",adjMatrix[i][j]);
			}
			printf("\n");
		}

		printf("%i\n",sumDist);


		return 0;
	}
	else {
		// Boo hoo, you can't count.
		printf("Please enter valid coordinates (i.e., even number of values.).\n");
		return 1;
	}
}
