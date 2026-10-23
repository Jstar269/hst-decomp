/* HSTMATCH module=EBOOT.BIN start=0x000bcd8c end=0x000bce08 symbol=FUN_000bcd8c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Obj {
  char pad[0x10];
  unsigned short f10;
  char pad2[0x28 - 0x12];
  int f28;
  char pad3[0x17c - 0x2c];
  int f17c;
  char pad4[0x190 - 0x180];
  int f190;
  int f194;
};

extern char *DAT_00338ac4;
int FUN_000bda40(char *, char *, int, int, int);

void FUN_000bcd8c(struct Obj *self)
{
  int v;

  self->f194 = self->f190;
  self->f28 = 0xb;
  switch (self->f28) {
  case 4:
  case 8:
    v = FUN_000bda40(DAT_00338ac4, DAT_00338ac4 + 56, self->f10, 1444, 0);
    self->f17c = v & 0xff;
    break;
  case 10:
    break;
  }
}
