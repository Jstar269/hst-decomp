/* HSTMATCH module=EBOOT.BIN start=0x0019494c end=0x00194ba4 symbol=FUN_0019494c lang=c99 */
/* NEAR MISS 147/150 words, 132 differing: `iVar3 = 0; if (g != 0) {...}` is closer to retail than the two-arm
   if/else (retail keeps the zero assignment out of line at the end and fills the branch delay with the last
   parameter copy), and the object-index multiply (raw*4+raw, *8-raw, *4 = 0x9c) already matches; the rest is
   parameter-copy scheduling and the duplicated body's register assignment. */
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

extern undefined * DAT_00341730;
extern undefined4 DAT_00341748;
extern char DAT_002e159c[];
extern void FUN_0005743c();
extern void FUN_00194438();
extern void FUN_00196478();

void FUN_0019494c(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5, int param_6)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  char local_1;
  char local_2;
  undefined4 local_8;
  int local_c;
  char *local_10;
  int local_14;
  
  local_8 = param_2;
  iVar3 = 0;
  if (DAT_00341730 != 0) {
    FUN_00196478(&local_c,DAT_00341748 + 0x30,&local_8);
    if (local_c != DAT_00341748 + 0x34) {
      iVar3 = *(int *)(DAT_00341730 + 4) + *(int *)(local_c + 0x10) * 0x9c;
    }
  }
  if (iVar3 == 0) {
    local_10 = DAT_002e159c;
    iVar3 = 0;
    if (DAT_00341730 != 0) {
      FUN_00196478(&local_14,DAT_00341748 + 0x30,&local_10);
      if (local_14 != DAT_00341748 + 0x34) {
        iVar3 = *(int *)(DAT_00341730 + 4) + *(int *)(local_14 + 0x10) * 0x9c;
      }
    }
    if (iVar3 != 0) {
      local_2 = '\0';
      FUN_00194438(&local_2,param_1,iVar3,param_5,param_6);
      if (local_2 != '\0') {
        bVar1 = false;
        if (param_6 != 0) {
          bVar1 = *(char *)(iVar3 + 0x7c) == '\x02';
        }
        if (((param_3 != 0) && (iVar3 = *(int *)(param_1 + 0x58), iVar3 != 0)) &&
           (iVar2 = 0, 0 < param_4)) {
          do {
            FUN_0005743c(iVar3,iVar2,param_3,bVar1);
            iVar2 = iVar2 + 1;
            param_3 = param_3 + 0x10;
          } while (iVar2 < param_4);
        }
      }
    }
  }
  else {
    local_1 = '\0';
    FUN_00194438(&local_1,param_1,iVar3,param_5,param_6);
    if (local_1 != '\0') {
      bVar1 = false;
      if (param_6 != 0) {
        bVar1 = *(char *)(iVar3 + 0x7c) == '\x02';
      }
      if (((param_3 != 0) && (iVar3 = *(int *)(param_1 + 0x58), iVar3 != 0)) &&
         (iVar2 = 0, 0 < param_4)) {
        do {
          FUN_0005743c(iVar3,iVar2,param_3,bVar1);
          iVar2 = iVar2 + 1;
          param_3 = param_3 + 0x10;
        } while (iVar2 < param_4);
      }
    }
  }
  return;
}
// near miss from lane fm7 (unreviewed)
