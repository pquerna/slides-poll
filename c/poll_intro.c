
#include <stdio.h>
#include <string.h>
#include <sys/poll.h>

int wait_for_read(int fd) {
  struct pollfd fds[1];
  memset(fds, 0, sizeof(fds));

  fds[0].fd = fd;
  fds[0].events = POLLIN;

  do {
    int rv = poll(fds, 1, NULL);
    if (rv == -1) {
      perror("poll failure");
      return -1;
    }

    if (fds[0].revents & POLLIN) {
      return 1;
    }

    if (fds[0].revents & POLLERR) {
      return -2;
    }
  } while (1);
}
