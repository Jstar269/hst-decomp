/* HSTMATCH module=EBOOT.BIN start=0x001f4050 end=0x001f41e8 symbol=FUN_001f4050 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: C++ with Vec4/Mat4 (user ctor) views, the four DAT floats are one extern const Vec4 copied as a unit (retail's pipelined copy), the three sums and the count initialised before it, the translation floats read into locals declared z,y,x but assigned x,y,z before the first-iteration test (matching idiom: it decouples the f1..f3 numbering from the load order), the count kept as a float local for the three divides, and the flag passed as unsigned char (flag != 0) ^ 1; readability pass; exact match verified; names and types await human review. */
#include "hst/slot_group.h"
struct Vec4 { float x, y, z, w; Vec4() {} };
struct Mat4 { Vec4 r[4]; };
struct Node { char pad[0x50]; Vec4 pos; };
struct Slot { char pad[0x58]; Node *node; };
struct Group {
  char pad0[0x3a0];
  Slot *slots[SLOT_GROUP_COUNT];
  int slot_ids[SLOT_GROUP_COUNT];
  char pad3b0[0x521 - 0x3b0 - 16];
  unsigned char flag;
  char pad522[0x584 - 0x522];
  void *target;
};
extern const Vec4 DAT_002bc430;
extern char DAT_002ee8d0[];
extern "C" void FUN_0005548c(Mat4 *out, Node *node, const char *name);
extern "C" void FUN_001ed4a8(void *a, Vec4 *avg, Vec4 *pos, unsigned char flag);
extern "C" void FUN_001f37e4(Group *o, Slot *slot, int id, int idx, int a, int b);

/* Average the slots' pelvis translations and report the average and the first slot's node position to the target. */
extern "C" void FUN_001f4050(Group *group)
{
  float sumx;
  float sumy;
  float sumz;
  Vec4 avg;
  Vec4 pos;
  Mat4 pelvis_mat;
  int count;
  int i;

  sumx = 0.0f;
  sumy = 0.0f;
  sumz = 0.0f;
  avg.x = 0.0f;
  avg.y = 0.0f;
  avg.z = 0.0f;
  avg.w = 0.0f;
  pos = DAT_002bc430;
  count = 0;
  for (i = 0; i < SLOT_GROUP_COUNT; i++) {
    Slot *slot = group->slots[i];
    Node *node = slot ? slot->node : 0;
    if (node != 0) {
      if (group->flag != 0) {
        FUN_001f37e4(group, slot, group->slot_ids[i], i, 6, 0);
      }
      FUN_0005548c(&pelvis_mat, node, DAT_002ee8d0);
      float tz;
      float ty;
      float tx;
      tx = pelvis_mat.r[3].x;
      ty = pelvis_mat.r[3].y;
      tz = pelvis_mat.r[3].z;
      if (count == 0) {
        pos.x = node->pos.x;
        pos.y = node->pos.y;
        pos.z = node->pos.z;
        pos.w = node->pos.w;
      }
      sumx = sumx + tx;
      count = count + 1;
      sumy = sumy + ty;
      sumz = sumz + tz;
    }
  }
  float count_f = (float)count;
  avg.w = 1.0f;
  avg.x = sumx / count_f;
  avg.y = sumy / count_f;
  avg.z = sumz / count_f;
  FUN_001ed4a8(group->target, &avg, &pos, (group->flag != 0) ^ 1);
}
