#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>

int main() {

  struct addrinfo hints, *res;
  int sockfd;
  int fileSize=0,i;
  FILE *fp;
  char name[20];

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;  
  hints.ai_socktype = SOCK_STREAM;

  getaddrinfo("localhost", "8080", &hints, &res);
  sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  connect(sockfd, res->ai_addr, res->ai_addrlen);

  printf("\nEnter filename: ");
  fgets(name,20,stdin);
  write(sockfd, name, 20);

  char buf[1024];
  int num = read(sockfd, buf, 1024);
  buf[num] = 0;
  fileSize= atoi(buf);
  printf("\nFileSize: %d",fileSize);

  num = read(sockfd, buf, fileSize);
  buf[num+1] = '\n';
  printf("\n Received buf %s", buf);

  fp= fopen("recv.txt","w+");
  fputs(buf,fp);
  fclose(fp);

  return 0;
}