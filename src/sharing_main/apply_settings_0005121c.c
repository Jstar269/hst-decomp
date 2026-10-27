/* HSTMATCH module=hstp_trans_main.prx start=0x0005121c end=0x00051324 symbol=FUN_0005121c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* When f1a010 is set, passes the three stored values f1a014/f1a018/f1a01c to the setters 0x3cabc/0x3caa4/0x3cab0 (each stores into the f1a00c object and returns 0) and reports a non-zero result with FUN_0004f864 (i3d.cpp lines 1993, 2000, 2007). The fields sit past 0x7fff, so MWCC addresses each one through the 0x20000 page (lui 0x2; addu; negative displacement). */
extern char DAT_003767fc;
extern char DAT_003763c8;
extern char DAT_003ba4b0;
extern int FUN_0003cabc(int, int);
extern int FUN_0003caa4(int, int);
extern int FUN_0003cab0(int, int);
extern void FUN_0004f864(void *, int, void *, int, void *);

typedef struct {
  char pad[0x1a00c];
  int f1a00c;
  int f1a010;
  int f1a014;
  int f1a018;
  int f1a01c;
} BigObj;

void FUN_0005121c(BigObj *self)
{
  int r;

  if (self->f1a010 != 0) {
    r = FUN_0003cabc(self->f1a00c, self->f1a014);
    if (r != 0) {
      FUN_0004f864(&DAT_003ba4b0, r, &DAT_003763c8, 1993, &DAT_003767fc);
    }
    r = FUN_0003caa4(self->f1a00c, self->f1a018);
    if (r != 0) {
      FUN_0004f864(&DAT_003ba4b0, r, &DAT_003763c8, 2000, &DAT_003767fc);
    }
    r = FUN_0003cab0(self->f1a00c, self->f1a01c);
    if (r != 0) {
      FUN_0004f864(&DAT_003ba4b0, r, &DAT_003763c8, 2007, &DAT_003767fc);
    }
  }
}
