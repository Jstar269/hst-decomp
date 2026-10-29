/* HSTMATCH module=EBOOT.BIN start=0x000fb2d0 end=0x000fb44c symbol=FUN_000fb2d0 lang=c++ data=0x002d826c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d826c-0x002d8278) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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
/* Owner of the emoji display; only its wait counter is touched here. */
struct EmojiOwner {
  char pad[0x48];
  int waitTime;           /* 0x48 positive while an emoji is still showing */
};

/* Source object: current mode id at +0x38 and a position vector at +0x10. */
struct EmojiSource {
  char pad[0x38];
  int mode;               /* 0x38 */
};

extern "C" {
extern float DAT_002d8260;
extern float DAT_002d8264;
extern int DAT_002d8268;
void FUN_000fb44c(char *msg);
void FUN_000fb478(EmojiOwner *owner, int rank, float *pos);
float FUN_000224d8(float *a, float *b);
float FUN_00022e44(float v);
}

/* Show the emoji for the source's mode when the speed passes the thresholds and the owner is idle. */
extern "C" void FUN_000fb2d0(EmojiOwner *self, EmojiSource *source, float *velocity)
{
  int rank = -1;
  int mode = source->mode;

  if (self->waitTime > 0) {
    FUN_000fb44c("EmojiWait!\n");
  } else {
    switch (mode) {
    case 22: rank = 0; break;
    case 2: rank = 1; break;
    case 26: rank = 2; break;
    case 13: rank = 3; break;
    case 32: rank = 4; break;
    case 43: rank = 5; break;
    case 48: rank = 6; break;
    case 25: rank = 7; break;
    case 14: rank = 8; break;
    case 24: rank = 9; break;
    case 21: rank = 10; break;
    case 23: rank = 11; break;
    case 28: rank = 12; break;
    case 31: rank = 14; break;
    }
    if (rank >= 0) {
      float speed = FUN_00022e44(FUN_000224d8(velocity, velocity));
      if (speed * 3.6f >= DAT_002d8260) {
        rank += 15;
      }
      if (speed * 3.6f >= DAT_002d8264) {
        FUN_000fb478(self, rank, (float *)((char *)source + 16));
        self->waitTime = DAT_002d8268;
      }
    }
  }
}
