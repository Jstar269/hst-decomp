/* HSTMATCH module=EBOOT.BIN start=0x0026f998 end=0x0026fcec symbol=FUN_0026f998 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand, starting from lane sn3's near-miss wip: the tail calls of the fifth loop pass the shared constant 3 as fourth argument too (Ghidra dropped it), which colours the element and kind registers like retail; prototypes added; exact match verified; names and types await human review. */
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
extern void FUN_001bf884(char *, int, int);
extern void FUN_001bf980(char *, int, int);
extern void FUN_001bf948(char *, int, int);
extern void FUN_001bf9b8(char *, int, int);
extern void FUN_001bfdd0(char *, int, int, int);

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
            FUN_001bfdd0(DAT_00341ccc, 10, e->f8, 3);
          } else if (k == 4) {
            FUN_001bfdd0(DAT_00341ccc, 11, e->f8, 3);
          } else if (k == 5) {
            *(unsigned char *)(DAT_00341ccc + 0x1024) = 3;
          } else if (k == 7) {
            FUN_001bfdd0(DAT_00341ccc, 5, e->f8, 3);
          } else if (k == 6) {
            FUN_001bfdd0(DAT_00341ccc, 6, e->f8, 3);
          }
        }
      }
      i++;
    } while (i < self->vcc.size);
  }
}
