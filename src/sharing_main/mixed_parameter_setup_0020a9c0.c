/* HSTMATCH module=hstp_trans_main.prx start=0x0020a9c0 end=0x0020aa34 symbol=FUN_0020a9c0 lang=c99 */
/* Clone of src/eboot/mixed_parameter_setup_001fc2a8.c (hstclone.py tag u5cr3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: interleaved integer and float arguments and materialized the scaled index before adding the object base; exact match verified; names and types await human review. */
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

extern void FUN_000f3588(int param_1,uint *param_2,float param_3,float param_4,int param_5,int param_6,float param_7,float param_8,float param_9);
extern void FUN_00105470();
extern void FUN_00108aec();

void FUN_0020a9c0(int param_1)
{
  int off;
  FUN_00105470(*(int *)(param_1 + 0x7c),(*(uchar *)(param_1 + 0x90) != 0) ^ 1);
  FUN_00108aec(param_1);
  off = *(int *)(param_1 + 0x8c) * 4;
  FUN_000f3588(*(int *)(off + param_1 + 0x80),
               *(uint **)(param_1 + 0x78),0.0f,0.0f,0,0,1.0f,1.0f,1.0f);
}
