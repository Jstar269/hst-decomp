/* Character-select screen object: layout pointer, rectangle table pointers, nine bound sub-objects, three element arrays. */
#ifndef HST_CHRSEL_SCREEN_H
#define HST_CHRSEL_SCREEN_H

#define CHRSEL_SLOT_COUNT 4      /* owned objects released in the destructor loop */
#define CHRSEL_BOUND_SIZE 0x8c   /* bytes per bound sub-object */
#define CHRSEL_ELEM_SIZE 0xc     /* bytes per element of the trailing arrays */
#define CHRSEL_ELEM_COUNT 10     /* elements per trailing array */

/* Rectangle record: four shorts after a 4-byte header. */
typedef struct ChrSelRect {
  char pad0[4];
  short a, b, c, d;
} ChrSelRect;

struct ChrSelPanel;
struct ChrSelPart;

typedef struct ChrSelScreen {
  const void *vtable;                     /* 0x0000 */
  void *unk04;                            /* 0x0004 */
  void *unk08;                            /* 0x0008 */
  char pad0c[4];
  void *layout;                           /* 0x0010 owned object, deleted by the destructor */
  void *group14;                          /* 0x0014 */
  char pad18[8];
  void *unk20;                            /* 0x0020 */
  void *unk24;                            /* 0x0024 */
  struct ChrSelPart *part28;              /* 0x0028 */
  void *unk2c;                            /* 0x002c */
  void *unk30;                            /* 0x0030 */
  void *unk34;                            /* 0x0034 */
  void *unk38;                            /* 0x0038 */
  char pad3c[8];
  char sub44[CHRSEL_BOUND_SIZE];          /* 0x0044 */
  int unkd0;                              /* 0x00d0 */
  char pad0d4[0x90c];
  ChrSelRect *rect9e0;                    /* 0x09e0 */
  char pad9e4[0x10];
  ChrSelRect *rect9f4;                    /* 0x09f4 */
  char pad9f8[0x178];
  ChrSelRect *rectb70;                    /* 0x0b70 */
  char padb74[0x40c];
  ChrSelRect *rectf80;                    /* 0x0f80 */
  char padf84[0x178];
  char sub10fc[0x84];                     /* 0x10fc */
  struct ChrSelPanel *panel;              /* 0x1180 */
  int unk1184;                            /* 0x1184 */
  char pad1188[0xa0];
  void *slots[CHRSEL_SLOT_COUNT];         /* 0x1228 owned objects, deleted by the destructor */
  int unk1238;                            /* 0x1238 */
  int unk123c;                            /* 0x123c */
  char pad1240[0x14];
  char s1254[CHRSEL_BOUND_SIZE];          /* 0x1254 */
  char s12e0[CHRSEL_BOUND_SIZE];          /* 0x12e0 */
  char s136c[CHRSEL_BOUND_SIZE];          /* 0x136c */
  char s13f8[CHRSEL_BOUND_SIZE];          /* 0x13f8 */
  char s1484[CHRSEL_BOUND_SIZE];          /* 0x1484 */
  char s1510[CHRSEL_BOUND_SIZE];          /* 0x1510 */
  char s159c[CHRSEL_BOUND_SIZE];          /* 0x159c */
  char s1628[CHRSEL_BOUND_SIZE];          /* 0x1628 */
  char s16b4[CHRSEL_BOUND_SIZE];          /* 0x16b4 */
  char pad1740[0x28b0 - 0x1740];
  char arrA[CHRSEL_ELEM_SIZE * CHRSEL_ELEM_COUNT];/* 0x28b0 */
  char arrB[CHRSEL_ELEM_SIZE * CHRSEL_ELEM_COUNT];/* 0x2928 */
  char arrC[CHRSEL_ELEM_SIZE * CHRSEL_ELEM_COUNT];/* 0x29a0 */
} ChrSelScreen;

#endif
