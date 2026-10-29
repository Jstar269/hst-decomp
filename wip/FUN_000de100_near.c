/* HSTMATCH module=EBOOT.BIN start=0x000de100 end=0x000de208 symbol=FUN_000de100 lang=c99 */
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

extern unsigned char DAT_003417bb;
extern undefined4 FUN_000def0c();

void FUN_000de100(int param_1,int *param_2,undefined1 *param_3,undefined4 *param_4)
{
  int iVar1;
  int *piVar2;
  
  *param_3 = 0;
  *param_4 = 0xffffffff;
  *param_2 = *(int *)(param_1 + 0xd0);
  param_2[1] = *(int *)(param_1 + 0xd4);
  iVar1 = FUN_000def0c();
  if ((((iVar1 == 0) && (DAT_003417bb != '\x01')) &&
      (iVar1 = *(int *)(param_1 + 0xcc) + -1, iVar1 <= *param_2)) && (iVar1 <= param_2[1])) {
    piVar2 = param_2;
    if (param_2[1] < *param_2) {
      piVar2 = param_2 + 1;
    }
    iVar1 = *piVar2;
    *param_2 = *param_2 - iVar1;
    iVar1 = param_2[1] - iVar1;
    param_2[1] = iVar1;
    if (*param_2 == iVar1) {
      *param_3 = 1;
    }
    else if (iVar1 < *param_2) {
      *param_4 = 0;
    }
    else {
      *param_4 = 1;
    }
  }
  return;
}
// near miss from lane dsn3 (unreviewed)
