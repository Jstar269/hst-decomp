/* HSTMATCH module=hstp_trans_main.prx start=0x00287d7c end=0x00288828 symbol=FUN_00287d7c lang=c99 */
/* Clone of src/eboot/update_five_gauges_00276bcc.c (hstclone.py tag c155507): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed struct members, flipped mirrored float comparisons, and inline span difference `(float)(param_1->f9e4 - param_1->f9e0)`; exact match verified; names and types await human review. */

extern char DAT_003a70d0[];
extern char DAT_003a70dc[];
extern char DAT_003a70e8[];
extern char DAT_003a70f4[];
extern char DAT_003a7100[];
extern char DAT_003a710c[];
extern char DAT_003a7118[];
extern char DAT_003a7120[];
extern char DAT_003a7128[];
extern char DAT_003a7134[];
extern char DAT_003a7140[];
extern char DAT_003a714c[];
extern char DAT_003a7158[];
extern char DAT_003a7164[];
extern char DAT_003a7170[];
extern char DAT_003a717c[];
extern char DAT_003a7188[];
extern char DAT_003a7194[];

typedef struct {
  char pad0[4];
  short f4;
  char pad1[2];
  short f8;
  char pad2[0x24 - 0x0a];
  int f24;
  int f28;
} Widget_00287d7c;

typedef struct {
  char pad0[0x48c];
  void *f48c;
  char pad1[0x99c - 0x490];
  float f99c;
  float f9a0;
  float f9a4;
  float f9a8;
  float f9ac;
  char pad2[0x9b8 - 0x9b0];
  short f9b8;
  char pad3[0x9e0 - 0x9ba];
  short f9e0;
  char pad4[2];
  short f9e4;
} Self_00287d7c;

typedef struct {
  char pad0[0x1c];
  float f1c;
  float f20;
  float f24;
  float f28;
  float f2c;
} Param2_00287d7c;

extern void FUN_00105470(Widget_00287d7c *, int);
extern Widget_00287d7c *FUN_00108124(void *, char *);

void FUN_00287d7c(Self_00287d7c *param_1, Param2_00287d7c *param_2)
{
  Widget_00287d7c *uVar1;
  Widget_00287d7c *iVar2;
  float fVar3;
  float fVar6;

  uVar1 = FUN_00108124(param_1->f48c,DAT_003a70d0);
  FUN_00105470(uVar1,1);
  uVar1 = FUN_00108124(param_1->f48c,DAT_003a70dc);
  FUN_00105470(uVar1,1);
  uVar1 = FUN_00108124(param_1->f48c,DAT_003a70e8);
  FUN_00105470(uVar1,1);
  uVar1 = FUN_00108124(param_1->f48c,DAT_003a70f4);
  FUN_00105470(uVar1,1);
  uVar1 = FUN_00108124(param_1->f48c,DAT_003a7100);
  FUN_00105470(uVar1,1);
  uVar1 = FUN_00108124(param_1->f48c,DAT_003a710c);
  FUN_00105470(uVar1,1);
  uVar1 = FUN_00108124(param_1->f48c,DAT_003a7118);
  FUN_00105470(uVar1,1);
  uVar1 = FUN_00108124(param_1->f48c,DAT_003a7120);
  FUN_00105470(uVar1,1);

  uVar1 = FUN_00108124(param_1->f48c,DAT_003a7128);
  if (param_1->f99c >= 0.0f) {
    FUN_00105470(uVar1,1);
  }
  uVar1 = FUN_00108124(param_1->f48c,DAT_003a7134);
  if (param_1->f99c <= 0.0f) {
    FUN_00105470(uVar1,1);
  }
  fVar6 = param_2->f1c;
  if (fVar6 < 0.0f) {
    fVar3 = fVar6 - (param_1->f99c * 2.0f) / (float)(param_1->f9e4 - param_1->f9e0);
    if ((int)fVar3 == 0) {
      param_1->f99c = (fVar6 * (float)(param_1->f9e4 - param_1->f9e0)) / 2.0f;
    }
    else if (fVar3 < 0.0f) {
      param_1->f99c -= 2.0f;
    }
    else {
      param_1->f99c += 2.0f;
    }
  }
  else {
    fVar3 = fVar6 - (param_1->f99c * 2.0f) / (float)(param_1->f9e4 - param_1->f9e0);
    if ((int)fVar3 == 0) {
      param_1->f99c = (fVar6 * (float)(param_1->f9e4 - param_1->f9e0)) / 2.0f;
    }
    else if (fVar3 > 0.0f) {
      param_1->f99c += 2.0f;
    }
    else {
      param_1->f99c -= 2.0f;
    }
  }
  if (param_1->f99c >= 0.0f) {
    iVar2 = FUN_00108124(param_1->f48c,DAT_003a7134);
    iVar2->f24 = iVar2->f28 + 1;
    iVar2->f8 = (short)(int)(param_1->f99c + (float)param_1->f9e0);
    FUN_00105470(iVar2,0);
  }
  else {
    iVar2 = FUN_00108124(param_1->f48c,DAT_003a7128);
    iVar2->f4 = (short)(int)(param_1->f99c + (float)param_1->f9b8);
    FUN_00105470(iVar2,0);
  }

  uVar1 = FUN_00108124(param_1->f48c,DAT_003a7140);
  if (param_1->f9a0 >= 0.0f) {
    FUN_00105470(uVar1,1);
  }
  uVar1 = FUN_00108124(param_1->f48c,DAT_003a714c);
  if (param_1->f9a0 <= 0.0f) {
    FUN_00105470(uVar1,1);
  }
  fVar6 = param_2->f20;
  if (fVar6 < 0.0f) {
    fVar3 = fVar6 - (param_1->f9a0 * 2.0f) / (float)(param_1->f9e4 - param_1->f9e0);
    if ((int)fVar3 == 0) {
      param_1->f9a0 = (fVar6 * (float)(param_1->f9e4 - param_1->f9e0)) / 2.0f;
    }
    else if (fVar3 < 0.0f) {
      param_1->f9a0 -= 2.0f;
    }
    else {
      param_1->f9a0 += 2.0f;
    }
  }
  else {
    fVar3 = fVar6 - (param_1->f9a0 * 2.0f) / (float)(param_1->f9e4 - param_1->f9e0);
    if ((int)fVar3 == 0) {
      param_1->f9a0 = (fVar6 * (float)(param_1->f9e4 - param_1->f9e0)) / 2.0f;
    }
    else if (fVar3 > 0.0f) {
      param_1->f9a0 += 2.0f;
    }
    else {
      param_1->f9a0 -= 2.0f;
    }
  }
  if (param_1->f9a0 >= 0.0f) {
    iVar2 = FUN_00108124(param_1->f48c,DAT_003a714c);
    iVar2->f24 = iVar2->f28 + 1;
    iVar2->f8 = (short)(int)(param_1->f9a0 + (float)param_1->f9e0);
    FUN_00105470(iVar2,0);
  }
  else {
    iVar2 = FUN_00108124(param_1->f48c,DAT_003a7140);
    iVar2->f4 = (short)(int)(param_1->f9a0 + (float)param_1->f9b8);
    FUN_00105470(iVar2,0);
  }

  uVar1 = FUN_00108124(param_1->f48c,DAT_003a7158);
  if (param_1->f9a4 >= 0.0f) {
    FUN_00105470(uVar1,1);
  }
  uVar1 = FUN_00108124(param_1->f48c,DAT_003a7164);
  if (param_1->f9a4 <= 0.0f) {
    FUN_00105470(uVar1,1);
  }
  fVar6 = param_2->f24;
  if (fVar6 < 0.0f) {
    fVar3 = fVar6 - (param_1->f9a4 * 2.0f) / (float)(param_1->f9e4 - param_1->f9e0);
    if ((int)fVar3 == 0) {
      param_1->f9a4 = (fVar6 * (float)(param_1->f9e4 - param_1->f9e0)) / 2.0f;
    }
    else if (fVar3 < 0.0f) {
      param_1->f9a4 -= 2.0f;
    }
    else {
      param_1->f9a4 += 2.0f;
    }
  }
  else {
    fVar3 = fVar6 - (param_1->f9a4 * 2.0f) / (float)(param_1->f9e4 - param_1->f9e0);
    if ((int)fVar3 == 0) {
      param_1->f9a4 = (fVar6 * (float)(param_1->f9e4 - param_1->f9e0)) / 2.0f;
    }
    else if (fVar3 > 0.0f) {
      param_1->f9a4 += 2.0f;
    }
    else {
      param_1->f9a4 -= 2.0f;
    }
  }
  if (param_1->f9a4 >= 0.0f) {
    iVar2 = FUN_00108124(param_1->f48c,DAT_003a7164);
    iVar2->f24 = iVar2->f28 + 1;
    iVar2->f8 = (short)(int)(param_1->f9a4 + (float)param_1->f9e0);
    FUN_00105470(iVar2,0);
  }
  else {
    iVar2 = FUN_00108124(param_1->f48c,DAT_003a7158);
    iVar2->f4 = (short)(int)(param_1->f9a4 + (float)param_1->f9b8);
    FUN_00105470(iVar2,0);
  }

  uVar1 = FUN_00108124(param_1->f48c,DAT_003a7170);
  if (param_1->f9a8 >= 0.0f) {
    FUN_00105470(uVar1,1);
  }
  uVar1 = FUN_00108124(param_1->f48c,DAT_003a717c);
  if (param_1->f9a8 <= 0.0f) {
    FUN_00105470(uVar1,1);
  }
  fVar6 = param_2->f28;
  if (fVar6 < 0.0f) {
    fVar3 = fVar6 - (param_1->f9a8 * 2.0f) / (float)(param_1->f9e4 - param_1->f9e0);
    if ((int)fVar3 == 0) {
      param_1->f9a8 = (fVar6 * (float)(param_1->f9e4 - param_1->f9e0)) / 2.0f;
    }
    else if (fVar3 < 0.0f) {
      param_1->f9a8 -= 2.0f;
    }
    else {
      param_1->f9a8 += 2.0f;
    }
  }
  else {
    fVar3 = fVar6 - (param_1->f9a8 * 2.0f) / (float)(param_1->f9e4 - param_1->f9e0);
    if ((int)fVar3 == 0) {
      param_1->f9a8 = (fVar6 * (float)(param_1->f9e4 - param_1->f9e0)) / 2.0f;
    }
    else if (fVar3 > 0.0f) {
      param_1->f9a8 += 2.0f;
    }
    else {
      param_1->f9a8 -= 2.0f;
    }
  }
  if (param_1->f9a8 >= 0.0f) {
    iVar2 = FUN_00108124(param_1->f48c,DAT_003a717c);
    iVar2->f24 = iVar2->f28 + 1;
    iVar2->f8 = (short)(int)(param_1->f9a8 + (float)param_1->f9e0);
    FUN_00105470(iVar2,0);
  }
  else {
    iVar2 = FUN_00108124(param_1->f48c,DAT_003a7170);
    iVar2->f4 = (short)(int)(param_1->f9a8 + (float)param_1->f9b8);
    FUN_00105470(iVar2,0);
  }

  uVar1 = FUN_00108124(param_1->f48c,DAT_003a7188);
  if (param_1->f9ac >= 0.0f) {
    FUN_00105470(uVar1,1);
  }
  uVar1 = FUN_00108124(param_1->f48c,DAT_003a7194);
  if (param_1->f9ac <= 0.0f) {
    FUN_00105470(uVar1,1);
  }
  fVar6 = param_2->f2c;
  if (fVar6 < 0.0f) {
    fVar3 = fVar6 - (param_1->f9ac * 2.0f) / (float)(param_1->f9e4 - param_1->f9e0);
    if ((int)fVar3 == 0) {
      param_1->f9ac = (fVar6 * (float)(param_1->f9e4 - param_1->f9e0)) / 2.0f;
    }
    else if (fVar3 < 0.0f) {
      param_1->f9ac -= 2.0f;
    }
    else {
      param_1->f9ac += 2.0f;
    }
  }
  else {
    fVar3 = fVar6 - (param_1->f9ac * 2.0f) / (float)(param_1->f9e4 - param_1->f9e0);
    if ((int)fVar3 == 0) {
      param_1->f9ac = (fVar6 * (float)(param_1->f9e4 - param_1->f9e0)) / 2.0f;
    }
    else if (fVar3 > 0.0f) {
      param_1->f9ac += 2.0f;
    }
    else {
      param_1->f9ac -= 2.0f;
    }
  }
  if (param_1->f9ac >= 0.0f) {
    iVar2 = FUN_00108124(param_1->f48c,DAT_003a7194);
    iVar2->f24 = iVar2->f28 + 1;
    iVar2->f8 = (short)(int)(param_1->f9ac + (float)param_1->f9e0);
    FUN_00105470(iVar2,0);
  }
  else {
    iVar2 = FUN_00108124(param_1->f48c,DAT_003a7188);
    iVar2->f4 = (short)(int)(param_1->f9ac + (float)param_1->f9b8);
    FUN_00105470(iVar2,0);
  }
}
