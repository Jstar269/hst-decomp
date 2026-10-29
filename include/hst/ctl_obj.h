/* Control object with a float level (compared against CTL_LEVEL_MAX), a mode byte and flag bytes; set up by two initialisers. */
#ifndef HST_CTL_OBJ_H
#define HST_CTL_OBJ_H

#define CTL_LEVEL_MAX 31.0f   /* threshold the level is compared against */

typedef struct CtlObj {
  char pad00[4];
  float unk4;                 /* 0x04 */
  float unk8;                 /* 0x08 */
  char pad0c[0x38 - 0xc];
  float level;                /* 0x38 */
  char pad3c[4];
  unsigned char unk40;        /* 0x40 */
  char pad41[0x4c - 0x41];
  unsigned char unk4c;        /* 0x4c */
  unsigned char active;       /* 0x4d */
  unsigned char mode;         /* 0x4e copy of the mode argument */
  char pad4f;
  float start;                /* 0x50 */
  unsigned char unk54;        /* 0x54 */
} CtlObj;

#endif
