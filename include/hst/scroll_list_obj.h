/* List screen object with a 16-row window cursor (row, first visible index) and the fields that drive it. */
#ifndef HST_SCROLL_LIST_OBJ_H
#define HST_SCROLL_LIST_OBJ_H

#define SCROLL_LIST_ROWS 16 /* visible rows in the window */

typedef struct ScrollListObj {
  char pad00[0x2f8];
  int kind;      /* 0x2f8 selects which of the two index sources applies (4 or 6 picks unk300) */
  int unk2fc;    /* 0x2fc */
  int unk300;    /* 0x300 */
  int unk304;    /* 0x304 */
  int count;     /* 0x308 number of list entries */
  char pad30c[0x31c - 0x30c];
  int unk31c;    /* 0x31c */
  int unk320;    /* 0x320 */
  char pad324[0x35c - 0x324];
  int row;       /* 0x35c cursor row inside the window */
  int unk360;    /* 0x360 */
  int top;       /* 0x364 first visible index */
} ScrollListObj;

#endif
