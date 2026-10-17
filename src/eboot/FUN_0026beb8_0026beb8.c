/* HSTMATCH module=EBOOT.BIN start=0x0026beb8 end=0x0026bf18 symbol=FUN_0026beb8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: restored the second initialization-helper argument; exact match verified; names and types await human review. */
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

extern undefined4 DAT_002cfc8c;
extern void FUN_0001dfe8();
extern void FUN_0001e23c();
extern void FUN_0026bf18(undefined4 *param_1, int param_2);
extern void FUN_00281128();

void FUN_0026beb8(undefined4 *param_1)
{
  FUN_0001dfe8(DAT_002cfc8c,0x2000);
  FUN_0001e23c(DAT_002cfc8c,0x2000,1);
  *(undefined1 *)(param_1 + 0x2ef) = 1;
  *(undefined1 *)(param_1 + 0x2f1) = 0;
  FUN_0026bf18(param_1,1);
  FUN_00281128(*param_1);
  return;
}
