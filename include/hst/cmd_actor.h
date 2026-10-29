/* Actor driven by a queue of timed commands (vtable DAT_00309cac): resource, position, flags and the command list. */
#ifndef HST_CMD_ACTOR_H
#define HST_CMD_ACTOR_H

#include "hst/menu_state.h" /* Vec4 */

/* Doubly linked list links; in the command list each queued node continues with its command record. */
typedef struct CmdLink {
  struct CmdLink *prev;         /* 0x00 */
  struct CmdLink *next;         /* 0x04 */
} CmdLink;

typedef struct CmdActor {
  void *vtbl;                   /* 0x00 */
  void *res;                    /* 0x04 resource loaded from a file (FUN_00286938), freed with FUN_0014c028 */
  void *objA;                   /* 0x08 36-byte object (FUN_00286d08) */
  void *objB;                   /* 0x0c 36-byte object (FUN_00286d08) */
  char *name;                   /* 0x10 copy of the resource name */
  char pad14[0xc];
  Vec4 pos;                     /* 0x20 */
  int unk30;
  int unk34;
  int unk38;
  int unk3c;                    /* 0x3c lookup result inside res, -1 when none */
  int unk40;
  float unk44;
  float unk48;
  int unk4c;
  float unk50;
  unsigned char unk54;
  unsigned char enabled;        /* 0x55 */
  unsigned char unk56;
  unsigned char unk57;
  unsigned char unk58;
  unsigned char unk59;
  unsigned char unk5a;
  unsigned char unk5b;
  unsigned char unk5c;
  char pad5d[3];
  int unk60;
  char alloc64[4];              /* 0x64 allocator tag of the command list */
  CmdLink head;                 /* 0x68 list sentinel */
} CmdActor;

#endif
