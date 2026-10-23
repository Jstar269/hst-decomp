/* HSTMATCH module=EBOOT.BIN start=0x002805fc end=0x002807d0 symbol=FUN_002805fc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   The three arms are written positive-test-first (a2 != 0, then a1 != 0): MWCC keeps the fall-through arm
   inline and puts the taken arm out of line, which is retail's layout. */
extern char s_IllegalErrorMessage__002fe8d4[];
extern char DAT_002c0e20;
extern char DAT_002c0e1c;
extern char DAT_002c0e18;
extern int DAT_003415ac;

typedef struct Named {
  char pad0[8];
  int f8;
} Named;

typedef struct Keep {
  char pad0[0xc0];
  void *fc0;
  int fc4;
} Keep;

typedef struct Node {
  char pad0[4];
  int f4;
  Named *f8;
  Keep *fc;
} Node;

extern void FUN_002803d8(char *);
extern Node *FUN_0018c9f4(int);
extern void FUN_00114168(int, int, void *, int, int);
extern void FUN_000143b0(int, void *, ...);

void FUN_002805fc(int a0, int a1, int a2, int a3)
{
  Node *n;
  char *name;

  if (a2 != 0) {
    n = FUN_0018c9f4(0x11);
    if (n->f4 == 0)
      name = &DAT_002c0e20;
    else if (n->f8->f8 < 0x11)
      name = &DAT_002c0e1c;
    else if (n->fc->fc4 < 0x12)
      name = &DAT_002c0e18;
    else
      name = *(char **)((char *)n->fc->fc0 + 0x44);
    FUN_000143b0(a0, name, a3);
    FUN_00114168(DAT_003415ac, 6, (void *)a0, 0, 0);
  } else if (a1 != 0) {
    n = FUN_0018c9f4(0x11);
    if (n->f4 == 0)
      name = &DAT_002c0e20;
    else if (n->f8->f8 < 0x11)
      name = &DAT_002c0e1c;
    else if (n->fc->fc4 < 0x11)
      name = &DAT_002c0e18;
    else
      name = *(char **)((char *)n->fc->fc0 + 0x40);
    FUN_00114168(DAT_003415ac, 6, name, 0, 0);
    if (a0 != 0)
      FUN_000143b0(a0, name);
  } else {
    FUN_002803d8(s_IllegalErrorMessage__002fe8d4);
    n = FUN_0018c9f4(0x11);
    if (n->f4 == 0)
      name = &DAT_002c0e20;
    else if (n->f8->f8 < 0x11)
      name = &DAT_002c0e1c;
    else if (n->fc->fc4 < 0x11)
      name = &DAT_002c0e18;
    else
      name = *(char **)((char *)n->fc->fc0 + 0x40);
    FUN_00114168(DAT_003415ac, 6, name, 0, 0);
  }
}
