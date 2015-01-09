
#include <stdio.h>
#include <sys/select.h>

int wait_for_read(int fd) {
  fd_set readfds;
  do {
    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    int rv = select(FD_SETSIZE, &readfds, NULL, NULL, NULL);
    if (rv == -1) {
      perror("select failure");
      return -1;
    }

    if (FD_ISSET(fd, &readfds)) {
      return 1;
    }

  } while (1);
}
