/* HSTMATCH module=hstp_trans_main.prx start=0x000bdd78 end=0x000bde14 symbol=FUN_000bdd78 lang=c99 */
/* Hand-written reconstruction from the disassembly (adhoclib.cpp per the assert strings); exact match verified; names and types await human review. */
typedef struct Ctx {
  char pad[0x38];
  char sub[4];
} Ctx;

typedef struct Obj {
  char pad0[0x10];
  unsigned short f10;
  char pad1[0x28 - 0x12];
  int mode;
  char pad2[0x17c - 0x2c];
  int f17c;
} Obj;

extern Ctx *DAT_003e1e04;
extern char DAT_0037b7e4[];
extern char DAT_0037b810[];
extern char DAT_0037b818[];
extern void FUN_000bd6f0(char *, ...);
extern unsigned char FUN_000c0fbc(Ctx *, char *, unsigned short, int, int);

#define ASSERT(c, line) if (!(c)) { FUN_000bd6f0(DAT_0037b7e4, DAT_0037b810, DAT_0037b818, line); for (;;) {} }

void FUN_000bdd78(Obj *self, int mode)
{
  self->mode = mode;
  switch (mode) {
  case 4:
  case 8:
    self->f17c = FUN_000c0fbc(DAT_003e1e04, DAT_003e1e04->sub, self->f10, 0x5a4, 0);
    break;
  case 10:
    ASSERT(0, 313);
    break;
  }
}
