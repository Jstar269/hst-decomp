/* HSTMATCH module=hstp_trans_main.prx start=0x000df814 end=0x000df888 symbol=FUN_000df814 lang=c99 */
/* Clone of src/eboot/FUN_000db7f4.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: the two odd-address globals typed as bytes; exact match verified; names and types await human review. */
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

extern undefined DAT_003eabd3;
extern undefined DAT_003eacf3;
extern uint * FUN_000114c0();

void FUN_000df814(int param_1)
{
  FUN_000114c0((uint *)(param_1 + 0xd8),0,0x30);
  *(uint *)(param_1 + 0xd0) = (uint)DAT_003eabd3;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(uint *)(param_1 + 0xd4) = (uint)DAT_003eacf3;
  *(undefined4 *)(param_1 + 200) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(undefined4 *)(param_1 + 0x48) = 1;
  *(undefined4 *)(param_1 + 0x4c) = 1;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x58) = 1;
  *(undefined1 *)(param_1 + 0x108) = 0;
  return;
}
