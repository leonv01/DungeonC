#include "core/Game.h"
#include "core/Network/Networking.h"

#include "core/network/Server.h"
#include "core/network/Client.h"

#include "core/World.h"

int main() {
    Game::run();
    World::players.push_back(Player{{1,1}, {1,1}, 4});

    std::cout << "Server (s) or client (c)? ";
    char choice;
    std::cin >> choice;

    if(choice == 's'){
        Server server(25565);
        server.run();
    }
    else if(choice == 'c') {
        Client client("127.0.0.1", 25565);
        client.run();
    }


    return 0;
}
