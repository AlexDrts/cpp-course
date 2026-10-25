#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    WSADATA wsaData;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        cout << "Winsock startup error!" << endl;
        return 1;
    }

    SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (listenSocket == INVALID_SOCKET)
    {
        cout << "Socket creation error!" << endl;

        WSACleanup();

        return 1;
    }

    sockaddr_in serverAddr;

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(27015);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listenSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
    {
        cout << "Socket bind error!" << endl;

        closesocket(listenSocket);
        WSACleanup();

        return 1;
    }

    listen(listenSocket, SOMAXCONN);

    cout << "Server started!" << endl;
    cout << "Waiting for client..." << endl;

    SOCKET clientSocket = accept(listenSocket, NULL, NULL);

    if (clientSocket == INVALID_SOCKET)
    {
        cout << "Client connection error!" << endl;

        closesocket(listenSocket);
        WSACleanup();

        return 1;
    }

    cout << "Client connected!" << endl;

    while (true)
    {
        int number;

        int bytesReceived = recv(clientSocket, (char*)&number, sizeof(number), 0);

        if (bytesReceived <= 0)
        {
            cout << "Client disconnected." << endl;
            break;
        }

        cout << "Received number: " << number << endl;

        int result = number + 1;

        cout << "Result: " << result << endl;

        send(clientSocket, (char*)&result, sizeof(result), 0);
    }

    closesocket(clientSocket);
    closesocket(listenSocket);

    WSACleanup();

    return 0;
}