/* HSTMATCH module=hstp_trans_main.prx start=0x00299d58 end=0x00299db0 symbol=FUN_00299d58 lang=c99 */
/* Clone of src/eboot/helper_00288624.c (hstclone.py tag u6cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: modelled adjacent call fields as a 16-byte-aligned record (matching idiom: aligned local record); exact match verified; names and types await human review. */
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

extern undefined4 DAT_003f344c;
extern void FUN_001dae00();
extern undefined4 FUN_0029ace0();

struct WorkArgs_288624 {
  int field68;
  undefined1 result[4];
  int kind;
  int count;
  undefined4 id;
} __attribute__((aligned(16)));

void FUN_00299d58(int param_1,undefined4 param_2,int param_3)
{
  struct WorkArgs_288624 args;
  
  if (param_3 < 1) {
    FUN_001dae00(DAT_003f344c);
  }
  else {
    args.kind = 0x23;
    args.field68 = param_1 + 0x68;
    args.count = param_3;
    args.id = param_2;
    FUN_0029ace0(args.result,param_1 + 100,&args.field68,&args.kind);
  }
  return;
}
