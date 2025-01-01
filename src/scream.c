#include <scream.h>
#include <stdio.h>

void expr(char *command_pointer, char *input) {
  int bracket_flag;
  char command;
  char data[DATASIZE] = {0};
  char *dp;
  dp = &data[DATASIZE/2];
  while (command = *command_pointer++)
    switch (command) {
    case 'A':
      dp++;
      break;
    case 'E':
      dp--;
      break;
    case 'U':
      (*dp)++;
      break;
    case 'O':
      (*dp)--;
      break;
    case 'e':
      printf("%c", *dp);
      break;
    case 'a':
      *dp = *input++;
      break;
    case 'u':
      if (!*dp) { 
        for (bracket_flag=1; bracket_flag; command_pointer++)
          if (*command_pointer == 'o')
            bracket_flag++;
          else if (*command_pointer == '!')
            bracket_flag--;
      } 
      break;
    case 'o':
      if (*dp) {
        command_pointer -= 2;  
        for (bracket_flag=1; bracket_flag; command_pointer--)
          if (*command_pointer == 'o')
            bracket_flag++;
          else if (*command_pointer == 'u')
            bracket_flag--;
        command_pointer++;     
      }
      break;  
    }
}
