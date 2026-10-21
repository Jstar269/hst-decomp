/* HSTMATCH module=EBOOT.BIN start=0x0026f998 end=0x0026fcec symbol=FUN_0026f998 lang=c99 */
#pragma opt_strength_reduction off
typedef struct Elem {
  unsigned char f0;
  char f1;
  unsigned char f2;
  char f3;
  unsigned char f4;
  char pad5[3];
  int f8;
  char padc[0xc];
  int f18;
  char pad1c[0x14];
} Elem;
typedef struct Vec {
  Elem *data;
  unsigned size;
} Vec;
typedef struct Obj {
  char pad[0x90];
  Vec v90;
  char pad98[0x10];
  Vec va8;
  char padb0[4];
  Vec vb4;
  char padbc[4];
  Vec vc0;
  char padc8[4];
  Vec vcc;
} Obj;

extern char *DAT_003415a8;
extern char *DAT_00341ccc;
extern void FUN_001bf884();
extern void FUN_001bf980();
extern void FUN_001bf948();
extern void FUN_001bf9b8();
extern void FUN_001bfdd0();

void FUN_0026f998(Obj *self)
{
  unsigned i;
  Elem *e;

  i = 0;
  if (self->v90.size != 0) {
    do {
      e = &self->v90.data[i];
      if (e->f0 != 0) {
        if (e->f2 == 0 && e->f4 != 0) {
          FUN_001bf884(DAT_003415a8 + 0x80, e->f8, 3);
        }
      }
      i++;
    } while (i < self->v90.size);
  }
  i = 0;
  if (self->va8.size != 0) {
    do {
      e = &self->va8.data[i];
      if (e->f0 != 0) {
        if (e->f2 == 0 && e->f4 != 0) {
          FUN_001bf980(DAT_003415a8 + 0x80, e->f8, 3);
        }
      }
      i++;
    } while (i < self->va8.size);
  }
  i = 0;
  if (self->vb4.size != 0) {
    do {
      e = &self->vb4.data[i];
      if (e->f0 != 0) {
        if (e->f2 == 0 && e->f4 != 0) {
          FUN_001bf948(DAT_003415a8 + 0x80, e->f8, 3);
        }
      }
      i++;
    } while (i < self->vb4.size);
  }
  i = 0;
  if (self->vc0.size != 0) {
    do {
      e = &self->vc0.data[i];
      if (e->f0 != 0) {
        if (e->f2 == 0 && e->f4 != 0) {
          FUN_001bf9b8(DAT_003415a8 + 0x80, e->f8, 3);
        }
      }
      i++;
    } while (i < self->vc0.size);
  }
  i = 0;
  if (self->vcc.size != 0) {
    do {
      e = &self->vcc.data[i];
      if (e->f0 != 0) {
        if (e->f2 == 0 && e->f4 != 0) {
          int k = e->f18;
          if (k == 0) {
            FUN_001bfdd0(DAT_00341ccc, 7, e->f8, 3);
          } else if (k == 1) {
            FUN_001bfdd0(DAT_00341ccc, 8, e->f8, 3);
          } else if (k == 2) {
            FUN_001bfdd0(DAT_00341ccc, 9, e->f8, 3);
          } else if (k == 3) {
            FUN_001bfdd0(DAT_00341ccc, 10, e->f8);
          } else if (k == 4) {
            FUN_001bfdd0(DAT_00341ccc, 11, e->f8);
          } else if (k == 5) {
            *(unsigned char *)(DAT_00341ccc + 0x1024) = 3;
          } else if (k == 7) {
            FUN_001bfdd0(DAT_00341ccc, 5, e->f8);
          } else if (k == 6) {
            FUN_001bfdd0(DAT_00341ccc, 6, e->f8);
          }
        }
      }
      i++;
    } while (i < self->vcc.size);
  }
}
// NEAR MISS (213/213 words, 25 differ; sn3, ~12 compiles): four 48-byte-element vector loops (data at +0x90/0xa8/0xb4/0xc0, size = next word, recomputed index*48 per pass => `#pragma opt_strength_reduction off`,
// `i = 0` hoisted above the `if (size != 0)` guard) are retail-exact; so is the fifth loop's if/else ladder (0,1,2,3,4,5,7,6 with the K&R-declared FUN_001bfdd0 called with 3 or 4 args).
// Only the fifth loop's registers differ: retail keeps the element in a2 (`lw a2,8(a2)` for the argument) and the kind e->f18 in a0, with the constant 3 in a3 reused for the `k == 3` test
// and the 4th argument (and 5 in a1); ours puts the element in a3 and the kind in a2. Ruled out: char-pointer access, k declared at top, offset temp reused for k, per-loop element variable.
// near miss from lane sn3 (unreviewed)
