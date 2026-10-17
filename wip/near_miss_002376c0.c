/* HSTMATCH module=EBOOT.BIN start=0x002376c0 end=0x00237770 symbol=FUN_002376c0 lang=c99 */
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

extern void * FUN_00002f60(unsigned int, void *);
extern void * FUN_00236890(void *, void *);

void FUN_002376c0(int *param_1,uint param_2,uint param_3)
{
  int iVar1;
  void *newItem;
  int iVar2;
  
  iVar2 = *param_1 + param_1[4] * 0x230;
  while (param_2 < param_3) {
    iVar2 = iVar2 + -0x230;
    param_3 = param_3 - 0x230;
    newItem = FUN_00002f60(0x230,(void *)iVar2);
    if (newItem != 0) {
      FUN_00236890(newItem,(void *)param_3);
    }
    iVar1 = param_1[4];
    param_1[4] = iVar1 + -1;
    param_1[1] = param_1[1] + 1;
  }
  return;
}
// Near miss: only the stack adjustment words differ; this source uses a 16-byte smaller frame than retail. Typed pointer results and allocation/copy helper parameters did not change the frame.
// near miss from lane u4r4-0 (unreviewed)
