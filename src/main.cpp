#include "core/Game.h"

#include "core/network/Server.h"
#include "core/network/Client.h"

#include "core/World.h"

#include <thread>

int main() {
    std::cout << "Host (s) or join (c)? ";
    char choice;
    std::cin >> choice;

    if(choice == 's'){
        std::thread serverThread([](){
            Server server(25565);
            server.run();
        });
        serverThread.detach();
    }
    else if(choice == 'c') {
        std::thread clientThread([]() {
            Client client("192.168.0.131", 25565);
            client.run();
        });
        clientThread.detach();
    }
    Game::run();



    return 0;
}
