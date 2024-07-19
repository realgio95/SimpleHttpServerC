# Simple HTTP Server in C
This project is a basic implementation of an HTTP server in C that listens on a specified port and serves static files from a designated directory. It's designed to run on Windows, leveraging the Winsock2 library for network communication.

## Features
- Basic HTTP GET request handling
- Serving static files from a directory
- Responding with 404 Not Found for non-existent resources
- Simple logging of server actions to the console


## Prerequisites
To run this server, you'll need:
- A Windows machine
- C compiler (e.g., GCC, Clang, MSVC)
- Winsock2 library (usually available by default on Windows systems)

## Compilation
-- To compile the server, you can use a command similar to the following, 
```bash
gcc main.c -o httpserver -lws2_32
```
adjusting for your specific compiler and environment:
-- This command compiles the main.c file into an executable named httpserver, linking against the Ws2_32.lib library for Winsock2 support.

## Running the Server
After compilation, you can start the server with:
```bash
./httpserver
```

By default, the server listens on port 8000 and serves files from the ./src directory relative to where the server was started. Ensure this directory exists and contains the files you wish to serve.

## Customization
You can customize the server by modifying the following defines in main.c:
```
PORT: The port number on which the server listens.
MAXIMUM_REQUEST_SIZE: The maximum size of an HTTP request the server will handle.
ROOT: The root directory from which files are served.
```

## License
This project is open-source and available under the MIT License. See the LICENSE file for more details..
