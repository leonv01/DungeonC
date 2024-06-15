#include "core/Game.h"

#include "core/network/Server.h"
#include "core/network/Client.h"

#include "core/World.h"

#include <thread>

int main() {
    // Game::run();
    World::players.push_back(Player{{1,1}, {1,1}, 4});

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
        Client client("127.0.0.1", 25565);
        client.run();
    }

    std::cout << "Test " << World::players[0].getX() << std::endl;

    Game::run();

    return 0;
}
