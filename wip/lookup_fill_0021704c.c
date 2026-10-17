/* HSTMATCH module=EBOOT.BIN start=0x0021704c end=0x002170ec symbol=FUN_0021704c lang=c99 */
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

extern int FUN_001026b8();

void FUN_0021704c(int *param_1,int *param_2,byte *param_3,int param_4)
{
  int *piVar1;
  int iVar2;
  int iVar3;

  int *base = param_2;
  byte *cursor;
  int *out;
  if (0 < param_4) {
    iVar3 = 0;
    cursor = param_3;
    out = param_1;
    do {
      piVar1 = (int *)FUN_001026b8(base[*cursor],cursor + 1);
      if (piVar1 != (int *)0x0) {
        *out = (int)piVar1;
        iVar2 = piVar1[8];
        out[1] = iVar2;
        if (iVar2 != 0) {
          out[2] = *piVar1;
        }
      }
      iVar3 = iVar3 + 1;
      cursor = cursor + 0x21;
      out = out + 3;
    } while (iVar3 < param_4);
  }
  return;
}

// NEAR MISS: five setup words differ. Retail saves the table pointer before the nonpositive-count branch and initializes the index in its delay slot; the loop body matches exactly.
// near miss from lane u5cr3-1 (unreviewed)
