/* HSTMATCH module=hstp_trans_main.prx start=0x001c1c84 end=0x001c1d6c symbol=FUN_001c1c84 lang=c99 */
/* Clone of src/eboot/scratch_buffer_log_001b37f4.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the two module addresses written as &DAT_003b3e6c / &DAT_003b7ebc (lui/addiu, not lui/ori); exact match verified; names and types await human review. */
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

extern undefined DAT_003b3e6c;
extern undefined DAT_003b7ebc;
extern undefined DAT_0038d204;
extern undefined DAT_0038d208;
extern char DAT_00390f10[];
extern char DAT_00390f2c[];
extern int FUN_00010184();
extern void FUN_000104e0();
extern void FUN_0001bb2c();
extern void FUN_0001c5f4();
extern void FUN_0001c73c();
extern int FUN_0001c848();
extern undefined4 FUN_0001c8a0();
extern void FUN_001be0d0();

void FUN_001c1c84(undefined4 *param_1)
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = *param_1;
  uVar1 = FUN_00010184(0x40,0x100000);
  FUN_0001bb2c(&DAT_003b3e6c,uVar1,0x100000);
  FUN_0001c5f4(&DAT_003b7ebc,DAT_00390f10);
  FUN_001be0d0(uVar3,&DAT_0038d204,1,0);
  FUN_0001c73c(&DAT_003b7ebc);
  FUN_0001c5f4(&DAT_003b7ebc,DAT_00390f2c);
  FUN_001be0d0(uVar3,&DAT_0038d208,3,0);
  FUN_0001c73c(&DAT_003b7ebc);
  uVar3 = FUN_0001c848();
  uVar2 = FUN_0001c8a0();
  FUN_0001bb2c(&DAT_003b3e6c,uVar3,uVar2);
  FUN_000104e0(uVar1);
  return;
}
