/*
 * gui.c
 *
 * Copyright (C) volodim - 2009
 * <benjamin.burget@gmail.com>
 *
 */

#include "global.h"

void
init_screen(void)
{
     int bg = -1;

     initscr();
     noecho();
     keypad(stdscr, TRUE);
     printw("uChat IRC Client.\n");

     /* Color support */
     start_color();
     bg = (use_default_colors() == OK) ? -1 : COLOR_BLACK;
     init_pair(0, COLOR_BLACK, COLOR_GREEN);
     init_pair(1, COLOR_WHITE, bg);

     /* Init main window and the borders */
     mainwin = newwin(LINES - 2, COLS, 1, 0);
     scrollok(mainwin, TRUE);
     refresh();
     wrefresh(mainwin);

     /* Init input window */
     inputwin = newwin(LINES - 4, COLS, LINES - 2, 0);
     wmove(inputwin, 0, 0);
     refresh();
     wrefresh(inputwin);

     return;
}

