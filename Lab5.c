#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main()
{
  size_t sizeRead;
  char first[1024];
  char second[1024];
  char str2[1000][100];
  char str1[1000][100];
  int i, n, m, fd;
  sizeRead = read(0, first, 1024);
  if (sizeRead <= 0)
  {
    printf("Can\'t read .\n");
    return (-1);
  }
  char *pfir = strtok(first, "\n");
  n = 0;
  while (pfir != NULL)
  {
    strcpy(str1[n], pfir);
    pfir = strtok(NULL, "\n");
    n++;
  }
  fd = open("./text", O_RDONLY);
  if (fd<= 0)
  {
    printf("Can\'t open .\n");
    return (-1);
  }
  read(fd, second, 1024);
  char *psec = strtok(second, " ");
  m = 0;
  while (psec != NULL)
  {
    strcpy(str2[m], psec);
    psec = strtok(NULL, " ");
    m++;
  }

  for (i = 0; i < n && i < m; i++)
  {
    if (str1[i][4] == '0' || str1[i][4] == '2' || str1[i][4] == '4' || str1[i][4] == '6' || str1[i][4] == '8')
      printf("%s\n  %s\n", str2[i], str1[i]);
  }

  return 0;
}
