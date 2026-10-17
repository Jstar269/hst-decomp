/* HSTMATCH module=hstp_trans_main.prx start=0x00166aa0 end=0x00166c04 symbol=FUN_00166aa0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idiom: `int off = slot * 4; (Snd **)(off + (int)self + 0x34)` (offset-first addu; `&self->snd[slot]` gives `addu v0,s1,v0`, one word off). The flag is an `int` (a uchar local adds `andi 0xff`); `*pp` is re-read after the new/ctor (lw a0,0(s2)); the virtual deleting dtor is slot 0 of Snd (`delete *pp`). */
struct Snd { virtual ~Snd(); };
struct Chan { char b[0x100]; };
struct Vv { int x, y, z; float w; };
struct Self { char pad0[0x34]; Snd *snd[3]; Vv v[3]; Chan ch[3]; char str[1]; };
extern "C" {
extern unsigned char DAT_003eab04;
extern int DAT_003f398c;
extern char DAT_0038560c[];
extern char DAT_00385630[];
extern char DAT_003b7ebc[];
extern void FUN_000143b0(void *, char *, int);
extern int FUN_00014934(void *, void *);
extern void FUN_000149a8(void *, void *);
extern void FUN_0001c684(char *, int, void *);
extern void FUN_0001c73c(char *);
extern Snd *FUN_000518d4(void *);
extern void FUN_00051ad8(Snd *, void *, int);
extern void FUN_00051d38(float, Snd *);
}
extern "C" void FUN_00166aa0(Self *self, int slot)
{
  int flag = 1;
  if (DAT_003f398c == 0)
    flag = DAT_003eab04;
  FUN_000143b0(self->str, DAT_0038560c, flag);
  FUN_0001c684(DAT_003b7ebc, 1, self->str);
  FUN_000143b0(self->str, DAT_00385630, flag);
  int off = slot * 4;
  Snd **pp = (Snd **)(off + (int)self + 0x34);
  if (*pp == 0 || FUN_00014934(&self->ch[slot], self->str) != 0) {
    if (*pp != 0) {
      delete *pp;
      *pp = 0;
    }
    Snd *p = (Snd *)operator new(0x48);
    if (p != 0)
      p = FUN_000518d4(p);
    *pp = p;
    FUN_00051ad8(p, self->str, 0);
    FUN_00051d38(3000.0f, *pp);
    FUN_000149a8(&self->ch[slot], self->str);
    self->v[slot].x = 0;
    self->v[slot].y = 0;
    self->v[slot].z = 0;
    self->v[slot].w = 1.0f;
  }
  FUN_0001c73c(DAT_003b7ebc);
}
