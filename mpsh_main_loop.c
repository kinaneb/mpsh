/* ****************************************************** */
/* BSHARA Kinan                                           */
/* mpsh program                                           */
/* mpsh_main_loop.c                                       */
/* ****************************************************** */

#include "mpsh_main_loop.h"


int exit_boolean = 1;

int mpsh_main_loop(void) {
  char *line;
  mpsh_init();
  while (exit_boolean)
  {
    printf("%s",PS1);
    line = mpsh_read_line();
    int l = builtin_handler(line);
    if(l != 0)
    {
      char **line_tokens = mpsh_toknizer(line);
      mpsh_excuter(line_tokens);
      free(line_tokens);
    }

    history = limited_append_row(history, line, HISTSIZE);
    history_init_len++;
    free(line);
  }
  limited_append_table(history_dir, history, HISTFILESIZE);
  return last_command_status;
}
