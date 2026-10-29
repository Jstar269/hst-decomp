/* Online game object: frame counter and the link object it owns. */
#ifndef HST_ONLINE_GAME_H
#define HST_ONLINE_GAME_H

typedef struct OnlineLink {
  char pad00[4];
  unsigned char flag;        /* 0x04 set when the peer reports ready */
} OnlineLink;

typedef struct OnlineGame {
  char pad000[0x780];
  int frame;                 /* 0x780 incremented once per update */
  OnlineLink *link;          /* 0x784 */
} OnlineGame;

#endif
