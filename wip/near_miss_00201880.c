/* HSTMATCH module=EBOOT.BIN start=0x00201880 end=0x00201910 symbol=FUN_00201880 lang=c99 */
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

void FUN_00201880(int param_1)
{
  FUN_002177d4(param_1 + 0x8bc,*(short *)(param_1 + 0x8c4) + 0xf0,(int)*(short *)(param_1 + 0x8c6),
               (int)*(short *)(param_1 + 0x8c4),(int)*(short *)(param_1 + 0x8c6),6);
  FUN_002177d4(param_1 + 0x948,*(short *)(param_1 + 0x950) + 0xf0,(int)*(short *)(param_1 + 0x952),
               (int)*(short *)(param_1 + 0x950),(int)*(short *)(param_1 + 0x952),6);
  FUN_002177d4(param_1 + 0x9d4,*(short *)(param_1 + 0x9dc) + 0xf0,(int)*(short *)(param_1 + 0x9de),
               (int)*(short *)(param_1 + 0x9dc),(int)*(short *)(param_1 + 0x9de),6);
  FUN_002177d4(param_1 + 0xa60,*(short *)(param_1 + 0xa68) + 0xf0,(int)*(short *)(param_1 + 0xa6a),
               (int)*(short *)(param_1 + 0xa68),(int)*(short *)(param_1 + 0xa6a),6);
  return;
}
// Near miss: two words differ at +0x20 because the first call sets a0 before jal and a1 in the delay slot; retail sets a1 first and a0 in the slot. Typed helper arguments and an adjusted-y local did not change scheduling.
// near miss from lane u4r4-0 (unreviewed)
