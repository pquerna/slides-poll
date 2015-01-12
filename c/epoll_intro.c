#include <stdint.h>
#include "sys/epoll.h"

int wait_for_read(int fd) {
  struct epoll_event *events;
  struct epoll_event e;
  memset(&e, 0, sizeof(epoll_event));

  int epfd = epoll_create(0);

  e.events = EPOLLIN;

  epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &e);

  events = (epoll_event *)calloc(1, sizeof(epoll_event));

  do {
    int n = epoll_wait(epfd, events, 1, -1);
    for (int i = 0; i < n; i++) {
      if (events[i].data.fd == fd) {
        return 1;
      }
    }
  } while (1);
}
