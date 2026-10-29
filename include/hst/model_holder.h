/* Loaded model stream and the 0x1b0-byte model holder that renders it (the 0x28a000 and 0x293000 sources). */
#ifndef HST_MODEL_HOLDER_H
#define HST_MODEL_HOLDER_H

#define MODEL_HOLDER_SIZE 0x1b0   /* bytes allocated for one holder */
#define I3R_STREAM_SIZE 0x30      /* bytes allocated for one stream */

/* Model resource loaded from an .i3r file. */
typedef struct I3rStream {
  char pad00[8];
  int unk8;                   /* 0x08 resource handle, zero when the load failed */
} I3rStream;

/* Track item whose float value is read back by the update code. */
typedef struct HolderItem {
  char pad00[8];
  float value;                /* 0x08 */
} HolderItem;

typedef struct ModelNode {
  HolderItem *item;            /* 0x00 */
} ModelNode;

/* Polymorphic holder; slot 1 of its vtable attaches a stream. Only the used fields are named. */
typedef struct ModelHolder {
  void *vtable;               /* 0x00 */
  char pad04[0xc0 - 4];
  unsigned char unkc0;        /* 0xc0 */
  char padc1[3];
  float unkc4;                /* 0xc4 */
  char padc8[4];
  float unkcc;                /* 0xcc */
  float unkd0;                /* 0xd0 */
  char padd4[0xf4 - 0xd4];
  ModelNode *node;            /* 0xf4 */
  char padf8[0x100 - 0xf8];
  float unk100;               /* 0x100 */
  float unk104;               /* 0x104 */
  char pad108[0x158 - 0x108];
  int unk158;                 /* 0x158 */
  int unk15c;                 /* 0x15c */
} ModelHolder;

#endif
