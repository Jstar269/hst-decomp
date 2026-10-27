/* HSTMATCH module=EBOOT.BIN start=0x00050908 end=0x00050a10 symbol=FUN_00050908 lang=c99 */
/* Clone of src/sharing_main/apply_settings_0005121c.c (hstclone.py tag c072920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* When f1a010 is set, passes the three stored values f1a014/f1a018/f1a01c to the setters 0x3cabc/0x3caa4/0x3cab0 (each stores into the f1a00c object and returns 0) and reports a non-zero result with FUN_0004f010 (i3d.cpp lines 1993, 2000, 2007). The fields sit past 0x7fff, so MWCC addresses each one through the 0x20000 page (lui 0x2; addu; negative displacement). */
extern char DAT_002d0d40;
extern char DAT_002d0a6c;
extern char DAT_00311170;
extern int FUN_0003ca94(int, int);
extern int FUN_0003ca7c(int, int);
extern int FUN_0003ca88(int, int);
extern void FUN_0004f010(void *, int, void *, int, void *);

typedef struct {
  char pad[0x1a00c];
  int f1a00c;
  int f1a010;
  int f1a014;
  int f1a018;
  int f1a01c;
} BigObj;

void FUN_00050908(BigObj *self)
{
  int r;

  if (self->f1a010 != 0) {
    r = FUN_0003ca94(self->f1a00c, self->f1a014);
    if (r != 0) {
      FUN_0004f010(&DAT_00311170, r, &DAT_002d0a6c, 1993, &DAT_002d0d40);
    }
    r = FUN_0003ca7c(self->f1a00c, self->f1a018);
    if (r != 0) {
      FUN_0004f010(&DAT_00311170, r, &DAT_002d0a6c, 2000, &DAT_002d0d40);
    }
    r = FUN_0003ca88(self->f1a00c, self->f1a01c);
    if (r != 0) {
      FUN_0004f010(&DAT_00311170, r, &DAT_002d0a6c, 2007, &DAT_002d0d40);
    }
  }
}
