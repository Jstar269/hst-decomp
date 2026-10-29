/* Lobby stage object: the lobby and room indices and the name table used to build its data file paths. */
#ifndef HST_LOBBY_STAGE_H
#define HST_LOBBY_STAGE_H

#define LOBBY_STAGE_PRIMARY_OFFSET 0x1320  /* distance from the secondary base to the primary object (thunks adjust by it) */

typedef struct LobbyStage {
  char pad0000[0x1390];
  int lobby;            /* 0x1390 zero-based lobby index (paths use lobby + 1) */
  int room;             /* 0x1394 zero-based room index (paths use room + 1) */
  void *names;          /* 0x1398 table that maps the lobby index to its folder name */
} LobbyStage;

#endif
