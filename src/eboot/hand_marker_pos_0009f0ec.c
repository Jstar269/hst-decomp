/* HSTMATCH module=EBOOT.BIN start=0x0009f0ec end=0x0009f230 symbol=FUN_0009f0ec lang=c99 data=0x002d45fc */
/* Ghidra pseudocode (hstgen.py tag from inputs/generated/FUN_0009f0ec.c) corrected by hand, from the lane fm5 near miss: restructured into struct members and ternaries, added the dropped leading owner argument (int) to FUN_000937c8; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002d45fc-0x002d4613) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern void FUN_000937c8(int, float, float);
extern void FUN_0009b96c(int);
extern void FUN_000939a4(float *, int, char *);
extern void FUN_00022498(float, float *, float *);
extern void FUN_00022548(float *, float *, float *);

struct Self { char pad[0x150]; int mode; char pad2[0x468]; int owner; };

void FUN_0009f0ec(float *param_1,struct Self *param_2)
{
  float v[4];
  float m[4][4];
  float out[4];
  int p;
  float hi;
  float lo;
  char *name;

  p = *(int *)(param_2->owner + 0x58);
  hi = p != 0 ? *(float *)(p + 0x13c) : 0.0f;
  lo = p != 0 ? *(float *)(p + 0x108) : 0.0f;
  FUN_000937c8(param_2->owner,lo,hi);
  FUN_0009b96c((int)param_2);
  v[0] = 0.066430002450943f;
  v[1] = -0.08136999607086182f;
  v[2] = 0.008729999884963036f;
  v[3] = 1.0f;
  if (param_2->mode == 1) {
    v[0] = v[0] * -1.0f;
  }
  name = param_2->mode == 0 ? "Bip01LHand" : "Bip01RHand";
  FUN_000939a4(m[0],param_2->owner,name);
  FUN_00022498(100.0f,m[0],m[0]);
  FUN_00022498(100.0f,m[1],m[1]);
  FUN_00022498(100.0f,m[2],m[2]);
  FUN_00022548(out,m[0],v);
  param_1[0] = out[0];
  param_1[1] = out[1];
  param_1[2] = out[2];
  param_1[3] = out[3];
}
