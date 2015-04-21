#include <netdb.h>
#include <stdio.h>
#include <sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include <string.h>

int main(char argc , char * argv[]){
	char ** p;
	struct in_addr addr;
	struct hostent *hostp;

	if (argc != 2) return 1;
	
	int n = inet_aton((char *)argv[1] ,&addr);

	printf("%s\n",argv[1]);
	
	if( n != 0){
		hostp = gethostbyaddr( (const char*)argv[1], sizeof(addr) ,AF_INET );
	}else{
		hostp = gethostbyname(argv[1]);

		/*char ** p = hostp->h_aliases;	*/
		/*int i;*/
		/*char ** h_aliases = hostp->h_aliases;*/
		/*int h_length = hostp->h_length;*/
		/*for(i=0;i<h_length;i++){*/
			/*printf("%s,\n",*(h_aliases +i));*/
		/*}*/

		//print addresses 

		if(!hostp) return 1;

		int i;
		for(i=0;;i++){
			if(hostp->h_addr_list[i] == NULL)break;
			
			struct in_addr *addr2  =(struct in_addr *)hostp->h_addr_list[i];
			char * addrStr = inet_ntoa( *addr2  );
			
			printf("%s\n",addrStr );
		
		}

		printf("==============aliases==============================\n");

		for(i=0;;i++){
			if(hostp->h_aliases[i] == NULL) break;

			printf("%s\n",hostp->h_aliases[i]);
		}

	}
	
	/*printf("official hostname: %s \n ", hostp->h_name);*/
	return 0;

}
