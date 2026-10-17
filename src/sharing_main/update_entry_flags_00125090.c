/* HSTMATCH module=hstp_trans_main.prx start=0x00125090 end=0x00125188 symbol=FUN_00125090 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
// Update status flags on entry based on team matching and queries

typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined4 DAT_003e19f0;
extern undefined * DAT_003e1e84;
extern undefined4 DAT_003e1f60;
extern undefined DAT_003eaaf7;
extern undefined DAT_003eaaf8;
extern undefined4 FUN_00100fb0();
extern undefined4 FUN_001f8d98();
extern int FUN_001f8dac();

void FUN_00125090(int param_1)
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int cond;
  char *ptr;
  int idx;

  *(char *)(param_1 + 0x2c8) = 0;
  *(char *)(param_1 + 0x2c9) = 0;
  *(char *)(param_1 + 0x2ca) = 0;

  ptr = (char *)DAT_003e1e84;
  idx = *(int *)(ptr + 0x50);
  idx = idx * 4;
  idx += DAT_003e19f0;
  uVar4 = *(uint *)(*(int *)(idx + 0x70) + 0x144);
  uVar3 = *(uint *)(ptr + 0xa0);

  if (uVar3 == uVar4 || uVar3 == (uVar4 ^ 1)) {
    cond = (uVar3 != 0);
    uVar1 = FUN_00100fb0(DAT_003e1f60);
    iVar2 = FUN_001f8dac(uVar1);
    if (iVar2 == 0) {
      if (cond != uVar4) {
        *(char *)(param_1 + 0x2c9) = 1;
      }
      else {
        *(char *)(param_1 + 0x2c8) = 1;
      }
    }
    uVar1 = FUN_00100fb0(DAT_003e1f60);
    iVar2 = FUN_001f8d98(uVar1, cond ^ 1);
    if (iVar2 == 0 && DAT_003eaaf7 == 0 && DAT_003eaaf8 == 0) {
      *(char *)(param_1 + 0x2ca) = 1;
    }
  }
}
