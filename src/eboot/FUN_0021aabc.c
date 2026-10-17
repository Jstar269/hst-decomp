/* HSTMATCH module=EBOOT.BIN start=0x0021aabc end=0x0021ab00 symbol=FUN_0021aabc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: retained and passed the allocated pointer through initialization before one shared store; exact match verified; names and types await human review. */
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
extern undefined4 *FUN_00000bcc(int);
extern undefined4 *FUN_00219fa0(undefined4 *);
void FUN_0021aabc(undefined4 **param_1)
{
  undefined4 *p;
  p = FUN_00000bcc(0x114);
  if (p != 0) p = FUN_00219fa0(p);
  *param_1 = p;
}