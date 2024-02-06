//Copy code
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main() {
    int clientSocket;
    sockaddr_in serverAddr;

    // Create socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        std::cerr << "Error creating socket" << std::endl;
        return 1;
    }

    // Server address configuration
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12346); // Port to connect
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Server IP address

    // Connect to the server
    if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Connection failed" << std::endl;
        return 1;
    }

    // Message to send
    const char *message = "Hello, server!";
    
    // Send the message to the server
    if (send(clientSocket, message, strlen(message), 0) < 0) {
        std::cerr << "Send failed" << std::endl;
        return 1;
    }

    std::cout << "Message sent to server: " << message << std::endl;

    // Close the socket
    close(clientSocket);

    return 0;
}
