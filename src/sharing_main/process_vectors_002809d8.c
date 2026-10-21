/* HSTMATCH module=hstp_trans_main.prx start=0x002809d8 end=0x00280d2c symbol=FUN_002809d8 lang=c99 */
/* Clone of src/eboot/process_vectors_0026f998.c (hstclone.py tag c21rt1s): addresses substituted; exact match verified; names and types await human review. */
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

extern char *DAT_003ea8e8;
extern char *DAT_003eb004;
extern void FUN_001cd610(char *, int, int);
extern void FUN_001cd780(char *, int, int);
extern void FUN_001cd708(char *, int, int);
extern void FUN_001cd7f8(char *, int, int);
extern void FUN_001cdd24(char *, int, int, int);

void FUN_002809d8(Obj *self)
{
  unsigned i;
  Elem *e;

  i = 0;
  if (self->v90.size != 0) {
    do {
      e = &self->v90.data[i];
      if (e->f0 != 0) {
        if (e->f2 == 0 && e->f4 != 0) {
          FUN_001cd610(DAT_003ea8e8 + 0x80, e->f8, 3);
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
          FUN_001cd780(DAT_003ea8e8 + 0x80, e->f8, 3);
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
          FUN_001cd708(DAT_003ea8e8 + 0x80, e->f8, 3);
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
          FUN_001cd7f8(DAT_003ea8e8 + 0x80, e->f8, 3);
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
            FUN_001cdd24(DAT_003eb004, 7, e->f8, 3);
          } else if (k == 1) {
            FUN_001cdd24(DAT_003eb004, 8, e->f8, 3);
          } else if (k == 2) {
            FUN_001cdd24(DAT_003eb004, 9, e->f8, 3);
          } else if (k == 3) {
            FUN_001cdd24(DAT_003eb004, 10, e->f8, 3);
          } else if (k == 4) {
            FUN_001cdd24(DAT_003eb004, 11, e->f8, 3);
          } else if (k == 5) {
            *(unsigned char *)(DAT_003eb004 + 0x1024) = 3;
          } else if (k == 7) {
            FUN_001cdd24(DAT_003eb004, 5, e->f8, 3);
          } else if (k == 6) {
            FUN_001cdd24(DAT_003eb004, 6, e->f8, 3);
          }
        }
      }
      i++;
    } while (i < self->vcc.size);
  }
}
