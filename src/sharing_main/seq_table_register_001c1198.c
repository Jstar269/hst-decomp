/* HSTMATCH module=hstp_trans_main.prx start=0x001c1198 end=0x001c1260 symbol=FUN_001c1198 lang=c99 */
/* Clone of src/eboot/seq_table_register_001b3068.c (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the module address 0x3b7ebc is the symbol &DAT_003b7ebc (lui/addiu, not lui/ori); exact match verified; names and types await human review. */
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

extern undefined DAT_0038d2a0;
extern undefined DAT_0038d2a8;
extern undefined DAT_0038d2b4;
extern undefined DAT_003b7ebc;
extern char DAT_00390db8[];
extern char DAT_00390de4[];
extern char DAT_00390e10[];
extern void FUN_0001c5f4();
extern void FUN_0001c73c();
extern void FUN_001be0d0();

void FUN_001c1198(undefined4 *param_1)
{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  FUN_0001c5f4(&DAT_003b7ebc,DAT_00390db8);
  FUN_001be0d0(uVar1,&DAT_0038d2a0,2,0);
  FUN_0001c73c(&DAT_003b7ebc);
  FUN_0001c5f4(&DAT_003b7ebc,DAT_00390de4);
  FUN_001be0d0(uVar1,&DAT_0038d2a8,3,0);
  FUN_0001c73c(&DAT_003b7ebc);
  FUN_0001c5f4(&DAT_003b7ebc,DAT_00390e10);
  FUN_001be0d0(uVar1,&DAT_0038d2b4,2,0);
  FUN_0001c73c(&DAT_003b7ebc);
  return;
}
