/* HSTMATCH module=EBOOT.BIN start=0x00293194 end=0x002931f0 symbol=FUN_00293194 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed object and float parameters and an unsigned flag; exact match verified; names and types await human review. */
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

extern undefined4 DAT_00331b84;
extern void FUN_00063a30();

void FUN_00293194(void *param_1,float param_2)
{
  *(undefined1 *)((char *)param_1 + 0x40) = 0;
  *(undefined4 *)((char *)param_1 + 4) = 0x41f00000;
  *(undefined4 *)((char *)param_1 + 8) = 0x41f00000;
  *(undefined4 *)((char *)param_1 + 0x38) = 0;
  *(undefined4 *)((char *)param_1 + 0x38) = 0x41f80000;
  *(undefined1 *)((char *)param_1 + 0x4c) = 0;
  *(undefined1 *)((char *)param_1 + 0x4d) = 0;
  *(float *)((char *)param_1 + 0x50) = param_2;
  *(undefined1 *)((char *)param_1 + 0x54) = 0;
  if (*(unsigned char *)((char *)param_1 + 0x4e) == 0) {
    FUN_00063a30(DAT_00331b84,0xf);
  }
  return;
}
