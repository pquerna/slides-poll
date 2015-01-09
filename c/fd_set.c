#include <stdint.h>

#define FD_SETSIZE (1024)

typedef struct {
  unsigned long fds_bits[FD_SETSIZE / (8 * sizeof(long))];
} fd_set;

#define FD_ZERO(set)                                          \
  do {                                                        \
    unsigned int __i;                                         \
    fd_set *__arr = (set);                                    \
    for (__i = 0; __i < sizeof(fd_set) / sizeof(long); ++__i) \
      __arr->fds_bits[__i] = 0;                               \
  } while (0)

#define __NFDBITS (8 * (int)sizeof(long int))
#define __FD_ELT(d) ((d) / __NFDBITS)
#define __FD_MASK(d) ((long int)1 << ((d) % __NFDBITS))

#define FD_SET(d, set) ((void)(set->fds_bits[__FD_ELT(d)] |= __FD_MASK(d)))
