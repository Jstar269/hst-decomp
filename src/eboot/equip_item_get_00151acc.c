/* HSTMATCH module=EBOOT.BIN start=0x00151acc end=0x00151b94 symbol=FUN_00151acc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Obj { char pad[8]; int f8; int fc; };

extern unsigned char DAT_003402f0;
extern int *DAT_0034a118;
extern char DAT_002dc584[];
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
    FUN_0014fd94(DAT_002dc584, self->f8, self->fc);
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
