/* HSTMATCH module=hstp_trans_main.prx start=0x00199038 end=0x00199098 symbol=FUN_00199038 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: reused the allocation result through construction, copy, and release; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003ea8e8;
extern void FUN_00000a00();
extern int FUN_00000bcc();
extern undefined4 * FUN_00011090();
extern int FUN_00198ee4();

void FUN_00199038(void)
{
  int *object = (int *)FUN_00000bcc(0x979c0);
  if (object != (int *)0) {
    object = (int *)FUN_00198ee4((int)object);
  }
  FUN_00011090(DAT_003ea8e8, object, 0x979c0);
  FUN_00000a00(object);
}
