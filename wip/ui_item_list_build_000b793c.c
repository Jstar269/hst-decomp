/* HSTMATCH module=EBOOT.BIN start=0x000b793c end=0x000b7d6c symbol=FUN_000b793c lang=c99 */
/* Hand-written reconstruction from the disassembly; near miss, not exact; names and types await human review. */
#pragma opt_loop_invariants off
typedef struct { int p; } Res;
typedef struct { int vptr; int f4; } Obj8;
typedef struct { int vptr; int f4; int f8; char name[16]; } Obj1c;
typedef struct { int vptr; int f4; int f8; char name[16]; char name2[16]; } Obj2c;
typedef struct { char pad[0xa8]; void *fa8; } Self;
typedef struct { char pad[0x45]; unsigned char f45; } Game;
extern char DAT_003072d4;
extern char DAT_003072f8;
extern char DAT_0030731c;
extern char DAT_00307340;
extern char DAT_00307364;
extern char DAT_00307388;
extern char DAT_003073ac;
extern char DAT_002d47f4;
extern char DAT_002d47d4[];
extern char DAT_002d47dc[];
extern char DAT_002d47e8[];
extern char DAT_002d47fc[];
extern char DAT_002d4808[];
extern char DAT_002d4810[];
extern char DAT_002d481c[];
extern char DAT_002d4824[];
extern char DAT_002d4830[];
extern char DAT_002d483c[];
extern Game *DAT_00338b44;
extern void *FUN_00000bcc(int);
extern void FUN_000143b0(char *, char *, int);
extern char *FUN_000149a8(char *, char *);
extern void *FUN_0015e2ac(void *, char *);
extern Res FUN_0015e470(void *, void *);

void FUN_000b793c(Self *self)
{
  Obj8 *p8;
  Obj8 *p8b;
  void *child;
  void *root;
  Obj1c *p1c;
  Obj2c *p2c;
  int n;
  int i;
  char buf[16];

  p8 = FUN_00000bcc(8);
  if (p8 != 0) {
    p8->vptr = (int)&DAT_003073ac;
    p8->f4 = 0;
    p8->vptr = (int)&DAT_00307388;
    p8->vptr = (int)&DAT_00307364;
  }
  FUN_0015e470(self->fa8, p8);
  p8b = FUN_00000bcc(8);
  if (p8b != 0) {
    p8b->vptr = (int)&DAT_003073ac;
    p8b->f4 = 0;
    p8b->vptr = (int)&DAT_00307388;
    p8b->vptr = (int)&DAT_00307340;
  }
  FUN_0015e470(self->fa8, p8b);
  root = FUN_00000bcc(0x20);
  if (root != 0) root = FUN_0015e2ac(root, DAT_002d47d4);
  if (DAT_00338b44->f45 != 0) n = 2; else n = 4;
  i = 0;
  if (n > 0) {
    do {
      FUN_000143b0(buf, DAT_002d47dc, i);
      child = FUN_00000bcc(0x20);
      if (child != 0) child = FUN_0015e2ac(child, buf);
      if ((p1c = FUN_00000bcc(0x1c)) != 0) {
        p1c->vptr = (int)&DAT_003073ac;
        p1c->f4 = 0;
        p1c->vptr = (int)&DAT_00307388;
        p1c->vptr = (int)&DAT_0030731c;
        p1c->f8 = i;
        FUN_000149a8(p1c->name, DAT_002d47e8);
        p1c->name[7] = i + '0';
      }
      FUN_0015e470(child, p1c);
      if ((p2c = FUN_00000bcc(0x2c)) != 0) {
        p2c->vptr = (int)&DAT_003073ac;
        p2c->f4 = 0;
        p2c->vptr = (int)&DAT_00307388;
        p2c->vptr = (int)&DAT_0030731c;
        p2c->f8 = i;
        FUN_000149a8(p2c->name, DAT_002d47e8);
        p2c->name[7] = i + '0';
        p2c->vptr = (int)&DAT_003072f8;
        FUN_000149a8(p2c->name, &DAT_002d47f4);
        FUN_000149a8(p2c->name2, DAT_002d47fc);
      }
      FUN_0015e470(child, p2c);
      if ((p2c = FUN_00000bcc(0x2c)) != 0) {
        p2c->vptr = (int)&DAT_003073ac;
        p2c->f4 = 0;
        p2c->vptr = (int)&DAT_00307388;
        p2c->vptr = (int)&DAT_0030731c;
        p2c->f8 = i;
        FUN_000149a8(p2c->name, DAT_002d47e8);
        p2c->name[7] = i + '0';
        p2c->vptr = (int)&DAT_003072f8;
        FUN_000149a8(p2c->name, DAT_002d4808);
        FUN_000149a8(p2c->name2, DAT_002d4810);
      }
      FUN_0015e470(child, p2c);
      if ((p2c = FUN_00000bcc(0x2c)) != 0) {
        p2c->vptr = (int)&DAT_003073ac;
        p2c->f4 = 0;
        p2c->vptr = (int)&DAT_00307388;
        p2c->vptr = (int)&DAT_0030731c;
        p2c->f8 = i;
        FUN_000149a8(p2c->name, DAT_002d47e8);
        p2c->name[7] = i + '0';
        p2c->vptr = (int)&DAT_003072f8;
        FUN_000149a8(p2c->name, DAT_002d481c);
        FUN_000149a8(p2c->name2, DAT_002d4824);
      }
      FUN_0015e470(child, p2c);
      if ((p2c = FUN_00000bcc(0x2c)) != 0) {
        p2c->vptr = (int)&DAT_003073ac;
        p2c->f4 = 0;
        p2c->vptr = (int)&DAT_00307388;
        p2c->vptr = (int)&DAT_0030731c;
        p2c->f8 = i;
        FUN_000149a8(p2c->name, DAT_002d47e8);
        p2c->name[7] = i + '0';
        p2c->vptr = (int)&DAT_003072d4;
        FUN_000149a8(p2c->name, DAT_002d4830);
        FUN_000149a8(p2c->name2, DAT_002d483c);
      }
      FUN_0015e470(child, p2c);
      FUN_0015e470(root, child);
      i++;
    } while (i < n);
  }
  FUN_0015e470(self->fa8, root);
}

// Structurally complete near miss (20 of 268 words differ, ALL of them saved-register colours; code, branches, delay slots, frame 96 and the
// nine 4-byte sret result slots at sp+48..76 are exact). Retail colours: i s0, root s1, self s2, n s3, child s4, obj s5; ours: i s0, root s1,
// child s2, self s3, n s4, obj s5 (the loop-local `child` is coloured before the param and `n`).
// Found: (1) plain C with `#pragma opt_loop_invariants off` (otherwise the vtable-address lui/addiu constants are hoisted into s6..s8 and the frame grows
// to 112); (2) `if ((p = FUN_00000bcc(n)) != 0)` gives retail's `beqz v0; move sN,v0` (a separate `p = ..; if (p)` tests the saved register);
// (3) `if (flag != 0) n = 2; else n = 4;` gives `beqzl v0; li 4; li 2`; (4) the dead triple vptr stores are kept in C.
// Ruled out: all 24 orders of {root, child, n, i} (x2 with the object pointers first), block-scope loop locals, a local copy of the parameter in all 120 orders with
// the others, `int n = cond ? 2 : 4;`, pointer variable shared by the five objects. C++ with real classes (vtables + inline ctor chain, vptr declared first) reaches
// the same body but keeps a second register for the derived `this` (`move s5,s4`, +6 words), so it is worse.
