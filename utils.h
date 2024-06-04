#ifndef UTILS_H
#define UTILS_H

void clear_input_buffer();

#ifdef _WIN32
#define CLEAR_SCREEN() system("cls")
#else
#define CLEAR_SCREEN() system("clear")
#endif

#endif // UTILS_H
