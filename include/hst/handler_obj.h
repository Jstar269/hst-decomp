/* Object driven by the state handlers around the 0x1d9000 sources: a state id, sub-buffers and two helper objects. */
#ifndef HST_HANDLER_OBJ_H
#define HST_HANDLER_OBJ_H

typedef struct HandlerObj {
  char pad000[0xd4];
  int unkd4;           /* 0xd4 set to 3 together with the state */
  char padd8[0x290 - 0xd8];
  char unk290[0x10];   /* 0x290 buffer passed to a helper */
  char pad2a0[0x514 - 0x2a0];
  int unk514;          /* 0x514 handle updated from the state */
  char pad518[4];
  int unk51c;          /* 0x51c set to 6 when the state is cleared */
  int state;           /* 0x520 current state id */
  char pad524[0x530 - 0x524];
  char unk530[0x10];   /* 0x530 buffer passed to a helper */
  char pad540[0x1110 - 0x540];
  char unk1110[0x8c];  /* 0x1110 embedded helper object with virtual methods */
  void *unk119c;       /* 0x119c object with virtual methods */
} HandlerObj;

#endif
