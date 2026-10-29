/* C++ object that names an Npc_%03d_%02d resource: two numbers and a lazily looked-up sub record. */
#ifndef HST_NPC_OBJ_H
#define HST_NPC_OBJ_H

#include "hst/mode_obj.h"

/* Looked-up record; only the id is read. */
struct NpcSub {
  char pad00[0x40];
  short id;            /* 0x40 */
};

struct NpcObj : VirtualModeObj {
  char pad04[0x34 - 4];
  int npc_num;         /* 0x34 first number of the Npc_%03d_%02d name */
  int sub_num;         /* 0x38 second number of the name */
  char pad3c[0x60 - 0x3c];
  NpcSub *sub;         /* 0x60 found by name, null until looked up */
};

#endif
