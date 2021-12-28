// A Dynamic Programming solution
// for subset sum problem
#include <stdio.h>
#include <stdbool.h> 
// Returns true if there is a subset of set[]
// with sum equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if
    // there is a subset of set[0..j-1] with sum
    // equal to i
    bool subset[n + 1][sum + 1];
    int i,j;
 
    // If sum is 0, then answer is true
    for (i = 0; i <= n; i++)
        subset[i][0] = true;
 
    // If sum is not 0 and set is empty,
    // then answer is false
    for (i = 1; i <= sum; i++)
        subset[0][i] = false;
 
    // Fill the subset table in bottom up manner
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= sum; j++) {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j]
                               || subset[i - 1][j - set[i - 1]];
        }
    }
 
    /*   // uncomment this code to print table
     for (int i = 0; i <= n; i++)
     {
       for (int j = 0; j <= sum; j++)
          printf ("%4d", subset[i][j]);
       printf("\n");
     }*/
 
    return subset[n][sum];
}
 
// Driver code
int main()
{
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
	int id1,id3;
	int id2;
	int diff;
	id1=4254970840;
	id3=4273514497;
	id2 = 9484934;
	diff=(int)(id3-id2);
	printf("%d", diff);
	return;
    if (isSubsetSum(set, n, sum) == true)
        printf("Found a subset with given sum");
    else
        printf("No subset with given sum");
    return 0;
}
// This code is contributed by Arjun Tyagi.
