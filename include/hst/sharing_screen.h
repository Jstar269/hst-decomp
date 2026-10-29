/* Game-sharing screen object (sub-objects built by its constructor) and its layout pane. */
#ifndef HST_SHARING_SCREEN_H
#define HST_SHARING_SCREEN_H

#include "hst/types.h"

struct SharingWidget; /* layout widget with virtual methods; C++ sources define it */

/* Layout pane (0x70 bytes) loaded from the sharing layout, showing two pages. */
typedef struct SharingPane {
  const void *vtable;              /* 0x00 */
  char pad04[0x54 - 4];
  u8 unk54;                        /* 0x54 */
  u8 unk55;                        /* 0x55 */
  char pad56[2];
  struct SharingWidget *key;       /* 0x58 part of the first page named key040 */
  int state;                       /* 0x5c current state id, set by the state switch */
  struct SharingWidget *page1;     /* 0x60 sub-layout sharing1 */
  struct SharingWidget *page2;     /* 0x64 sub-layout sharing2 */
  int unk68;                       /* 0x68 */
  int unk6c;                       /* 0x6c */
} SharingPane;

typedef struct SharingScreen {
  u32 unk0;                        /* 0x00 copied from the global record at construction */
  char sub4[0x110 - 4];            /* 0x04 sub-object */
  char sub110[0x6f0 - 0x110];      /* 0x110 */
  char sub6f0[0xabc - 0x6f0];      /* 0x6f0 */
  char subabc[0xb48 - 0xabc];      /* 0xabc */
  SharingPane pane;                /* 0xb48 */
  u32 unkbb8;                      /* 0xbb8 */
  u8 unkbbc;                       /* 0xbbc */
  char padbbd[0xbc4 - 0xbbd];
  u8 unkbc4;                       /* 0xbc4 */
  char padbc5[3];
  u32 unkbc8;                      /* 0xbc8 */
} SharingScreen;

#endif
