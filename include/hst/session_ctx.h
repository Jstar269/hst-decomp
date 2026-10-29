/* Context object reached through a global pointer: a flag byte, a mode word and an index word. */
#ifndef HST_SESSION_CTX_H
#define HST_SESSION_CTX_H

typedef struct SessionCtx {
  char pad00[0x5c];
  unsigned char unk5c;  /* 0x5c flag byte */
  char pad5d[4];
  unsigned char unk61;  /* 0x61 flag byte */
  char pad62[0x90 - 0x62];
  int mode;             /* 0x90 switched on by the counter step (0, 1, 2, other) */
  char pad94[0x9c - 0x94];
  unsigned unk9c;       /* 0x9c compared with the owner's index word */
} SessionCtx;

#endif
