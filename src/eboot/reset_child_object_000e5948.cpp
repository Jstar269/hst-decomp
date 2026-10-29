/* HSTMATCH module=EBOOT.BIN start=0x000e5948 end=0x000e59e4 symbol=FUN_000e5948 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py candidate FUN_000e5948) corrected by hand: single null-tested new/construct chain with the store after the if; readability pass; exact match verified; names and types await human review. */

#define CHILD_SIZE 0xc0

extern "C" {
extern int FUN_00000bcc(int);
extern void FUN_0001f21c(int, void *);
extern void *FUN_000e1584(void *, int, int, int);
}

struct VC_0 { virtual ~VC_0(); };

struct ChildHolder {
  char pad00[0x48];
  VC_0 *child;              /* 0x48 */
};

/* Destroys the current child object and builds a new one from the three arguments. */
extern "C" void FUN_000e5948(ChildHolder *self, int a, int b)
{
  VC_0 *p = self->child;

  if (p != 0 && p != 0) {
    delete p;
    self->child = 0;
  }
  p = (VC_0 *)FUN_00000bcc(CHILD_SIZE);
  if (p != 0) p = (VC_0 *)FUN_000e1584(p, (int)self, a, b);
  self->child = p;
  FUN_0001f21c((int)self, p);
}
