/* Layout list object: a widget base followed by a list of placed rectangles. */
#ifndef HST_LAYOUT_LIST_H
#define HST_LAYOUT_LIST_H

#include "hst/types.h"

/* Rectangle written back for each placed item. */
typedef struct LayoutQuad {
  char pad00[4];
  short left;         /* 0x04 */
  short top;          /* 0x06 */
  short right;        /* 0x08 */
  short bottom;       /* 0x0a */
} LayoutQuad;

/* One entry of the list (20 bytes); a null quad is skipped. */
typedef struct LayoutItem {
  LayoutQuad *quad;   /* 0x00 */
  int unk04;          /* 0x04 */
  int x;              /* 0x08 offset from the list origin */
  int y;              /* 0x0c */
  int unk10;          /* 0x10 */
} LayoutItem;

typedef struct LayoutList {
  u32 vtable;         /* 0x00 */
  char pad04[0x2c];
  u8 partA[0x40];     /* 0x30 first sub-object */
  u32 unk70;          /* 0x70 */
  int unk74;          /* 0x74 starts at -1 */
  u32 unk78;          /* 0x78 starts as 1.0f (bit pattern) */
  u32 unk7c;          /* 0x7c starts as 1.0f (bit pattern) */
  u8 partB[0x40];     /* 0x80 second sub-object */
  u32 vtableC0;       /* 0xc0 */
  char padc4[0xc];
  u32 vtableD0;       /* 0xd0 vtable of the list member at 0xd0 */
  u32 unkd4;          /* 0xd4 */
  u32 unkd8;          /* 0xd8 */
  int width;          /* 0xdc */
  int height;         /* 0xe0 */
  int originX;        /* 0xe4 */
  int originY;        /* 0xe8 */
  int scrollY;        /* 0xec */
  char padf0[0x104 - 0xf0];
  int count;          /* 0x104 number of items */
} LayoutList;

#endif
