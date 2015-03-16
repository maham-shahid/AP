#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>

int main() {

  struct addrinfo hints, *res;
  int sockfd;

  // first, load up address structs with getaddrinfo():
  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;  // use IPv4 or IPv6, whichever
  hints.ai_socktype = SOCK_STREAM;

  // we could put "80" instead on "http" on the next line:
  getaddrinfo("localhost", "8080", &hints, &res);
  // make a socket:
  sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  // connect it to the address and port we passed in to getaddrinfo():
  connect(sockfd, res->ai_addr, res->ai_addrlen);

    char filename[100];
    // printf("Enter file name:\n");
    // scanf("%s",&filename);
    strcpy(filename,"yo.txt");
    //Write to the socket.
     write(sockfd, filename, 100);
    //Read back response from the socket
    char filesize[1024];
    int num = read(sockfd, filesize, 1024);
    filesize[num] = 0;
    int fsize=atoi(filesize);
    printf("Received buf %d\n", fsize);
    
    char*data=malloc(fsize*sizeof(char));
    int i=0;
    for (i=0;i<fsize;i++)
        read(sockfd,(char)data[i],1);
  return 0;
}