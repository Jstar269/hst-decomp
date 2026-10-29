/* HSTMATCH module=EBOOT.BIN start=0x001b53f4 end=0x001b5578 symbol=FUN_001b53f4 lang=c99 rodata=0x2c61a8 */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: case 0 leaves through a goto to the final return 0 (a plain return 0 there puts move v0,zero ahead of lw ra in the shared epilogue); rodata=0x2c61a8 is the 26-entry jump table; names and types await human review. */
extern void FUN_001b64fc(void *, int);
extern void FUN_001b66bc(void *);
extern void FUN_001b6868(void *);
extern void FUN_001b6870(void *);
extern void FUN_001b6878(void *);
extern void FUN_001b68c4(void *);
extern void FUN_001b6a7c(void *);
extern void FUN_001b6b5c(void *);
extern void FUN_001b6b64(void *);
extern void FUN_001b6b6c(void *);
extern void FUN_001b6db0(void *);
extern void FUN_001b6e14(void *);
extern void FUN_001b6e1c(void *);
extern void FUN_001b6e24(void *);
extern void FUN_001b6f68(void *);
extern void FUN_001b7100(void *);
extern void FUN_001b7108(void *);
extern void FUN_001b7150(void *);
extern void FUN_001b71c4(void *);
extern void FUN_001b7210(void *);
extern void FUN_001b7218(void *);

/* Run the handler for the given mode id on the object (ids without a handler do nothing); always returns 0. */
int FUN_001b53f4(void *self, unsigned mode)
{
  switch (mode) {
  case 0:
    FUN_001b64fc(self, 0);
    goto out;
  case 4:
    FUN_001b66bc(self);
    break;
  case 5:
    FUN_001b6868(self);
    break;
  case 6:
    FUN_001b6870(self);
    break;
  case 7:
    FUN_001b6878(self);
    break;
  case 8:
    FUN_001b68c4(self);
    break;
  case 14:
    FUN_001b6a7c(self);
    break;
  case 15:
    FUN_001b6b5c(self);
    break;
  case 20:
    FUN_001b6b6c(self);
    break;
  case 21:
    FUN_001b6db0(self);
    break;
  case 10:
    FUN_001b6e14(self);
    break;
  case 11:
    FUN_001b6e1c(self);
    break;
  case 22:
    FUN_001b6b64(self);
    break;
  case 12:
    FUN_001b6e24(self);
    break;
  case 13:
    FUN_001b6f68(self);
    break;
  case 16:
    FUN_001b7100(self);
    break;
  case 17:
    FUN_001b7108(self);
    break;
  case 18:
    FUN_001b7150(self);
    break;
  case 19:
    FUN_001b71c4(self);
    break;
  case 24:
    FUN_001b7210(self);
    break;
  case 25:
    FUN_001b7218(self);
    break;
  }
out:
  return 0;
}
