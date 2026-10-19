/* HSTMATCH module=EBOOT.BIN start=0x00276bcc end=0x00277678 symbol=FUN_00276bcc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed struct members, flipped mirrored float comparisons, and inline span difference `(float)(param_1->f9e4 - param_1->f9e0)`; exact match verified; names and types await human review. */

extern char DAT_002fe3a8[];
extern char DAT_002fe3b4[];
extern char DAT_002fe3c0[];
extern char DAT_002fe3cc[];
extern char DAT_002fe3d8[];
extern char DAT_002fe3e4[];
extern char DAT_002fe3f0[];
extern char DAT_002fe3f8[];
extern char DAT_002fe400[];
extern char DAT_002fe40c[];
extern char DAT_002fe418[];
extern char DAT_002fe424[];
extern char DAT_002fe430[];
extern char DAT_002fe43c[];
extern char DAT_002fe448[];
extern char DAT_002fe454[];
extern char DAT_002fe460[];
extern char DAT_002fe46c[];

typedef struct {
  char pad0[4];
  short f4;
  char pad1[2];
  short f8;
  char pad2[0x24 - 0x0a];
  int f24;
  int f28;
} Widget_00276bcc;

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
} Self_00276bcc;

typedef struct {
  char pad0[0x1c];
  float f1c;
  float f20;
  float f24;
  float f28;
  float f2c;
} Param2_00276bcc;

extern void FUN_000ffb3c(Widget_00276bcc *, int);
extern Widget_00276bcc *FUN_001026b8(void *, char *);

void FUN_00276bcc(Self_00276bcc *param_1, Param2_00276bcc *param_2)
{
  Widget_00276bcc *uVar1;
  Widget_00276bcc *iVar2;
  float fVar3;
  float fVar6;

  uVar1 = FUN_001026b8(param_1->f48c,DAT_002fe3a8);
  FUN_000ffb3c(uVar1,1);
  uVar1 = FUN_001026b8(param_1->f48c,DAT_002fe3b4);
  FUN_000ffb3c(uVar1,1);
  uVar1 = FUN_001026b8(param_1->f48c,DAT_002fe3c0);
  FUN_000ffb3c(uVar1,1);
  uVar1 = FUN_001026b8(param_1->f48c,DAT_002fe3cc);
  FUN_000ffb3c(uVar1,1);
  uVar1 = FUN_001026b8(param_1->f48c,DAT_002fe3d8);
  FUN_000ffb3c(uVar1,1);
  uVar1 = FUN_001026b8(param_1->f48c,DAT_002fe3e4);
  FUN_000ffb3c(uVar1,1);
  uVar1 = FUN_001026b8(param_1->f48c,DAT_002fe3f0);
  FUN_000ffb3c(uVar1,1);
  uVar1 = FUN_001026b8(param_1->f48c,DAT_002fe3f8);
  FUN_000ffb3c(uVar1,1);

  uVar1 = FUN_001026b8(param_1->f48c,DAT_002fe400);
  if (param_1->f99c >= 0.0f) {
    FUN_000ffb3c(uVar1,1);
  }
  uVar1 = FUN_001026b8(param_1->f48c,DAT_002fe40c);
  if (param_1->f99c <= 0.0f) {
    FUN_000ffb3c(uVar1,1);
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
    iVar2 = FUN_001026b8(param_1->f48c,DAT_002fe40c);
    iVar2->f24 = iVar2->f28 + 1;
    iVar2->f8 = (short)(int)(param_1->f99c + (float)param_1->f9e0);
    FUN_000ffb3c(iVar2,0);
  }
  else {
    iVar2 = FUN_001026b8(param_1->f48c,DAT_002fe400);
    iVar2->f4 = (short)(int)(param_1->f99c + (float)param_1->f9b8);
    FUN_000ffb3c(iVar2,0);
  }

  uVar1 = FUN_001026b8(param_1->f48c,DAT_002fe418);
  if (param_1->f9a0 >= 0.0f) {
    FUN_000ffb3c(uVar1,1);
  }
  uVar1 = FUN_001026b8(param_1->f48c,DAT_002fe424);
  if (param_1->f9a0 <= 0.0f) {
    FUN_000ffb3c(uVar1,1);
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
    iVar2 = FUN_001026b8(param_1->f48c,DAT_002fe424);
    iVar2->f24 = iVar2->f28 + 1;
    iVar2->f8 = (short)(int)(param_1->f9a0 + (float)param_1->f9e0);
    FUN_000ffb3c(iVar2,0);
  }
  else {
    iVar2 = FUN_001026b8(param_1->f48c,DAT_002fe418);
    iVar2->f4 = (short)(int)(param_1->f9a0 + (float)param_1->f9b8);
    FUN_000ffb3c(iVar2,0);
  }

  uVar1 = FUN_001026b8(param_1->f48c,DAT_002fe430);
  if (param_1->f9a4 >= 0.0f) {
    FUN_000ffb3c(uVar1,1);
  }
  uVar1 = FUN_001026b8(param_1->f48c,DAT_002fe43c);
  if (param_1->f9a4 <= 0.0f) {
    FUN_000ffb3c(uVar1,1);
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
    iVar2 = FUN_001026b8(param_1->f48c,DAT_002fe43c);
    iVar2->f24 = iVar2->f28 + 1;
    iVar2->f8 = (short)(int)(param_1->f9a4 + (float)param_1->f9e0);
    FUN_000ffb3c(iVar2,0);
  }
  else {
    iVar2 = FUN_001026b8(param_1->f48c,DAT_002fe430);
    iVar2->f4 = (short)(int)(param_1->f9a4 + (float)param_1->f9b8);
    FUN_000ffb3c(iVar2,0);
  }

  uVar1 = FUN_001026b8(param_1->f48c,DAT_002fe448);
  if (param_1->f9a8 >= 0.0f) {
    FUN_000ffb3c(uVar1,1);
  }
  uVar1 = FUN_001026b8(param_1->f48c,DAT_002fe454);
  if (param_1->f9a8 <= 0.0f) {
    FUN_000ffb3c(uVar1,1);
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
    iVar2 = FUN_001026b8(param_1->f48c,DAT_002fe454);
    iVar2->f24 = iVar2->f28 + 1;
    iVar2->f8 = (short)(int)(param_1->f9a8 + (float)param_1->f9e0);
    FUN_000ffb3c(iVar2,0);
  }
  else {
    iVar2 = FUN_001026b8(param_1->f48c,DAT_002fe448);
    iVar2->f4 = (short)(int)(param_1->f9a8 + (float)param_1->f9b8);
    FUN_000ffb3c(iVar2,0);
  }

  uVar1 = FUN_001026b8(param_1->f48c,DAT_002fe460);
  if (param_1->f9ac >= 0.0f) {
    FUN_000ffb3c(uVar1,1);
  }
  uVar1 = FUN_001026b8(param_1->f48c,DAT_002fe46c);
  if (param_1->f9ac <= 0.0f) {
    FUN_000ffb3c(uVar1,1);
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
    iVar2 = FUN_001026b8(param_1->f48c,DAT_002fe46c);
    iVar2->f24 = iVar2->f28 + 1;
    iVar2->f8 = (short)(int)(param_1->f9ac + (float)param_1->f9e0);
    FUN_000ffb3c(iVar2,0);
  }
  else {
    iVar2 = FUN_001026b8(param_1->f48c,DAT_002fe460);
    iVar2->f4 = (short)(int)(param_1->f9ac + (float)param_1->f9b8);
    FUN_000ffb3c(iVar2,0);
  }
}
