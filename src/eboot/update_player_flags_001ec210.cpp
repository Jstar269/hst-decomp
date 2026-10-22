/* HSTMATCH module=EBOOT.BIN start=0x001ec210 end=0x001ec2f0 symbol=FUN_001ec210 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py candidate FUN_001ec210) corrected by hand: restored the dropped fourth pointer indirection, branchless int flag, bool second parameter and inverted final ternary; exact match verified; names and types await human review. */

extern "C" {
extern char *DAT_003386b0;
extern char *DAT_003415ac;
extern void FUN_000ffb3c(int, bool);
extern void FUN_00103128(char *);
}

struct VC_1 { virtual void d0(); virtual void m(int); };

extern "C" void FUN_001ec210(char *param_1)
{
  int v;
  int b;
  int *q;

  v = *(unsigned short *)(*(int *)(*(int *)(*(int *)(DAT_003415ac + 0x54) + 0x10)) + 0xe) & 3;
  b = (*(unsigned char *)(DAT_003386b0 + 0x4c) | (unsigned char)((v != 0) ^ 1)) != 0;
  ((VC_1 *)*(int **)(param_1 + 0x60))->m(b);
  FUN_000ffb3c(*(int *)(param_1 + 0xc0), (*(int *)(param_1 + 0x134) != 0) || b);
  FUN_000ffb3c(*(int *)(param_1 + 0xc4), (*(int *)(param_1 + 0x134) == 0) || b);
  v = *(int *)(param_1 + 0x134) != 0 ? 0 : 0x16;
  q = *(int **)(param_1 + 0xd0);
  q[9] = v;
  q[10] = v;
  FUN_00103128(param_1);
}
