#pragma once

#define CSTRIKE_WINDOW_NAME "Counter-Strike"
#define HWDLL "hw.dll"
#define CLDLL "client.dll"

#define PLAYER_BASE 0x1AFFA8
#define PLAYER_COORDINATE_OFFSET -8
#define PLAYER_VIEW_OFFSET 0x10569A4

#define ENEMY_BASE 0x11D01FC + 0x8C
#define ENEMY_NUMBER_MULTIPLICATION_OFFSET 0x250
#define ENEMY_COORDINATE_OFFSET -8
#define ENEMY_ALIVE_OFFSET -20