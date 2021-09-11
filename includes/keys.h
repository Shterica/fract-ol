#ifndef KEYS_H
# define KEYS_H

# ifdef __unix__
#  define K_ESC 65307
#  define K_LEFT_ARROW 65361
#  define K_UP_ARROW 65362
#  define K_RIGHT_ARROW 65363
#  define K_DOWN_ARROW 65364
# else
#  define K_ESC 53
#  define K_LEFT_ARROW 123
#  define K_UP_ARROW 126
#  define K_RIGHT_ARROW 124
#  define K_DOWN_ARROW 125
# endif

#endif