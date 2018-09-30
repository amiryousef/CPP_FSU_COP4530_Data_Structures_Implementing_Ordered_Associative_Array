/* 
     ansicodes.h
     http://en.wikipedia.org/wiki/ANSI_escape_code#Colors

     int main()
     {
       std::cout << ANSI_COLOR_RED << "Red" << ANSI_COLOR_RESET << "Black\n";
       std::cout << ANSI_BGCOLOR_RED << "Red" << ANSI_BGCOLOR_RESET << "Black\n";
       std::cout << ANSI_COLOR_BOLD_RED << "Red" << ANSI_BGCOLOR_RESET << "Black\n";
     }

*/

#ifndef _ANSI_CODES_H
#define _ANSI_CODES_H

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"

#define ANSI_BGCOLOR_BLACK   "\x1b[40m"
#define ANSI_BGCOLOR_RED     "\x1b[41m"
#define ANSI_BGCOLOR_GREEN   "\x1b[42m"
#define ANSI_BGCOLOR_YELLOW  "\x1b[43m"
#define ANSI_BGCOLOR_BLUE    "\x1b[44m"
#define ANSI_BGCOLOR_MAGENTA "\x1b[45m"
#define ANSI_BGCOLOR_CYAN    "\x1b[46m"

#define ANSI_COLOR_BOLD_BLACK   "\x1b[1m\x1b[30m"
#define ANSI_COLOR_BOLD_RED     "\x1b[1m\x1b[31m"
#define ANSI_COLOR_BOLD_GREEN   "\x1b[1m\x1b[32m"
#define ANSI_COLOR_BOLD_YELLOW  "\x1b[1m\x1b[33m"
#define ANSI_COLOR_BOLD_BLUE    "\x1b[1m\x1b[34m"
#define ANSI_COLOR_BOLD_MAGENTA "\x1b[1m\x1b[35m"
#define ANSI_COLOR_BOLD_CYAN    "\x1b[1m\x1b[36m"

#define ANSI_COLOR_RESET   "\x1b[0m"

#define ANSI_COLOR_BOLD_BLUE_SHADED "\x1b[1m\x1b[34m\x1b[43m"
#define ANSI_COLOR_BOLD_RED_SHADED  "\x1b[1m\x1b[31m\x1b[43m"

#endif
