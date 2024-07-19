#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <winsock2.h>
#pragma comment(lib, "Ws2_32.lib")

#define PORT 8000
#define MAXIMUM_REQUEST_SIZE 2048
#define ROOT "./src"

void handling()
{
    printf("Hello");
}

int main() {
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (result != 0) {
        // Handle error
    }

    int serverSock, clientSock;
    struct sockaddr_in serverAddr, clientAddr;
    int lenAddr = sizeof(struct sockaddr_in);

    serverSock = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSock == -1) 
    {
    	perror("Server failed badly.");
	    exit(EXIT_FAILURE);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    if (bind(serverSock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("Bad error, failed to listen.");
        exit(EXIT_FAILURE);
    }

    printf("Listen to port %d", PORT);

    while (1) 
    {
        clientSock = accept(serverSock, (struct sockaddr*)&clientAddr, &lenAddr);
 	    if (clientSock < 0) 
        {
            perror("proposal declientd");
            exit(EXIT_FAILURE);
        }
        handling(clientSock);
	}

    WSACleanup();
    return 0;
}

