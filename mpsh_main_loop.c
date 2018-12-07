/* ****************************************************** */
/* BSHARA Kinan                                           */
/* mpsh program                                           */
/* mpsh_main_loop.c                                       */
/* ****************************************************** */

#include "mpsh_main_loop.h"


void mpsh_main_loop(void) {
  char *line;
  char **line_tokens;
  short status = 1;
  mpsh_init();
    while (status){
    printf("%s",PS1);
    line = mpsh_read_line();
    line_tokens = mpsh_toknizer(line);
    status = mpsh_excuter(line_tokens);

    free(line);
    free(line_tokens);
  }
}
