#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define EPOLL_CTL_ADD (1)
#define EPOLLIN (1)

typedef union epoll_data {
    void    *ptr;
    int      fd;
    uint32_t u32;
    uint64_t u64;
} epoll_data_t;

struct epoll_event {
    uint32_t     events;    /* Epoll events */
    epoll_data_t data;      /* User data variable */
};

int epoll_create(int size);

int epoll_wait(int epfd, struct epoll_event *events,
               int maxevents, int timeout);

int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);