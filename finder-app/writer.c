#include <unistd.h>
#include <syslog.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/resource.h>
#include <fcntl.h>


int main(int argc, char **argv)
{
  openlog("Assignment-2 Writer App in C ", LOG_NDELAY, LOG_USER);
  int fd;
  if(argc < 3)
  {
    syslog(LOG_ERR, "Error: This program expects 2 arguments and you provided %d argument(s)", argc);
    return 1;
  }
  else if(argc > 3)
  {
    syslog(LOG_ERR, "Error: This program expects 2 arguments and you provided %d argument(s)", argc);
    return 1;
  }
  else
  {
    size_t count;
    ssize_t number_returned;
    const char *file_name = argv[1];
    const char *string_buffer = argv[2];

    syslog(LOG_DEBUG, "Writing %s to %s.", string_buffer, file_name);


    fd = open(file_name, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if(fd == -1)
    {
      syslog(LOG_ERR, "Error with open(), errno is %d (%s)",errno, strerror(errno) );
      return 1;
    }

    count = strlen(string_buffer);
    number_returned = write(fd, string_buffer, count);


    if(number_returned == -1)
    {
      syslog(LOG_ERR, "Error with write(), errno is %d (%s)",errno, strerror(errno) );
      return 1;
    }
    else if(number_returned != count)
    {
      syslog(LOG_ERR, "write() is incomplete, but 'errno' not set");
      return 1;
    } else {
      close(fd);
      syslog(LOG_DEBUG, "Writing %s to %s completed.", string_buffer, file_name);
      closelog();
      return 0;
    }

  }

}
