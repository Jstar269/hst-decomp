/* HSTMATCH module=EBOOT.BIN start=0x000e5948 end=0x000e59e4 symbol=FUN_000e5948 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py candidate FUN_000e5948) corrected by hand: single null-tested new/construct chain with the store after the if; exact match verified; names and types await human review. */

extern "C" {
extern int FUN_00000bcc(int);
extern void FUN_0001f21c(int, void *);
extern void *FUN_000e1584(void *, int, int, int);
}

struct VC_0 { virtual ~VC_0(); };

extern "C" void FUN_000e5948(int param_1, int param_2, int param_3)
{
  VC_0 *p = *(VC_0 **)(param_1 + 0x48);

  if (p != 0 && p != 0) {
    delete p;
    *(VC_0 **)(param_1 + 0x48) = 0;
  }
  p = (VC_0 *)FUN_00000bcc(0xc0);
  if (p != 0) p = (VC_0 *)FUN_000e1584(p, param_1, param_2, param_3);
  *(VC_0 **)(param_1 + 0x48) = p;
  FUN_0001f21c(param_1, p);
}
