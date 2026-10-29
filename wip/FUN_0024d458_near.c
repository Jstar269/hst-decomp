/* HSTMATCH module=EBOOT.BIN start=0x0024d458 end=0x0024d5b8 symbol=FUN_0024d458 lang=c99 */
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

extern undefined4 DAT_003313c4;
extern undefined4 DAT_00340284;
extern void FUN_0005f1e8();
extern int FUN_00131cf8();

void FUN_0024d458(int param_1)
{
  int iVar1;
  
  if ((*(int *)(DAT_00340284 + 0x8c) == 0) || (iVar1 = FUN_00131cf8(), iVar1 != 0)) {
    if (*(float *)(DAT_003313c4 + 0x1d8) > *(float *)(param_1 + 0x24c)) {
      if (*(float *)(param_1 + 0xb8) > *(float *)(param_1 + 0x24c)) {
        *(undefined1 *)(param_1 + 0x254) = 1;
      }
      else if ((*(int *)(param_1 + 0x3c) == 2) && (*(uchar *)(param_1 + 0x249) != '\0')) {
        FUN_0005f1e8(param_1 + 0x50,0);
        *(undefined1 *)(param_1 + 0x254) = 0;
      }
    }
    else if (*(float *)(DAT_003313c4 + 0x1d8) < *(float *)(param_1 + 0x250)) {
      if (*(float *)(param_1 + 0xb8) < *(float *)(param_1 + 0x250)) {
        *(undefined1 *)(param_1 + 0x254) = 1;
      }
      else if ((*(int *)(param_1 + 0x3c) == 2) && (*(uchar *)(param_1 + 0x249) != '\0')) {
        FUN_0005f1e8(param_1 + 0x50,0);
        *(undefined1 *)(param_1 + 0x254) = 0;
      }
    }
    else if ((*(int *)(param_1 + 0x3c) == 2) && (*(uchar *)(param_1 + 0x249) != '\0')) {
      FUN_0005f1e8(param_1 + 0x50,0);
      *(undefined1 *)(param_1 + 0x254) = 0;
    }
  }
  else if ((*(int *)(param_1 + 0x3c) == 2) && (*(uchar *)(param_1 + 0x249) != '\0')) {
    FUN_0005f1e8(param_1 + 0x50,0);
    *(undefined1 *)(param_1 + 0x254) = 0;
  }
  return;
}
// near miss from lane dsn3 (unreviewed)
