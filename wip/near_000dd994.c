/* HSTMATCH module=EBOOT.BIN start=0x000dd994 end=0x000ddbb0 symbol=FUN_000dd994 lang=c99 */
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

extern undefined * DAT_003386b0;
extern int FUN_0008882c();
extern undefined4 FUN_000de3f0();

void FUN_000dd994(int param_1)
{
  char cVar1;
  int iVar2;
  
  iVar2 = FUN_0008882c(DAT_003386b0);
  iVar2 = FUN_000de3f0(param_1,*(undefined4 *)(iVar2 + 0x144));
  if (iVar2 != 0) {
    *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 0x1fc) =
         *(int *)(*(int *)(DAT_003386b0 + 0xa0) + 0x1fc) + 1;
  }
  iVar2 = *(int *)(param_1 + 0x78);
  if (-1 < iVar2) {
    iVar2 = iVar2 * 0x5c + *(int *)(DAT_003386b0 + 0xa0);
    *(int *)(iVar2 + 0x70) = *(int *)(iVar2 + 0x70) + 1;
  }
  iVar2 = *(int *)(param_1 + 0x9c) * 4 + *(int *)(DAT_003386b0 + 0xa0);
  *(int *)(iVar2 + 100) = *(int *)(iVar2 + 100) + 1;
  if (*(int *)(param_1 + 0x94) == *(int *)(param_1 + 0x9c)) {
    if (*(int *)(param_1 + 0x90) == 1) {
      if (*(unsigned char *)(param_1 + 0x62) == '\0') {
        iVar2 = *(int *)(param_1 + 0x98) * 0x5c + *(int *)(DAT_003386b0 + 0xa0);
        *(int *)(iVar2 + 0x78) = *(int *)(iVar2 + 0x78) + 1;
      }
    }
    else {
      if (*(unsigned char *)(param_1 + 0x62) == '\0') {
        iVar2 = *(int *)(param_1 + 0x98) * 0x5c + *(int *)(DAT_003386b0 + 0xa0);
        *(int *)(iVar2 + 0x74) = *(int *)(iVar2 + 0x74) + 1;
      }
      cVar1 = *(char *)(param_1 + 99);
      if (cVar1 != '\0') {
        iVar2 = *(int *)(param_1 + 0x98) * 0x5c + *(int *)(DAT_003386b0 + 0xa0);
        *(int *)(iVar2 + 0xb8) = *(int *)(iVar2 + 0xb8) + 1;
      }
    }
  }
  else {
    if (*(int *)(param_1 + 0x90) >= 2) {
      iVar2 = *(int *)(param_1 + 0x98) * 0x5c + *(int *)(DAT_003386b0 + 0xa0);
      *(int *)(iVar2 + 0x7c) = *(int *)(iVar2 + 0x7c) + 1;
    }
    cVar1 = *(char *)(param_1 + 0x5f);
    if (cVar1 != '\0') {
      iVar2 = *(int *)(param_1 + 0x98) * 0x5c + *(int *)(DAT_003386b0 + 0xa0);
      *(int *)(iVar2 + 0x80) = *(int *)(iVar2 + 0x80) + 1;
    }
  }
  return;
}
// Best near miss: 103 differing words remain. State counter updates and the callback state branches
// still have different register and block layouts. Tried byte/int parameter and flag types, local
// statistics pointers, declaration reordering, and outer/inner condition inversions; unsigned flag
// reads at +0x62 gave the best one-word improvement.
// near miss from lane km4 (unreviewed)
