/* Camera object that loads its per-mode settings from commoncamera.csv, and its settings entry. */
#ifndef HST_PRIZE_CAMERA_H
#define HST_PRIZE_CAMERA_H

#define PRIZE_CAM_ENTRY_COUNT 2 /* settings rows loaded from the csv, one per mode (csv ids 1 and 2) */

typedef struct PrizeVec4 {
  float x, y, z, w;
} __attribute__((aligned(16))) PrizeVec4;

/* One settings row; the field names are the csv column names (angles in radians). */
typedef struct PrizeCamEntry {
  float rot_speed;        /* 0x00 RotSpeed */
  float tilt;             /* 0x04 Tilt */
  float tilt_win;         /* 0x08 TiltWin */
  float distance;         /* 0x0c Distance */
  float fov_x;            /* 0x10 FovX */
  float offset_y;         /* 0x14 OffsetY */
  float near_plane;       /* 0x18 Near */
  float far_plane;        /* 0x1c Far */
  float default_angle_y;  /* 0x20 DefaultAngleY */
} PrizeCamEntry;          /* size 0x24 */

typedef struct PrizeCamera {
  const void *vtable;               /* 0x00 */
  char pad04[0x40 - 0x04];
  PrizeVec4 eye;                    /* 0x40 */
  char pad50[0x60 - 0x50];
  PrizeVec4 target;                 /* 0x60 */
  char pad70[0x80 - 0x70];
  float fov_x;                      /* 0x80 copied from the selected entry */
  float near_plane;                 /* 0x84 */
  float far_plane;                  /* 0x88 */
  char pad8c[0x90 - 0x8c];
  void *res;                        /* 0x90 csv reader, deleted by the destructor helper */
  int unk94;                        /* 0x94 */
  unsigned char unk98;              /* 0x98 */
  char pad99[0x9c - 0x99];
  PrizeCamEntry ent[PRIZE_CAM_ENTRY_COUNT]; /* 0x9c */
  int sel;                          /* 0xe4 index of the selected entry */
  unsigned char unke8;              /* 0xe8 */
  unsigned char unke9;              /* 0xe9 */
  unsigned char unkea;              /* 0xea */
} PrizeCamera;

#endif
