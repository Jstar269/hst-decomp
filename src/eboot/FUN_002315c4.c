/* HSTMATCH module=EBOOT.BIN start=0x002315c4 end=0x00231614 symbol=FUN_002315c4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
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

extern int * DAT_0034a65c;
extern undefined DAT_0034a678;
extern int FUN_00231280();
extern void FUN_0023466c();

void FUN_002315c4(void)
{
  if ((DAT_0034a65c != (int *)0x0) && (FUN_00231280(DAT_0034a65c), DAT_0034a65c[1] == 1)) {
    FUN_0023466c((int *)&DAT_0034a678);
  }
  return;
}
