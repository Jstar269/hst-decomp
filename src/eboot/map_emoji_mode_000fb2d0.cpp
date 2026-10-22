/* HSTMATCH module=EBOOT.BIN start=0x000fb2d0 end=0x000fb44c symbol=FUN_000fb2d0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Maps the mode of the object at +0x38 to a rank (0..14) and, when the owner at +0x48 is idle,
   reports the rank: the rank is raised by 15 when the length of the vector at the third argument
   times 3.6 reaches the threshold in DAT_002d8260, and the vector at +0x10 of the second argument
   is handed to FUN_000fb478 (with the rank) once the second threshold DAT_002d8264 is reached;
   the owner flag is then set to DAT_002d8268. While the owner is busy the "EmojiWait" message
   (DAT_002d826c) is logged instead.
   Matching idioms: the switch is a chain of branch-likely comparisons whose delay slot holds the
   case value, so the cases have to be written in the reverse of the order MWCC emits them and the
   default must be -1 (the "li s0,-1" sits in the delay slot of the guard branch); the mode is read
   into a local BEFORE the guard so that the load stays in front of the branch; the two float
   thresholds are compared with the product on the left ("f * 3.6f >= DAT_...") because retail
   compares with c.nge.s/bc1t and not with c.le.s/bc1f; the length is the square root of the dot
   product of the third argument with itself (FUN_000224d8 is a vdot.t helper, FUN_00022e44 a
   sqrt.s helper). */
struct Obj {
  char pad[0x48];
  int f48;
};

struct Thing {
  char pad[0x38];
  int f38;
};

extern "C" {
extern float DAT_002d8260;
extern float DAT_002d8264;
extern int DAT_002d8268;
extern char DAT_002d826c[];
void FUN_000fb44c(char *msg);
void FUN_000fb478(Obj *owner, int r, float *p);
float FUN_000224d8(float *a, float *b);
float FUN_00022e44(float v);
}

extern "C" void FUN_000fb2d0(Obj *self, Thing *a1, float *a2)
{
  int r = -1;
  int mode = a1->f38;

  if (self->f48 > 0) {
    FUN_000fb44c(DAT_002d826c);
  } else {
    switch (mode) {
    case 22: r = 0; break;
    case 2: r = 1; break;
    case 26: r = 2; break;
    case 13: r = 3; break;
    case 32: r = 4; break;
    case 43: r = 5; break;
    case 48: r = 6; break;
    case 25: r = 7; break;
    case 14: r = 8; break;
    case 24: r = 9; break;
    case 21: r = 10; break;
    case 23: r = 11; break;
    case 28: r = 12; break;
    case 31: r = 14; break;
    }
    if (r >= 0) {
      float f = FUN_00022e44(FUN_000224d8(a2, a2));
      if (f * 3.6f >= DAT_002d8260) {
        r += 15;
      }
      if (f * 3.6f >= DAT_002d8264) {
        FUN_000fb478(self, r, (float *)((char *)a1 + 16));
        self->f48 = DAT_002d8268;
      }
    }
  }
}
