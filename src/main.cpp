#include "core/Game.h"

#include "core/network/Server.h"
#include "core/network/Client.h"

#include "core/World.h"

#include <thread>

int main() {
    // Game::run();
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
        Client client("172.30.176.1", 25565);
        client.run();
    }
    Game::run();

    return 0;
}
