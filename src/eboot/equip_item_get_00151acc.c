/* HSTMATCH module=EBOOT.BIN start=0x00151acc end=0x00151b94 symbol=FUN_00151acc lang=c99 data=0x002dc584 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc584-0x002dc5a5) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */

struct Obj { char pad[8]; int f8; int fc; };

extern unsigned char DAT_003402f0;
extern int *DAT_0034a118;
void FUN_0014d044(int *);
void FUN_0014fd94(char *, int, int);
int *FUN_0014c384(int, int);

int FUN_00151acc(struct Obj *self, int *param_2)
{
  int i;
  int v;
  int key;

  if (DAT_003402f0 != 0) {
    FUN_0014d044(param_2);
    FUN_0014fd94("GetEquipItem [reg:%d, parts:%d]\n", self->f8, self->fc);
  }
  key = *param_2;
  i = self->fc;
  v = -1;
  switch (i) {
  case 0:
    v = *(int *)(*(int *)((char *)DAT_0034a118 + 0x54) + 0x1b4);
    break;
  case 1:
    v = *(int *)(*(int *)((char *)DAT_0034a118 + 0x58) + 0x1b4);
    break;
  case 2:
    v = *(int *)(*(int *)((char *)DAT_0034a118 + 0x5c) + 0x1b4);
    break;
  }
  *(int *)FUN_0014c384(key, self->f8) = v;
  return 0;
}
