/* HSTMATCH module=EBOOT.BIN start=0x001e8424 end=0x001e84c8 symbol=FUN_001e8424 lang=c99 */
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

extern void FUN_002177d4(int, int, int, int, int, int);

void FUN_001e8424(int param_1)
{
  FUN_002177d4(param_1 + 0x279c,*(short *)(param_1 + 0x27a4) + 0x15e,
               (int)*(short *)(param_1 + 0x27a6),(int)*(short *)(param_1 + 0x27a4),
               (int)*(short *)(param_1 + 0x27a6),5);
  FUN_002177d4(param_1 + 0x48,(int)*(short *)(param_1 + 0x5c),(int)*(short *)(param_1 + 0x5e),
               (int)((float)(int)*(short *)(param_1 + 0x5c) + -140.0f),
               (int)*(short *)(param_1 + 0x5e),5);
  FUN_002177d4(param_1 + 0x168,(int)*(short *)(param_1 + 0x170),(int)*(short *)(param_1 + 0x172),
               (int)((float)(int)*(short *)(param_1 + 0x170) + -140.0f),
               (int)*(short *)(param_1 + 0x172),5);
  return;
}
// Near miss: two words differ at +0x20 because the first call sets a0 before jal and a1 in the delay slot; retail sets a1 first and a0 in the slot. Typed helper arguments and an adjusted-y local did not change scheduling.
// near miss from lane u4r4-0 (unreviewed)
