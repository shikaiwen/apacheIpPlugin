
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(char argc , char * argv []){

	int client_sockfd;


	char * url = "http://www.baidu.com/index/aa.php" ;


	char * hostPart;
	char * hostPartEnd = strchr(url,'/');
	printf("%d\n",&hostPartEnd);
	/*strncpy( hostPart , url , hostPartEnd  );*/

	/*printf("%s\n", hostPart);*/

	/*struct sockaddr_in remoteAddr;*/

	/*remoteAddr.sin_family = AF_INET;*/
	/*remoteAddr.sin_port = htons(80);*/
	/*inet_aton("ipaddr", remoteAddr.sin_addr);*/


}
