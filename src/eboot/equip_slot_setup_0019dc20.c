/* HSTMATCH module=EBOOT.BIN start=0x0019dc20 end=0x0019dd0c symbol=FUN_0019dc20 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Obj { char pad[4]; short *f4; char pad2[0x10 - 8]; char body; };

extern char DAT_002e1b68[];
char *FUN_000149a8(char *, const char *);
unsigned char *FUN_00193474(int);

void FUN_0019dc20(struct Obj *self, int x, short p3, short p4, short p5, short p6, short p7,
                  unsigned char p8, unsigned int p9, int p10, char *p11)
{
  unsigned char *rec;

  if (self->f4 != 0) {
    self->f4[0] = (short)x;
    self->f4[1] = p3;
    self->f4[2] = p4;
    self->f4[3] = p5;
    self->f4[4] = p6;
    self->f4[5] = p7;
    ((char (*)[3])((char *)self->f4 + 0x7d))[p10][0] = p8;
    *(char *)((char *)self->f4 + 0x7c) = p9;
  }
  if (p11 != 0) {
    FUN_000149a8((char *)self + 0x10, p11);
  } else {
    FUN_000149a8((char *)self + 0x10, DAT_002e1b68);
  }
  if (x >= 0 && x < 0xf) {
    rec = FUN_00193474(x);
    *((char *)self->f4 + 0xe) = 3;
    *((char *)self->f4 + 0xc) = rec[0xc];
    *((char *)self->f4 + 0xd) = rec[0xd];
  }
}
