/* HSTMATCH module=EBOOT.BIN start=0x000513a0 end=0x000513e4 symbol=FUN_000513a0 lang=c99 */
/* Clone of src/sharing_main/FUN_00051d40.c (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: expressed the three stores as ascending switch cases; exact match verified; names and types await human review. */
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


void FUN_000513a0(int param_1,int param_2)
{
  switch (param_2) {
    case 0: *(undefined4 *)(param_1 + 0x1c) = 0x10; break;
    case 1: *(undefined4 *)(param_1 + 0x1c) = 0x11; break;
    case 2: *(undefined4 *)(param_1 + 0x1c) = 0x12; break;
  }
}
