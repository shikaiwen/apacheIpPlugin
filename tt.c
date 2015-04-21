#include <sys/socket.h>
#include <stdio.h>
#include<netinet/in.h>
int main(int argc , char * argv[]){

		printf("%d\n",sizeof(struct sockaddr));
		printf("%d\n",sizeof(struct sockaddr_in));

}
