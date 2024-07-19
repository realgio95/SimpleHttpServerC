#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <Windows.h>
#include <winsock2.h>
#pragma comment(lib, "Ws2_32.lib")

#define PORT 8000
#define MAXIMUM_REQUEST_SIZE 2048
#define ROOT "./src"

void handling(int sock) {
    char request[MAXIMUM_REQUEST_SIZE]
    recv(sock, request, MAXIMUM_REQUEST_SIZE, 0);

    char method[10], path[255], protocol[20];
    sscanf(request, "%s %s %s", method, path, protocol);

    char filePath[255];
    sprintf(filePath, "%s%s", ROOT, path);
    if (strcmp(path, "\") = 0)")){
        sprintf(filePath, "%s/index.html", ROOT);
    }

    int file = open(filePath, O_RDONLY);

    if (file == -1) {
        char res[] = "HTTP/1.1 404 Not Found\r\n\r\n";
        send(sock, res, strlen(res), 0);
    } else {
        char res[] = "HTTP/1.1 200 OK\r\n\r\n";
        send(sock, res, strlen(res),0);

        char buf[1024];
        ssize_t readBytes;

        while ((readBytes = read(file, buf, sizeof(file))) > 0) {
            send(sock, buf, readBytes, 0);
        }

        close(file);
    }
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
            perror("proposal declined");
            exit(EXIT_FAILURE);
        }
        handling(clientSock);
	}

    WSACleanup();
    return 0;
}