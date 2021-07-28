#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4442

int main(){

	int sockfd, ret;
	struct sockaddr_in serverAddr;


	int newSocket1;
	int newSocket2;
    int optval =1;
	struct sockaddr_in newAddr1,newAddr2;

	socklen_t addr_size;

	pid_t childpid;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
		printf("[-]Error in connection.\n");
		exit(1);
	}
	printf("[+]Server Socket is created.\n");
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR,&optval,sizeof(optval));
	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		printf("[-]Error in binding.\n");
		exit(1);
	}
	printf("[+]Bind to port %d\n", 4444);

	if(listen(sockfd, 10) == 0){
		printf("[+]Listening....\n");
	}else{
		printf("[-]Error in binding.\n");
	}


	while(1){
		newSocket1 = accept(sockfd, (struct sockaddr*)&newAddr1, &addr_size);
		char *buff;
		newSocket2= accept(sockfd, (struct sockaddr*)&newAddr2, &addr_size);
		buff="1";
		send(newSocket1,buff,2,0);
        buff="2";
        send(newSocket2,buff,2,0);
		printf("Connection accepted from %s:%d\n", inet_ntoa(newAddr1.sin_addr), ntohs(newAddr1.sin_port));
		printf("Connection accepted from %s:%d\n", inet_ntoa(newAddr2.sin_addr), ntohs(newAddr2.sin_port));


		if((childpid = fork()) == 0){
			close(sockfd);
           
			while(1){
				char buff1[24];
				char buff2[24];
				char buff3[48];
			
				int r=0,s=0;
				int r1=0,s1=0;
			   
				r=recv(newSocket1, buff3, 6, 0);;
				s=send(newSocket2,buff3,6,0);
			
                bzero(buff1,sizeof(buff1));
                bzero(buff2,sizeof(buff2));
				bzero(buff3,sizeof(buff3));
	            

				r1=recv(newSocket2, buff3, 6, 0);
				s1=send(newSocket1,buff3,6,0);
			    
				bzero(buff1,sizeof(buff1));
                bzero(buff2,sizeof(buff2));
				bzero(buff3,sizeof(buff3));
				 

	             }
				 }


	close(newSocket1);
	close(newSocket2);


} 
return 0;
}
