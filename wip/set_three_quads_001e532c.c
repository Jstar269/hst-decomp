/* HSTMATCH module=EBOOT.BIN start=0x001e532c end=0x001e5470 symbol=FUN_001e532c lang=c99 */
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

extern char DAT_002ec18c[];
extern undefined4 FUN_00065740();
extern int FUN_001ee224();
extern void FUN_00217834();

void FUN_001e532c(int param_1)
{
  uint w;
  undefined4 u6;
  undefined4 u5;

  if (*(unsigned char *)(param_1 + 0x438) != 0) {
    w = (uint)*(unsigned char *)(param_1 + 0x53e) << 0x18;
    w = w | (uint)*(unsigned char *)(param_1 + 0x53c) << 0x10;
    w = w | (uint)*(unsigned char *)(param_1 + 0x53a) << 8;
    w = w | *(unsigned char *)(param_1 + 0x538);
    u6 = *(undefined4 *)(param_1 + 0x4e8);
    u5 = FUN_001ee224();
    u5 = FUN_00065740(u5,DAT_002ec18c,1);
    FUN_00217834(param_1 + 0x4c8,w,u6,u5);

    w = (uint)*(unsigned char *)(param_1 + 0x5ca) << 0x18;
    w = w | (uint)*(unsigned char *)(param_1 + 0x5c8) << 0x10;
    w = w | (uint)*(unsigned char *)(param_1 + 0x5c6) << 8;
    w = w | *(unsigned char *)(param_1 + 0x5c4);
    u6 = *(undefined4 *)(param_1 + 0x574);
    u5 = FUN_001ee224();
    u5 = FUN_00065740(u5,DAT_002ec18c,1);
    FUN_00217834(param_1 + 0x554,w,u6,u5);

    w = (uint)*(unsigned char *)(param_1 + 0x656) << 0x18;
    w = w | (uint)*(unsigned char *)(param_1 + 0x654) << 0x10;
    w = w | (uint)*(unsigned char *)(param_1 + 0x652) << 8;
    w = w | *(unsigned char *)(param_1 + 0x650);
    u6 = *(undefined4 *)(param_1 + 0x600);
    u5 = FUN_001ee224();
    u5 = FUN_00065740(u5,DAT_002ec18c,1);
    FUN_00217834(param_1 + 0x5e0,w,u6,u5);

    *(undefined1 *)(param_1 + 0x438) = 0;
  }
}
// near miss from lane od3 (unreviewed)
