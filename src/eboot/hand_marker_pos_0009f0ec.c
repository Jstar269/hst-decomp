/* HSTMATCH module=EBOOT.BIN start=0x0009f0ec end=0x0009f230 symbol=FUN_0009f0ec lang=c99 data=0x002d45fc */
/* Ghidra pseudocode (hstgen.py tag from inputs/generated/FUN_0009f0ec.c) corrected by hand, from the lane fm5 near miss: restructured into struct members and ternaries, added the dropped leading owner argument (int) to FUN_000937c8; readability pass; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002d45fc-0x002d4613) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/rig_obj.h"

extern void FUN_000937c8(void *, float, float);
extern void FUN_0009b96c(RigObj *);
extern void FUN_000939a4(float *, void *, char *);
extern void FUN_00022498(float, float *, float *);
extern void FUN_00022548(float *, float *, float *);

/* Part of the model that carries two float settings. */
typedef struct ModelPart {
  char pad00[0x108];
  float unk108;     /* 0x108 */
  char pad10c[0x13c - 0x10c];
  float unk13c;     /* 0x13c */
} ModelPart;

/* Model view: only the part pointer at +0x58 is read. */
typedef struct ModelView {
  char pad00[0x58];
  ModelPart *part;  /* 0x58 */
} ModelView;

/* Position of the hand marker: a fixed offset (mirrored for the right hand) transformed by the hand bone's matrix. */
void FUN_0009f0ec(float *dst,RigObj *obj)
{
  float v[4];
  float m[4][4];
  float out[4];
  ModelPart *part;
  float hi;
  float lo;
  char *name;

  part = ((ModelView *)obj->model)->part;
  hi = part != 0 ? part->unk13c : 0.0f;
  lo = part != 0 ? part->unk108 : 0.0f;
  FUN_000937c8(obj->model,lo,hi);
  FUN_0009b96c(obj);
  v[0] = 0.066430002450943f;
  v[1] = -0.08136999607086182f;
  v[2] = 0.008729999884963036f;
  v[3] = 1.0f;
  if (obj->hand == 1) {
    v[0] = v[0] * -1.0f;
  }
  name = obj->hand == 0 ? "Bip01LHand" : "Bip01RHand";
  FUN_000939a4(m[0],obj->model,name);
  FUN_00022498(100.0f,m[0],m[0]);
  FUN_00022498(100.0f,m[1],m[1]);
  FUN_00022498(100.0f,m[2],m[2]);
  FUN_00022548(out,m[0],v);
  dst[0] = out[0];
  dst[1] = out[1];
  dst[2] = out[2];
  dst[3] = out[3];
}
