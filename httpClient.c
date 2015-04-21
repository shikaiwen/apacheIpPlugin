#include <stdio.h>
#include <sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include <string.h>

int main(int argc,char * argv[]){
	
	int client_sockfd;
	struct sockaddr_in remote_addr;
	
	memset((void *)&remote_addr,0,sizeof(struct sockaddr_in));
	remote_addr.sin_family = AF_INET;
	/*remote_addr.sin_addr.s_addr = inet_addr("61.160.224.165");*/
	inet_aton("61.160.224.165",&remote_addr.sin_addr);
	remote_addr.sin_port = htons(80);
	
	//connect to server 
	if((client_sockfd = socket(PF_INET,SOCK_STREAM,0)) < 0){
		perror("sock create error");
		return 1;
	}

	if( connect(client_sockfd ,(struct sockaddr *)&remote_addr, sizeof(struct sockaddr)) <0 ){
			perror("connect to server error ");
			return 1;
	}

	printf("connect success ");
	
	char buf[BUFSIZ];
	/*int len = recv(client_sockfd,buf,BUFSIZ,0);*/

	/*buf[len]='\0';*/
	/*printf("received from server after connected :%s\n",buf);*/

	//send data to server 
	//
	printf("========================================================")	;
	char data[BUFSIZ];
	
	memset(&data,0,BUFSIZ);

	char * url = "http://www.23wx.com/";
	strcat(data,"GET ");
	strcat(data,url);
	strcat(data," HTTP/1.1");
	strcat(data,"\r\n");
	strcat(data,"HOST: www.23wx.com\r\n\r\n");

		
	/*printf("%s",data);*/
	/*return 0;*/

	send(client_sockfd,data,strlen(data),0);
	int len;
	while((len=recv(client_sockfd,buf,BUFSIZ,0)) >0 ){
		buf[len] = '\0';
		printf("%s",buf);
	}
	/*recv(client_sockfd,buf,BUFSIZ,0);*/
	
	close(client_sockfd);
	return 0;
}
