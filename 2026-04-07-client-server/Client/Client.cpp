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

    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (clientSocket == INVALID_SOCKET)
    {
        cout << "Socket creation error!" << endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in serverAddr;

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(27015);

    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

    if (connect(clientSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
    {
        cout << "Unable to connect to server!" << endl;

        closesocket(clientSocket);
        WSACleanup();

        return 1;
    }

    cout << "Connected to server." << endl;

    while (true)
    {
        int number;

        cout << "Enter a number: ";
        cin >> number;

        send(clientSocket, (char*)&number, sizeof(number), 0);

        cout << "Sent: " << number << endl;

        int response;

        int bytesReceived = recv(clientSocket, (char*)&response, sizeof(response), 0);

        if (bytesReceived <= 0)
        {
            cout << "Server disconnected." << endl;
            break;
        }

        cout << "Server response: " << response << endl;
    }

    closesocket(clientSocket);

    WSACleanup();

    return 0;
}