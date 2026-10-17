/* HSTMATCH module=hstp_trans_main.prx start=0x001d1978 end=0x001d19d8 symbol=FUN_001d1978 lang=c99 */
/* Clone of src/eboot/FUN_001c35ec.c (hstclone.py tag u6cr3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed FUN_0023569c as int instead of a byte result; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003f3610;
extern void FUN_001dbf68();
extern void FUN_00235654();
extern undefined4 FUN_0023568c();
extern int FUN_0023569c();

void FUN_001d1978(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0023569c(DAT_003f3610);
  if (iVar1 != 0) {
    uVar2 = FUN_0023568c(DAT_003f3610);
    *(undefined4 *)(param_1 + 0xf4) = uVar2;
    FUN_00235654(DAT_003f3610);
    FUN_001dbf68(param_1,0,1);
  }
  return;
}
