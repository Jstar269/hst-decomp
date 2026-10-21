/* HSTMATCH module=hstp_trans_main.prx start=0x00159de8 end=0x00159eb4 symbol=FUN_00159de8 lang=c99 */
/* Clone of src/eboot/init_sum_loop_0014df40.c (hstclone.py tag c21sn2s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: the loop end is a fresh variable (`end = pos + count`, which gives retail's `addu s2,v0,s2` operand order); exact match verified; names and types await human review. */
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

extern undefined DAT_003b15a0;
extern undefined DAT_003b16d8;
extern undefined4 * FUN_0015a3fc();
extern undefined2 FUN_0015b050();
extern undefined4 FUN_0015b5e0();
extern undefined4 * FUN_0015b6e4();

undefined4 * FUN_00159de8(undefined4 *param_1,uint *param_2)
{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_4;
  undefined1 auStack_8 [4];
  undefined4 *local_c;
  
  *param_1 = (unsigned int)(&DAT_003b16d8);
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = (unsigned int)(&DAT_003b15a0);
  FUN_0015b6e4(param_1 + 2);
  uVar2 = FUN_0015b050(param_2);
  FUN_0015b050(param_2);
  uVar3 = *param_2;
  uVar4 = uVar3 + uVar2;
  while (uVar3 < uVar4) {
    uVar1 = FUN_0015b050(param_2);
    local_4 = (unsigned int)(FUN_0015a3fc(param_1,uVar1,param_2));
    local_c = param_1 + 3;
    FUN_0015b5e0(auStack_8,param_1 + 2,&local_c,&local_4);
    uVar3 = *param_2;
  }
  return param_1;
}
