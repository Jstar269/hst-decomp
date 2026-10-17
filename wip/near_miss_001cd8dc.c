/* HSTMATCH module=EBOOT.BIN start=0x001cd8dc end=0x001cd970 symbol=FUN_001cd8dc lang=c99 */
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

extern void * FUN_000111c0(void *, const void *, uint);

int FUN_001cd8dc(int *param_1,int param_2,int param_3)
{
  int iVar1;
  
  if (param_2 != param_3) {
    iVar1 = (*param_1 + param_1[1] * 4) - param_3;
    FUN_000111c0((void *)param_2,(const void *)param_3,(uint)((iVar1 / 4) << 2));
    param_3 = param_3 - param_2;
    param_1[1] = param_1[1] - (param_3 / 4);
  }
  return param_2;
}
// Near miss: only the stack adjustment words differ; this source uses a 16-byte smaller frame than retail. A typed three-argument move helper did not change the frame.
// near miss from lane u4r4-0 (unreviewed)
