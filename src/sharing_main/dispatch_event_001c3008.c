/* HSTMATCH module=hstp_trans_main.prx start=0x001c3008 end=0x001c318c symbol=FUN_001c3008 lang=c99 rodata=0x002d66b8 */
/* Clone of src/eboot/dispatch_event_001b53f4.c (hstclone.py tag c21sn6s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: case 0 leaves through a goto to the final return 0 (a plain return 0 there puts move v0,zero ahead of lw ra in the shared epilogue); rodata=0x2d66b8 is the 26-entry jump table; names and types await human review. */
extern void FUN_001c41bc(void *, int);
extern void FUN_001c437c(void *);
extern void FUN_001c4528(void *);
extern void FUN_001c4530(void *);
extern void FUN_001c4538(void *);
extern void FUN_001c4584(void *);
extern void FUN_001c473c(void *);
extern void FUN_001c481c(void *);
extern void FUN_001c4824(void *);
extern void FUN_001c482c(void *);
extern void FUN_001c4a70(void *);
extern void FUN_001c4ad4(void *);
extern void FUN_001c4adc(void *);
extern void FUN_001c4ae4(void *);
extern void FUN_001c4c28(void *);
extern void FUN_001c4dc0(void *);
extern void FUN_001c4dc8(void *);
extern void FUN_001c4e10(void *);
extern void FUN_001c4e84(void *);
extern void FUN_001c4ed0(void *);
extern void FUN_001c4ed8(void *);

int FUN_001c3008(void *self, unsigned mode)
{
  switch (mode) {
  case 0:
    FUN_001c41bc(self, 0);
    goto out;
  case 4:
    FUN_001c437c(self);
    break;
  case 5:
    FUN_001c4528(self);
    break;
  case 6:
    FUN_001c4530(self);
    break;
  case 7:
    FUN_001c4538(self);
    break;
  case 8:
    FUN_001c4584(self);
    break;
  case 14:
    FUN_001c473c(self);
    break;
  case 15:
    FUN_001c481c(self);
    break;
  case 20:
    FUN_001c482c(self);
    break;
  case 21:
    FUN_001c4a70(self);
    break;
  case 10:
    FUN_001c4ad4(self);
    break;
  case 11:
    FUN_001c4adc(self);
    break;
  case 22:
    FUN_001c4824(self);
    break;
  case 12:
    FUN_001c4ae4(self);
    break;
  case 13:
    FUN_001c4c28(self);
    break;
  case 16:
    FUN_001c4dc0(self);
    break;
  case 17:
    FUN_001c4dc8(self);
    break;
  case 18:
    FUN_001c4e10(self);
    break;
  case 19:
    FUN_001c4e84(self);
    break;
  case 24:
    FUN_001c4ed0(self);
    break;
  case 25:
    FUN_001c4ed8(self);
    break;
  }
out:
  return 0;
}
