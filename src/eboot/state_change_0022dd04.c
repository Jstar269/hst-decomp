/* HSTMATCH module=EBOOT.BIN start=0x0022dd04 end=0x0022e020 symbol=FUN_0022dd04 lang=c99 data=0x002f353c */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: typed object and address symbols (lui/addiu), if/else-if on the new value rewritten as a range test plus a one-case-group switch (cases 0x22, 0x23, 0x25), table index as an int array, header typedefs dropped; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002f353c-0x002f3587) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern char DAT_0034179c[];
extern char DAT_0030ab9c[];
extern char DAT_0030ebf4[];
extern int DAT_002f33e4[];
extern void *FUN_00010184(int, int);
extern void FUN_000104e0(void *);
extern void FUN_000143b0(char *, char *, int);
extern void FUN_0001bfb4(char *, void *, int);
extern void FUN_0001ca58(char *, char *);
extern void FUN_0001cb88(char *);
extern int FUN_0001cbfc(void);
extern int FUN_0001cc54(void);
extern void FUN_001b2430(char *);
extern void FUN_001b322c(char *);
extern void FUN_001b32e0(char *, int);
extern void FUN_001b32f8(char *, int);
extern void FUN_001b3378(char *, int);
extern void FUN_001b338c(char *, int);
extern void FUN_001b3ce8(char *, int);
extern void FUN_001b3e2c(char *);

typedef struct Obj {
  char pad0[0xa4];
  int fa4;
  int fa8;
  char pad1[0x25c - 0xac];
  int f25c;
} Obj;

void FUN_0022dd04(Obj *o)
{
  void *p;
  int a;
  int b;
  int n;
  int t;
  char buf[256];

  FUN_001b3e2c(DAT_0034179c);
  FUN_001b2430(DAT_0034179c);
  if (o->fa8 == -1) {
    p = FUN_00010184(0x40, 0xccccc);
    FUN_0001bfb4(DAT_0030ab9c, p, 0xccccc);
    FUN_0001ca58(DAT_0030ebf4, "menu/optionbgm/option_bgm_stream.xb");
    FUN_001b3378(DAT_0034179c, 0);
    FUN_001b3378(DAT_0034179c, 2);
    FUN_001b3378(DAT_0034179c, 6);
    FUN_001b322c(DAT_0034179c);
    FUN_0001cb88(DAT_0030ebf4);
    a = FUN_0001cbfc();
    b = FUN_0001cc54();
    FUN_0001bfb4(DAT_0030ab9c, (void *)a, b);
    FUN_000104e0(p);
  }
  t = DAT_002f33e4[o->f25c];
  o->fa4 = t;
  if (o->fa8 != t) {
    if (o->fa8 >= 0x28 && o->fa8 < 0x32) {
      FUN_001b32f8(DAT_0034179c, o->fa8 - 0x27);
    }
    if (o->fa4 >= 0x28 && o->fa4 < 0x32) {
      FUN_001b338c(DAT_0034179c, 0x22);
      FUN_001b338c(DAT_0034179c, 0x23);
      FUN_001b338c(DAT_0034179c, 0x25);
      n = o->fa4 - 0x27;
      p = FUN_00010184(0x40, 0x173333);
      FUN_0001bfb4(DAT_0030ab9c, p, 0x173333);
      FUN_000143b0(buf, "menu/optionbgm/option_bgm_lobby%02d.xb", n);
      FUN_0001ca58(DAT_0030ebf4, buf);
      FUN_001b32e0(DAT_0034179c, n);
      FUN_0001cb88(DAT_0030ebf4);
      a = FUN_0001cbfc();
      b = FUN_0001cc54();
      FUN_0001bfb4(DAT_0030ab9c, (void *)a, b);
      FUN_000104e0(p);
    } else {
      switch (o->fa4) {
      case 0x22:
      case 0x23:
      case 0x25:
        p = FUN_00010184(0x40, 0xccccc);
        FUN_0001bfb4(DAT_0030ab9c, p, 0xccccc);
        FUN_0001ca58(DAT_0030ebf4, "menu/optionbgm/option_bgm_stream.xb");
        FUN_001b3378(DAT_0034179c, o->fa4);
        FUN_0001cb88(DAT_0030ebf4);
        a = FUN_0001cbfc();
        b = FUN_0001cc54();
        FUN_0001bfb4(DAT_0030ab9c, (void *)a, b);
        FUN_000104e0(p);
        break;
      }
    }
  }
  FUN_001b3ce8(DAT_0034179c, o->fa4);
  o->fa8 = o->fa4;
}
