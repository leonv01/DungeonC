//
// Created by leonv on 14.06.2024.
//

#ifndef DUNGEONC_RESOURCES_H
#define DUNGEONC_RESOURCES_H

namespace Texture {
    enum ID{
        PLAYER,
        ENEMY,
        WALL,
        FLOOR,
        DOOR,
    };
}

namespace Sound{
    enum ID{
        PLAYER_ATTACK,
        PLAYER_DAMAGE,
        PLAYER_DEATH,
        ENEMY_ATTACK,
        ENEMY_DAMAGE,
        ENEMY_DEATH,
        DOOR_OPEN,
        DOOR_CLOSE,
    };
}

namespace Music{
    enum ID{
        MAIN_THEME,
    };
}

namespace Font{
    enum ID{
        MAIN_FONT,
    };
}


#endif //DUNGEONC_RESOURCES_H
