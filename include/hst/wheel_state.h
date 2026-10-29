/* State object with a nine-slot ring of entries (0x70 bytes each from offset 0x80) and the host that owns a flag. */
#ifndef HST_WHEEL_STATE_H
#define HST_WHEEL_STATE_H

enum { WHEEL_SLOTS = 9 };

typedef struct WheelVec4 {
  float x, y, z, w;
} WheelVec4;

typedef struct WheelEntry {
  WheelVec4 unk00;    /* 0x00 */
  WheelVec4 unk10;    /* 0x10 */
  float unk20;          /* 0x20 */
  float unk24;          /* 0x24 */
  float unk28;          /* 0x28 */
  float unk2c;          /* 0x2c */
  int unk30;            /* 0x30 */
  short unk34;          /* 0x34 */
  signed char unk36;    /* 0x36 */
  signed char unk37;    /* 0x37 */
  int unk38;            /* 0x38 */
  char pad3c[4];
  int unk40;            /* 0x40 */
  char pad44[0x0c];
  int unk50;            /* 0x50 */
  int unk54;            /* 0x54 */
  int unk58;            /* 0x58 */
  int unk5c;            /* 0x5c */
  unsigned char unk60;  /* 0x60 */
  signed char unk61;    /* 0x61 */
  char pad62[0x0e];
} WheelEntry;

typedef struct WheelState {
  char pad00[0x3c];
  int unk3c;            /* 0x3c */
  unsigned char unk40;  /* 0x40 */
  char pad41[0x4c - 0x41];
  unsigned char unk4c;  /* 0x4c */
  char pad4d[3];
  int unk50;            /* 0x50 */
  unsigned char unk54;  /* 0x54 */
  char pad55[3];
  int unk58;            /* 0x58 */
  int unk5c;            /* 0x5c current ring index */
  int unk60;            /* 0x60 */
  int unk64;            /* 0x64 */
  int unk68;            /* 0x68 */
  int unk6c;            /* 0x6c */
  int unk70;            /* 0x70 */
  char pad74[0x0c];
  WheelEntry ring[WHEEL_SLOTS]; /* 0x80 */
} WheelState;

/* Host object with a flag byte at 0x79 of its member at 0x80. */
typedef struct WheelFlag {
  char pad00[0x79];
  unsigned char unk79;  /* 0x79 */
} WheelFlag;

typedef struct WheelHost {
  char pad00[0x80];
  WheelFlag *unk80;   /* 0x80 */
} WheelHost;

#endif
