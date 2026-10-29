/* Rectangle page object (C++ only): the element arrays and the entry list that the entry-queue and rectangle-setup sources fill. */
#ifndef HST_RECT_PAGE_H
#define HST_RECT_PAGE_H

#define RECT_PAGE_SMALL 6      /* elements in each of the two small arrays */
#define RECT_PAGE_WIDE 12      /* elements in the wide array and its value table */
#define RECT_PAGE_ENTRIES 10   /* entries in the entry list */

struct PageDev {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void m3();
};

/* Element with a rectangle given by its top-left and bottom-right corners. */
struct RectElem {
  int unk00;
  short x;           /* 0x04 */
  short y;           /* 0x06 */
  short x2;          /* 0x08 */
  short y2;          /* 0x0a */
  char pad0c[0x24 - 0x0c];
  int unk24;         /* 0x24 */
  int unk28;         /* 0x28 */
};

/* One queued entry: a type tag and the rectangle origin and size. */
struct RectEntry {
  int type;          /* 0x00 */
  int x;             /* 0x04 */
  int y;             /* 0x08 */
  float w;           /* 0x0c */
  float h;           /* 0x10 */
};

struct RectPage {
  PageDev *dev;                          /* 0x00 */
  RectElem *small[RECT_PAGE_SMALL];      /* 0x04 */
  RectElem *spr[RECT_PAGE_SMALL];        /* 0x1c */
  void *unk34[RECT_PAGE_SMALL];          /* 0x34 */
  RectElem *wide[RECT_PAGE_WIDE];        /* 0x4c */
  char pad7c[0xc4 - 0x7c];
  int vals[RECT_PAGE_WIDE];              /* 0xc4 */
  RectEntry ent[RECT_PAGE_ENTRIES];      /* 0xf4 */
  int count;                             /* 0x1bc, entries in use */
};

#endif
