/* Slot manager: a list of slot entries plus the value tables and flags they are applied with. */
#ifndef HST_SLOT_MGR_H
#define HST_SLOT_MGR_H

#define VALUE_UNSET 0x7fffffff /* marks an unset entry in a value record */

/* Model object a slot entry points at; only its id is read. */
typedef struct SlotObj {
  char pad00[0x1b4];
  int id;              /* 0x1b4 */
} SlotObj;

typedef struct SlotEntry {
  char pad00[4];
  int unk4;            /* 0x04 */
  char pad08[8];
  int sub[0x14];       /* 0x10 sub-object with virtual show/hide slots */
  SlotObj *obj;        /* 0x60 */
} SlotEntry;

/* Settings record returned by the settings accessor: the limits SlotMgr.value is clamped to and a position vector. */
typedef struct SlotSettings {
  float unk00;         /* 0x00 */
  char pad04[0x18];
  float lo;            /* 0x1c lower limit of SlotMgr.value */
  float hi;            /* 0x20 upper limit */
  float pos[3];        /* 0x24 position (x, y, z) */
} SlotSettings;

typedef struct SlotMgr {
  char pad00[4];
  int cur;             /* 0x04 index of the current entry */
  SlotEntry **entries; /* 0x08 */
  char pad0c[8];
  int **items;         /* 0x14 */
  unsigned count;      /* 0x18 number of items */
  char pad1c[0x34 - 0x1c];
  float unk34;         /* 0x34 */
  char pad38[0x41 - 0x38];
  unsigned char unk41; /* 0x41 */
  char pad42[2];
  int unk44;           /* 0x44 */
  char pad48[4];
  float value;         /* 0x4c clamped by the limits of the settings record */
  int unk50;           /* 0x50 */
  int unk54;           /* 0x54 */
  char pad58[4];
  char sub5c[0x140];   /* 0x5c lookup table object; its value records start at 0x64, 0x20 bytes each */
  int unk19c;          /* 0x19c */
  char sub1a0[0x140];  /* 0x1a0 */
  int unk2e0;          /* 0x2e0 */
  char sub2e4[4];      /* 0x2e4 */
} SlotMgr;

#endif
