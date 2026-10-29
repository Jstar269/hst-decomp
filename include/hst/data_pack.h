/* Data-pack object: a mode, a placement transform and tables of named data entries. */
#ifndef HST_DATA_PACK_H
#define HST_DATA_PACK_H

typedef struct PackVec4 {
  float x, y, z, w;
} PackVec4;

typedef struct PackVec3 {
  float x, y, z;
} PackVec3;

/* Four rows plus a translation (0x4c bytes). */
typedef struct PackTransform {
  PackVec4 r[4];
  PackVec3 pos;
} PackTransform;

/* One named entry (0x50 bytes); the payload sits in data or in owned, the other is 0. */
typedef struct DataEntry {
  char name[64];  /* 0x00 */
  void *data;     /* 0x40 */
  void *owned;    /* 0x44 */
  int size;       /* 0x48 */
  int unk4c;      /* 0x4c */
} DataEntry;

/* Growable array of entries. */
typedef struct DataEntryVec {
  DataEntry *data;  /* 0x00 */
  unsigned size;    /* 0x04 */
  unsigned cap;     /* 0x08 */
} DataEntryVec;

/* Growable array of items (element type not known). */
typedef struct PackItemVec {
  void *data;  /* 0x00 */
  int count;   /* 0x04 */
  int cap;     /* 0x08 */
} PackItemVec;

typedef struct DataPack {
  const void *vtable;        /* 0x00 */
  char pad04[0x3c - 4];
  int mode;                  /* 0x3c selects the layout set up by the mode switch */
  int unk40;                 /* 0x40 */
  signed char unk44;         /* 0x44 1 for the lower modes, else 0 */
  char pad45[3];
  PackTransform tf;          /* 0x48 */
  char pad94[0x694 - 0x94];
  int unk694;                /* 0x694 */
  char pad698[0x72c - 0x698];
  void *table72c;            /* 0x72c count * 0x50 bytes */
  char pad730[0x76c - 0x730];
  void *table76c;            /* 0x76c count * 0x18 bytes */
  DataEntryVec entries;      /* 0x770 */
  PackItemVec items;         /* 0x77c */
  int unk788;                /* 0x788 */
  int unk78c;                /* 0x78c */
} DataPack;

#endif
