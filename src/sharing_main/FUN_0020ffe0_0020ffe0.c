/* HSTMATCH module=hstp_trans_main.prx start=0x0020ffe0 end=0x00210050 symbol=FUN_0020ffe0 lang=c99 */
/* Clone of src/eboot/FUN_00201810_00201810.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the helper parameters and passed the first field by address; exact match verified; names and types await human review. */
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

extern void FUN_0022687c(void *param_1,int param_2,int param_3,int param_4,int param_5,int param_6);
extern void FUN_002268dc();

struct Ref_718 { char pad[0x718]; int field; };

void FUN_0020ffe0(int param_1)
{
  FUN_0022687c(&((struct Ref_718 *)param_1)->field,*(short *)(param_1 + 0x720) + -0xf0,(int)*(short *)(param_1 + 0x722),
               (int)*(short *)(param_1 + 0x720),(int)*(short *)(param_1 + 0x722),6);
  FUN_0022687c((void *)((char *)param_1 + 0x830),(int)*(short *)(param_1 + 0x838),*(short *)(param_1 + 0x83a) + 0x88,
               (int)*(short *)(param_1 + 0x838),(int)*(short *)(param_1 + 0x83a),6);
  FUN_002268dc(param_1 + 0xb78,*(uint *)(param_1 + 0xb98) & 0xffffff,*(uint *)(param_1 + 0xb98),6);
  return;
}
