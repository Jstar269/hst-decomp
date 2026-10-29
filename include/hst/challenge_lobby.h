/* Challenge lobby object (the global singleton): the menu it owns, two helper objects, the lobby state id and flag bytes. */
#ifndef HST_CHALLENGE_LOBBY_H
#define HST_CHALLENGE_LOBBY_H

#include "hst/types.h"

/* Owned objects; C++ sources define them with the virtual calls they use. */
struct LobbyMenu;    /* the challenge menu */
struct LobbyHelper4; /* helper object at 0x04 */
struct LobbyHelper8; /* helper object at 0x08 */

typedef struct ChallengeLobby {
  struct LobbyMenu *menu; /* 0x00 menu object (allocated 0x2f0 bytes) */
  struct LobbyHelper4 *unk4; /* 0x04 allocated 0x78 bytes */
  struct LobbyHelper8 *unk8; /* 0x08 allocated 0xa0 bytes */
  int state;              /* 0x0c lobby state id; the state switch sets it */
  u8 unk10;               /* 0x10 */
  u8 unk11;               /* 0x11 */
  u8 unk12;               /* 0x12 */
} ChallengeLobby;

/* State id the lobby starts in. */
#define LOBBY_STATE_INITIAL 9

#endif
