/* HSTMATCH module=hstp_trans_main.prx start=0x002b0ca4 end=0x002b0e58 symbol=FUN_002b0ca4 lang=c99 */
/* Clone of src/eboot/setup_entry_002a1898.c (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed struct views and prototypes (the float-argument calls FUN_00058814/FUN_000587ac/FUN_00059ba8 and the float-returning clamp); exact match verified; names and types await human review. */

typedef struct Sub_002b0ca4 {
  char pad[0x78];
  float f78;
} Sub_002b0ca4;

typedef struct Inner_002b0ca4 {
  char pad0[0x5c];
  Sub_002b0ca4 *f5c;
  char pad60[8];
  int f68;
  int f6c;
  unsigned char f70;
  char pad71[3];
  int f74;
} Inner_002b0ca4;

typedef struct Arg_002b0ca4 {
  int f0;
  int f4;
  int f8;
} Arg_002b0ca4;

typedef struct Obj_002b0ca4 {
  char pad0[0x1c8];
  Inner_002b0ca4 *f1c8;
  char pad1[0x1e0 - 0x1cc];
  int f1e0;
  unsigned char f1e4;
} Obj_002b0ca4;

extern float DAT_003a9688;
extern float DAT_003a969c;
extern float DAT_003a96a0;
extern float DAT_003a96a4;
extern float DAT_003a96a8;
extern void FUN_000587ac(Obj_002b0ca4 *, int, int, float);
extern void FUN_00058814(Obj_002b0ca4 *, int, int, float, float, float);
extern void FUN_00059ac0(Obj_002b0ca4 *, int, int);
extern void FUN_00059ba8(Obj_002b0ca4 *, int, float);
extern void FUN_00059d68(Obj_002b0ca4 *, int);
extern void FUN_00108dac(Inner_002b0ca4 *);
extern void FUN_0011fc80(int);
extern float FUN_001dc444(float *, float *, float *);
extern Sub_002b0ca4 *FUN_001dfd84(Inner_002b0ca4 *, int);
extern void FUN_001dff28(Sub_002b0ca4 *);
extern void FUN_001e3fe8(int);
extern void FUN_002aff90(Inner_002b0ca4 *, int);
extern void FUN_002b07a4(Obj_002b0ca4 *, int, int);
extern void FUN_002b0a68(Obj_002b0ca4 *, int);
extern void FUN_002b0e58(int *, int);

void FUN_002b0ca4(Obj_002b0ca4 *param_1, Arg_002b0ca4 *param_2, unsigned char param_3)
{
  Inner_002b0ca4 *in;
  int iVar1;
  float fVar5;
  float local_4;
  float local_8;

  iVar1 = param_2->f0;
  in = param_1->f1c8;
  FUN_002aff90(in, 1);
  FUN_002b0e58(&in->f74, iVar1);
  FUN_001dff28(in->f5c);
  FUN_001e3fe8(in->f68);
  FUN_0011fc80(in->f6c);
  in->f70 = param_3;
  local_4 = DAT_003a9688 + FUN_001dfd84(in, 0)->f78;
  fVar5 = FUN_001dc444(&local_4, &DAT_003a969c, &DAT_003a96a0);
  FUN_001dfd84(in, 0)->f78 = fVar5;
  local_8 = in->f5c->f78 + DAT_003a9688;
  fVar5 = FUN_001dc444(&local_8, &DAT_003a96a4, &DAT_003a96a8);
  in->f5c->f78 = fVar5;
  FUN_00108dac(in);
  param_1->f1e4 = 1;
  FUN_002b0a68(param_1, param_2->f8);
  iVar1 = param_2->f4;
  param_1->f1e0 = iVar1;
  if (iVar1 == 0xe) {
    FUN_00058814(param_1, 1, -1, 0.0f, 0.0f, 0.0f);
    FUN_000587ac(param_1, 1, iVar1, 0.0f);
  } else {
    FUN_002b07a4(param_1, 1, iVar1);
  }
  FUN_00059ac0(param_1, 1, 1);
  FUN_00059ba8(param_1, 1, 1.0f);
  FUN_00059d68(param_1, 1);
}
