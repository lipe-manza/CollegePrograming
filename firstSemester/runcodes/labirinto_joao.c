#include <stdio.h>
#include <stdbool.h>


bool search_the_path(int i, int j, int n, int m, char matrix[n][m], int visited[n][m])
{
  //Out of the maze
  if (i < 0 || i >= n || j < 0 || j >= m)
    return false;

  //already visited or wall
  if (visited[i][j] || matrix[i][j] == '#')
    return false;

  //found P
  if (matrix[i][j] == 'P')
    return true;

  //Visited
  visited[i][j] = true;

  //All 4 different paths
  return search_the_path(i + 1, j, n, m, matrix, visited) ||
         search_the_path(i - 1, j, n, m, matrix, visited) ||
         search_the_path(i, j + 1, n, m, matrix, visited) ||
         search_the_path(i, j - 1, n, m, matrix, visited);
}

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);

  char matrix[n][m];
  int visited[n][m];

  int start_i = -1, start_j = -1;

  //fill the matrix
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      scanf(" %c", &matrix[i][j]);
      visited[i][j] = 0;

      if (matrix[i][j] == 'J')
      {
        start_i = i;
        start_j = j;
      }
    }
  }

  //call the function
  if (search_the_path(start_i, start_j, n, m, matrix, visited))
    printf("Sim");
  else
    printf("Nao");

  return 0;
}
