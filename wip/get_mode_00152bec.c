/* HSTMATCH module=EBOOT.BIN start=0x00152bec end=0x00152c60 symbol=FUN_00152bec lang=c99 */
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

extern unsigned char DAT_003402f0;
extern char DAT_002dc6c8[];
extern void FUN_0014d044(void *);
extern void FUN_0014fd94(const char *, ...);
extern int FUN_0014c384(int, int);
extern int FUN_00288b68(void *);

undefined4 FUN_00152bec(int param_1, undefined4 *param_2)
{
  uint v;
  uint *p;
  if (DAT_003402f0 != 0) {
    FUN_0014d044(param_2);
    FUN_0014fd94(DAT_002dc6c8, *(int *)(param_1 + 8));
  }
  v = FUN_00288b68((void *)param_2[3]);
  p = (uint *)FUN_0014c384(*param_2, *(int *)(param_1 + 8));
  *p = v & 0xff;
  return 0;
}
// Near miss (7 words differ, all in the call/slot schedule and s0 sharing). Retail: lw a0,12(s0); jal 0x288b68; slot lw s0,0(s0) (the
// *param_2 value is loaded AFTER the argument and shares s0 with param_2); ours: jal 0x288b68 with lw a0,12(s0) in the slot, then lw a0,0(s0).
// Ruled out (~25 compiles): id as a local before/after the argument load (3 saved regs), const-qualified message pointer, one-statement
// *F(id,..) = G(..) (RHS call first, LHS args after), inline Store(id, idx, v) helpers (either evaluation order), comma-expression argument
// (t = p[3], id = *p, t), bool vs int return of 0x288b68 (bool double-masks; int & 0xff gives retail's single andi in the jal slot).
