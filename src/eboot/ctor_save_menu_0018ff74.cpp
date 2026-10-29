/* HSTMATCH module=EBOOT.BIN start=0x0018ff74 end=0x00190248 symbol=FUN_0018ff74 lang=c++ data=0x002e11b0 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string-pointer tables (1 tables, 1 strings, 0x002e11b0-0x002e11d4) are defined in place and placed with data= (tools/hstdatapool.py tables); before, the source named them through address externs. */
/* Menu object constructor: base ctor, vtable store, then a 0x57c-byte state block created with new + an inline constructor taking the owner (null-test on the allocation result, the block's fields zeroed, three sub-objects allocated, two save-slot descriptors filled with their icon/title strings and widgets created, with a temporary string object constructed and destroyed with delete-flag -1). The inline constructor form is what makes the allocation test use v0 with the copy to s0 in the delay slot. Names provisional. */
struct Tmp {
  int a, b, c, d, e, f;
};
struct Sub1;
struct Sub2;
struct Sub3;
struct Self;
struct MenuState {
  int f0, f4, f8, fc;
  Sub1 *f10;
  int f14;
  char pad18[0x24 - 0x18];
  char a24[0x10];
  char a34[0x10];
  const char *f44;
  const char *f48;
  int f4c;
  char pad50[8];
  int f58;
  char pad5c[4];
  char a60[0x20];
  char a80[0x10];
  const char *f90;
  const char *f94;
  int f98;
  char pad9c[0xa8 - 0x9c];
  unsigned char fa8;
  char pada9[3];
  unsigned char fac;
  unsigned char fad;
  unsigned char fae;
  char padaf;
  int fb0;
  char ab4[0x280 - 0xb4];
  Sub2 *f280;
  char a284[0x304 - 0x284];
  char a304[0x31c - 0x304];
  Sub3 *f31c;
  char a320[0x338 - 0x320];
  char a338[0x3f8 - 0x338];
  char a3f8[0x578 - 0x3f8];
  int f578;
  MenuState(Self *self);
};
struct Self {
  int vptr;
  char pad4[0x3c - 4];
  MenuState *state;
};
void *operator new(unsigned int);
extern "C" {
extern char DAT_00309178[];
extern char DAT_002c2544[];
extern char DAT_002c2534[];
extern char DAT_002c27d4[];
extern char DAT_002c27d0[];
extern char DAT_002c27c4[];
extern char DAT_002c27c0[];
extern int DAT_0034176c;
char *DAT_002e11d0 = "data/menu/saveicon/US/ICON0.PNG";
extern Self *DAT_003415d4;
void FUN_0001f06c(void *);
void *FUN_00000bcc(unsigned);
void FUN_00190368(void *);
void FUN_00190348(void *);
Sub1 *FUN_000c0738(void *);
void FUN_0001f21c(void *, void *);
void FUN_000c1624(void *);
void FUN_00011090(void *, void *, int);
int FUN_0018c9f4(int);
int FUN_0018f1ac(int, int, int);
int FUN_00198278(int, int, int, void *);
int FUN_0004cad0(char *, void *, int, int);
Sub2 *FUN_00190304(void *);
void FUN_001902d0(void *, int);
void FUN_00190290(void *, void *);
void FUN_0018f14c(void *, int);
int FUN_00190288(void *);
int FUN_00190268(int, int);
int FUN_0004577c(void *);
void FUN_00190260(int, int);
void FUN_00190258(int, int);
void FUN_00190250(int, void *);
void FUN_00190248(int, int);
Sub3 *FUN_00050fc0(void *);
}
inline MenuState::MenuState(Self *self)
{
    f0 = 0;
    f4 = 0;
    f8 = 0;
    fc = 0;
    fac = 0;
    fad = 0;
    fae = 0;
    fb0 = 0;
    FUN_00190368(ab4);
    f280 = 0;
    FUN_00190348(a304);
    f31c = 0;
    FUN_00190348(a320);
    f578 = 0;
    Sub1 *o1 = (Sub1 *)FUN_00000bcc(0x790);
    if (o1) o1 = FUN_000c0738(o1);
    f10 = o1;
    FUN_0001f21c(self, o1);
    FUN_000c1624(&f14);
    FUN_00011090(a34, DAT_002c2544, 16);
    f44 = DAT_002c27d4;
    f48 = DAT_002c27d0;
    int value = FUN_0018c9f4(0x11);
    value = FUN_0018f1ac(value, 12, 32);
    value = FUN_00198278(DAT_0034176c, value, 192, a338);
    f4c = value;
    f58 = 3;
    value = FUN_0004cad0(DAT_002e11d0, a24, 16, 1);
    f14 = value;
    FUN_000c1624(a60);
    FUN_00011090(a80, DAT_002c2534, 16);
    f90 = DAT_002c27c4;
    f94 = DAT_002c27c0;
    value = FUN_0018c9f4(0x11);
    value = FUN_0018f1ac(value, 12, 33);
    value = FUN_00198278(DAT_0034176c, value, 192, a3f8);
    f98 = value;
    fa8 = 0;
    Sub2 *o2 = (Sub2 *)FUN_00000bcc(0x88);
    if (o2) o2 = FUN_00190304(o2);
    f280 = o2;
    value = FUN_0018c9f4(0x11);
    value = FUN_0018f1ac(value, 13, 2);
    Tmp tmp;
    FUN_001902d0(&tmp, value);
    FUN_00190290(a320, &tmp);
    FUN_0018f14c(&tmp, -1);
    value = FUN_00190288(f280);
    value = FUN_00190268(value, 0);
    int u = FUN_0004577c(a320);
    FUN_00190260(value, u);
    value = FUN_00190288(f280);
    value = FUN_00190268(value, 0);
    FUN_00190258(value, 0x3f);
    value = FUN_00190288(f280);
    value = FUN_00190268(value, 0);
    FUN_00190250(value, a284);
    value = FUN_00190288(f280);
    value = FUN_00190268(value, 0);
    FUN_00190248(value, 6);
    FUN_0001f21c(self, f280);
    void *m = FUN_00000bcc(0x48);
    if (m) m = FUN_00050fc0(m);
    f31c = (Sub3 *)m;
}
extern "C" {
/* Constructor: base ctor, vtable, then allocate and fill the state block. */
Self *FUN_0018ff74(Self *self)
{
  FUN_0001f06c(self);
  self->vptr = (int)DAT_00309178;
  self->state = 0;
  MenuState *state = new MenuState(self);
  self->state = state;
  DAT_003415d4 = self;
  return self;
}
}
