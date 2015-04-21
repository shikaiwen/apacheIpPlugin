#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc , char * argv [] ){
	int server_sockfd;
	int client_sockfd;

	int len;
	struct sockaddr_in my_addr;
	struct sockaddr_in remote_addr;
	int sin_size;
	char buf[BUFSIZ];//8192
	memset(&my_addr,0, sizeof(my_addr));
	my_addr.sin_family= AF_INET;
	my_addr.sin_addr.s_addr=INADDR_ANY;
	my_addr.sin_port=htons(8000);

	if((server_sockfd = socket(PF_INET,SOCK_STREAM,0)) < 0){
		perror("socket error");
		return 1;
	}

	if(bind(server_sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) < 0){
		perror("bind error");
		return 1;
	}

	listen(server_sockfd, 5);

	sin_size = sizeof(struct sockaddr_in);

	// wait for client connection request
	if((client_sockfd=accept(server_sockfd, (struct sockaddr*)&remote_addr,&sin_size))<0){
		perror("accept error");
		return 1;
	}

	printf("accept client %s\n", inet_ntoa(remote_addr.sin_addr));
	len = send(client_sockfd,"Welcome to my server\n",21,0);

	while((len=recv(client_sockfd,buf,BUFSIZ,0)) > 0){
		buf[len] = '\0';
		printf("%s\n",buf);
		if(send(client_sockfd,buf,len,0)<0){
			perror("write error ");
			return 1;
		}
	}

	close(client_sockfd);
	close(server_sockfd);
	return 0;
}
