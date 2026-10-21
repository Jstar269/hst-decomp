/* HSTMATCH module=EBOOT.BIN start=0x00130b48 end=0x00130cf8 symbol=FUN_00130b48 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: FUN_00063e44 takes the game pointer as a third argument that Ghidra drops (retail leaves it in a2, which also gives the pointer its a2 colour); names and types await human review. */
struct Sub80 {
  char pad[0x58];
  int f58;
};
struct Obj {
  char pad0[0x3c];
  int f3c;
  int f40;
  char pad1[4];
  int f48;
  unsigned char f4c;
  char pad2[0x33];
  Sub80 *f80;
  char pad3[8];
  int f8c;
  char pad4[0x90];
  int f120;
  char pad5[0x10];
  unsigned char f134;
};
struct GameA { char pad[0x3c]; int f3c; };
struct GameB { char pad[0x3c]; int f3c; int f40; };
extern GameA *DAT_003386b0;
extern GameB *DAT_00340284;
extern char DAT_0033b5d5;
extern char DAT_0033b5d6;
extern "C" void *FUN_00000bcc(int);
extern "C" void *FUN_00063dc8(float, void *);
extern "C" void FUN_00063eb4(float, void *);
extern "C" void FUN_00063e44(void *, int, GameB *);
struct Item { int f0; float f4; };

extern "C" void FUN_00130b48(Obj *o)
{
  if (o->f120 >= 0) {
    o->f120 = o->f120 + 1;
  }
  if (o->f8c == 1 && o->f80 != 0) {
    int off = o->f80->f58 * 0x58;
    if ((&DAT_0033b5d5)[off] == 1 || (&DAT_0033b5d6)[off] == 1 || (&DAT_0033b5d5)[off] == 2 || (&DAT_0033b5d6)[off] == 2) {
      o->f134 = 1;
    }
  }
  if (DAT_003386b0->f3c == 7) {
    if (o->f48 == 0) {
      int ok = 1;
      if (o->f40 >= 0 && o->f3c < o->f40) {
        ok = 0;
      }
      if (!ok) {
        void *p = FUN_00000bcc(0x20);
        if (p) p = FUN_00063dc8(-1.0f, p);
        o->f48 = (int)p;
        FUN_00063eb4(3000.0f, p);
        ((Item *)o->f48)->f4 = 3000.0f;
        o->f4c = 1;
      }
    }
  }
  if (o->f40 >= 0) {
    o->f3c = o->f3c + 1;
  }
  int q = o->f48;
  if (q != 0) {
    int b = DAT_00340284->f40 < 0;
    if (!b) b = DAT_00340284->f40 <= DAT_00340284->f3c;
    if (b && q != 0) {
      FUN_00063e44((void *)q, 1, DAT_00340284);
      o->f48 = 0;
    }
  }
}
