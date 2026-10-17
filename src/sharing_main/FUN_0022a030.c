/* HSTMATCH module=hstp_trans_main.prx start=0x0022a030 end=0x0022a074 symbol=FUN_0022a030 lang=c99 */
/* Clone of src/eboot/FUN_0021aabc.c (hstclone.py tag u5cr3s): addresses substituted; exact match verified; names and types await human review. */
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
extern undefined4 *FUN_002294b8(undefined4 *);
void FUN_0022a030(undefined4 **param_1)
{
  undefined4 *p;
  p = FUN_00000bcc(0x114);
  if (p != 0) p = FUN_002294b8(p);
  *param_1 = p;
}