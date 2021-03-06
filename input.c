/*
 * input.c
 *
 * Copyright (C) volodim - 2009
 * <benjamin.burget@gmail.com>
 * Copyright (C) xorg62 - 2009
 * <xorg62@gmail.com>
 *
 */

#include "global.h"

const InputStruct input_struct[] =
{
     { "join", input_join },
     { "nick", input_setnick },
     { "quit", input_quit },
     { "help", input_help },
     { "connect", input_connect },
     { "disconnect", input_disconnect }
};

void
input_manage(const char *input)
{
     int i;

     if(input[0] == '/')
     {
          ++input;
          for(i = 0; i < LEN(input_struct); ++i)
               if(!strncmp(input, input_struct[i].cmd, strlen(input_struct[i].cmd)))
                    input_struct[i].func(input + strlen(input_struct[i].cmd));
     }
     else
          send_msg(Socket, "PRIVMSG "IRC_CHAN" :%s\r\n", input);

     return;
}

void
input_help(const char *arg) {
     return;
}

void
input_setnick(const char *arg) {
     send_msg(Socket, "NICK %s :\r\n", arg);
     return;
}

void
input_join(const char *arg) {
     send_msg(Socket, "JOIN %s :\r\n", arg);
     return;
}

void
input_part(const char *arg) {
     send_msg(Socket, "PART %s :\r\n", arg);
     return;
}

void
input_connect(const char *arg) {
  int online;
  init_connection("irc.freenode.net", 6667, online);
  gui_update_statuswin(online);
  return;
}

void
input_disconnect(const char *arg) {
  return;
}

void
input_quit(const char *arg) {
     send_msg(Socket, "QUIT %s :\r\n", arg);
     exit(0);
}
