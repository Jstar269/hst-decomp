/* HSTMATCH module=EBOOT.BIN start=0x0028bd5c end=0x0028be78 symbol=FUN_0028bd5c lang=c99 */
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

extern undefined * DAT_0034a114;
extern undefined1 FUN_0022cb40();

bool FUN_0028bd5c(int *param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar1 = (int *)*param_1;
  if (piVar1 == piVar1 + param_1[1] * 0x18) {
    return false;
  }
  iVar2 = *piVar1;
  piVar3 = piVar1;
  do {
    if (iVar2 == *(int *)(DAT_0034a114 + 0xcc) + 1) {
      if (((piVar3[1] == *(int *)(DAT_0034a114 + 0xd0) + 1) &&
          (piVar3[3] == *(int *)(param_2 + 0x30))) && (piVar3[2] == *(int *)(param_2 + 0x34))) {
        iVar2 = FUN_0022cb40(*(int *)(DAT_0034a114 + 0xcc),*(int *)(DAT_0034a114 + 0xd0),
                             piVar3[3] % 100);
        if (iVar2 != 1) {
          return true;
        }
        if (piVar3[4] != 1) {
          return false;
        }
        return *(char *)(param_2 + 0x5b) == '\0';
      }
      iVar2 = param_1[1];
    }
    else {
      iVar2 = param_1[1];
    }
    piVar3 = piVar3 + 0x18;
    if (piVar3 == piVar1 + iVar2 * 0x18) {
      return false;
    }
    iVar2 = *piVar3;
  } while( true );
}
// near miss from lane dsn3 (unreviewed)
