/* HSTMATCH module=hstp_trans_main.prx start=0x001db84c end=0x001db8a4 symbol=FUN_001db84c lang=c99 */
/* Clone of src/eboot/allocate_indexed_copy_001cd0e4.c (hstclone.py tag u5cr3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reused the allocation result for the conditional copy and return; exact match verified; names and types await human review. */
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

extern int FUN_00000bcc();
extern undefined4 * FUN_0029b9cc();

undefined4 FUN_001db84c(int param_1,int param_2)
{
  int value = *(int *)(*(int *)(param_1 + 0x180) + param_2 * 4);
  int result;

  if (value == 0) return 0;
  result = FUN_00000bcc(0x100);
  if (result != 0) result = (int)FUN_0029b9cc((int *)result,value);
  return (undefined4)result;
}
