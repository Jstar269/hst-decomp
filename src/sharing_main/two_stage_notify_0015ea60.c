/* HSTMATCH module=hstp_trans_main.prx start=0x0015ea60 end=0x0015ead0 symbol=FUN_0015ea60 lang=c99 */
/* Clone of src/eboot/two_stage_notify_001527e8.c (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: DAT_003e9630 is an unsigned char flag (lbu), not undefined4; exact match verified; names and types await human review. */
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

extern unsigned char DAT_003e9630;
extern char DAT_00383b84[];
extern void FUN_00158b2c();
extern void FUN_0015bb68();
extern void FUN_00299058();

undefined4 FUN_0015ea60(int param_1,int param_2)
{
  if (*(int *)(param_2 + 0xc) != 0) {
    FUN_00299058(*(int *)(param_2 + 0xc),*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 8)
                );
  }
  if (DAT_003e9630 != '\0') {
    FUN_00158b2c(param_2);
    FUN_0015bb68(DAT_00383b84,*(undefined4 *)(param_1 + 0xc),
                 *(undefined4 *)(param_1 + 8));
  }
  return 0;
}
