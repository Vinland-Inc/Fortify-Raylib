#pragma once
#include <string>
#include <vector>
#include "raylib.h"

struct LevelConfig
{
    int id;
    std::string name;
    std::string mapPath;
    const char* mapTexturePath;
    std::vector<std::vector<Vector2>> waypoints; // путей для врагов может быть несколько
    int enemyCount;

    static LevelConfig GetConfigById(int id)
    {
        if (id == 1)
        {
            return
            {
                1,
                "Level 1",
                "src/levels/.level_01.txt",
                "sprites/map/spritesheet.png",
                {
                    { {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0} }
                },
                10
            };
        }
        else if (id == 2)
        {
            return
            {
                2,
                "Level 2",
                "src/levels/.level_02.txt",
                "sprites/map/spritesheet.png",
                {
                    { {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0} }
                },
                15
            };
        }
        else if (id == 3)
        {
            return
            {
                3,
                "Level 3",
                "src/levels/.level_03.txt",
                "sprites/map/spritesheet.png",
                {
                    { {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0} },
                    { {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0} }
                },
                20
            };
        }
        else if (id == 4)
        {
            return
            {
                4,
                "Level 4",
                "src/levels/.level_04.txt",
                "sprites/map/spritesheet.png",
                {
                    { {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0} }
                },
                40
            };
        }
        else if (id == 5)
        {
            return
            {
                5,
                "Level 5",
                "src/levels/.level_05.txt",
                "sprites/map/spritesheet.png",
                {
                    { {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0} },
                    { {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0} },
                    { {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0} }
                },
                20
            };
        }
        else if (id == 6)
        {
            return
            {
                6,
                "Level 6",
                "src/levels/.level_06.txt",
                "sprites/map/spritesheet.png",
                {
                    { {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0} },
                    { {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0} },
                    { {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0} }
                },
                20
            };
        }
        else if (id == 7)
        {
            return
            {
                7,
                "Level 7",
                "src/levels/.level_07.txt",
                "sprites/map/spritesheet.png",
                {
                    { {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0} },
                    { {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0} },
                    { {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0} }
                },
                20
            };
        }
        else if (id == 8)
        {
            return
            {
                8,
                "Level 8",
                "src/levels/.level_08.txt",
                "sprites/map/spritesheet.png",
                {
                    { {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0} },
                    { {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0} },
                    { {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0} }
                },
                20
            };
        }

        return {0, "unknown", "unknown", "unknown", {{{0, 0}}}, 0};
    }
};
