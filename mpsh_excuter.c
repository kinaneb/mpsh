/* ****************************************************** */
/* BSHARA Kinan                                           */
/* mpsh program                                           */
/* mpsh_excuter.c                                        */
/* ****************************************************** */

#include "mpsh_excuter.h"

int mpsh_excuter(char **line_tokens)
{
  int pid, wpid;
  int status;

  pid = fork();
  if (pid == 0)
  {
    // Child  https://linux.die.net/man/3/execvp
    if (execvp (line_tokens[0], line_tokens) == -1)
    {
      fprintf(stderr, "%s\n", strerror( errno ) );
    }
    return errno;
  }
  else if (pid < 0)
  {
    // fork failure!
    perror("mpsh fork failure!");
  }
  else
  {
    // Parent
    do
    {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}
