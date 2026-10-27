/* HSTMATCH module=hstp_trans_main.prx start=0x0023de04 end=0x0023e120 symbol=FUN_0023de04 lang=c99 data=0x0039be00 */
/* Clone of src/eboot/state_change_0022dd04.c (hstclone.py tag c17b07b): addresses substituted; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x0039be00-0x0039be4b) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: typed object and address symbols (lui/addiu), if/else-if on the new value rewritten as a range test plus a one-case-group switch (cases 0x22, 0x23, 0x25), table index as an int array, header typedefs dropped; exact match verified; names and types await human review. */
extern char DAT_003eaad8[];
extern char DAT_003b3e6c[];
extern char DAT_003b7ebc[];
extern int DAT_0039bca8[];
extern void *FUN_00010184(int, int);
extern void FUN_000104e0(void *);
extern void FUN_000143b0(char *, char *, int);
extern void FUN_0001bb2c(char *, void *, int);
extern void FUN_0001c5f4(char *, char *);
extern void FUN_0001c73c(char *);
extern int FUN_0001c848(void);
extern int FUN_0001c8a0(void);
extern void FUN_001c04c4(char *);
extern void FUN_001c14ac(char *);
extern void FUN_001c1598(char *, int);
extern void FUN_001c15fc(char *, int);
extern void FUN_001c16b4(char *, int);
extern void FUN_001c170c(char *, int);
extern void FUN_001c1f44(char *, int);
extern void FUN_001c20b8(char *);

typedef struct Obj {
  char pad0[0xa4];
  int fa4;
  int fa8;
  char pad1[0x25c - 0xac];
  int f25c;
} Obj;

void FUN_0023de04(Obj *o)
{
  void *p;
  int a;
  int b;
  int n;
  int t;
  char buf[256];

  FUN_001c20b8(DAT_003eaad8);
  FUN_001c04c4(DAT_003eaad8);
  if (o->fa8 == -1) {
    p = FUN_00010184(0x40, 0xccccc);
    FUN_0001bb2c(DAT_003b3e6c, p, 0xccccc);
    FUN_0001c5f4(DAT_003b7ebc, "menu/optionbgm/option_bgm_stream.xb");
    FUN_001c16b4(DAT_003eaad8, 0);
    FUN_001c16b4(DAT_003eaad8, 2);
    FUN_001c16b4(DAT_003eaad8, 6);
    FUN_001c14ac(DAT_003eaad8);
    FUN_0001c73c(DAT_003b7ebc);
    a = FUN_0001c848();
    b = FUN_0001c8a0();
    FUN_0001bb2c(DAT_003b3e6c, (void *)a, b);
    FUN_000104e0(p);
  }
  t = DAT_0039bca8[o->f25c];
  o->fa4 = t;
  if (o->fa8 != t) {
    if (o->fa8 >= 0x28 && o->fa8 < 0x32) {
      FUN_001c15fc(DAT_003eaad8, o->fa8 - 0x27);
    }
    if (o->fa4 >= 0x28 && o->fa4 < 0x32) {
      FUN_001c170c(DAT_003eaad8, 0x22);
      FUN_001c170c(DAT_003eaad8, 0x23);
      FUN_001c170c(DAT_003eaad8, 0x25);
      n = o->fa4 - 0x27;
      p = FUN_00010184(0x40, 0x173333);
      FUN_0001bb2c(DAT_003b3e6c, p, 0x173333);
      FUN_000143b0(buf, "menu/optionbgm/option_bgm_lobby%02d.xb", n);
      FUN_0001c5f4(DAT_003b7ebc, buf);
      FUN_001c1598(DAT_003eaad8, n);
      FUN_0001c73c(DAT_003b7ebc);
      a = FUN_0001c848();
      b = FUN_0001c8a0();
      FUN_0001bb2c(DAT_003b3e6c, (void *)a, b);
      FUN_000104e0(p);
    } else {
      switch (o->fa4) {
      case 0x22:
      case 0x23:
      case 0x25:
        p = FUN_00010184(0x40, 0xccccc);
        FUN_0001bb2c(DAT_003b3e6c, p, 0xccccc);
        FUN_0001c5f4(DAT_003b7ebc, "menu/optionbgm/option_bgm_stream.xb");
        FUN_001c16b4(DAT_003eaad8, o->fa4);
        FUN_0001c73c(DAT_003b7ebc);
        a = FUN_0001c848();
        b = FUN_0001c8a0();
        FUN_0001bb2c(DAT_003b3e6c, (void *)a, b);
        FUN_000104e0(p);
        break;
      }
    }
  }
  FUN_001c1f44(DAT_003eaad8, o->fa4);
  o->fa8 = o->fa4;
}
