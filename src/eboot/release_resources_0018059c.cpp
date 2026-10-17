/* HSTMATCH module=EBOOT.BIN start=0x0018059c end=0x001808c4 symbol=FUN_0018059c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: one polymorphic VC class with virtual deleting dtor for the object pointers, an element class with a constructor for the eight delete[] members (16-byte cookie, FUN_000009e4(p - 16)) and a POD pointer for the global array (plain FUN_000009e4(p)), the if/else flipped to if (f1f48 != 0) with its explicit inner null test (three tests in retail), each member released as if (p != 0) { delete p; p = 0; }; exact match verified; names and types await human review. */
struct VC { virtual ~VC(); };
struct E { int x; E() {} };
struct Obj {
  char pad0[0x1f48];
  VC *f1f48;
  char pad1[0x2864 - 0x1f4c];
  VC *f2864;
  char pad2[0x2878 - 0x2868];
  VC *f2878;
  E *f287c;
  VC *f2880;
  E *f2884;
  VC *f2888;
  E *f288c;
  E *f2890;
  VC *f2894;
  E *f2898;
  E *f289c;
  VC *f28a0;
  E *f28a4;
  VC *f28a8;
  E *f28ac;
};
extern int *DAT_00341520;
extern char DAT_002e092c[];
extern char DAT_002e093c[];
extern char DAT_002e094c[];
extern "C" void FUN_000143b0(char *, const char *, int);
extern "C" void FUN_000ffa60(char *);

extern "C" void FUN_0018059c(Obj *param_1)
{
  char buf[128];
  int i;

  if (param_1->f1f48 != 0) {
    if (param_1->f1f48 != 0) { delete param_1->f1f48; param_1->f1f48 = 0; }
    if (param_1->f2864 != 0) { delete param_1->f2864; param_1->f2864 = 0; }
  } else {
    if (param_1->f2878 != 0) { delete param_1->f2878; param_1->f2878 = 0; }
    if (param_1->f2880 != 0) { delete param_1->f2880; param_1->f2880 = 0; }
    if (param_1->f2888 != 0) { delete param_1->f2888; param_1->f2888 = 0; }
    if (param_1->f2894 != 0) { delete param_1->f2894; param_1->f2894 = 0; }
    if (param_1->f28a0 != 0) { delete param_1->f28a0; param_1->f28a0 = 0; }
    if (param_1->f28a8 != 0) { delete param_1->f28a8; param_1->f28a8 = 0; }
  }
  if (DAT_00341520 != 0) { delete[] DAT_00341520; DAT_00341520 = 0; }
  if (param_1->f287c != 0) { delete[] param_1->f287c; param_1->f287c = 0; }
  if (param_1->f2884 != 0) { delete[] param_1->f2884; param_1->f2884 = 0; }
  if (param_1->f288c != 0) { delete[] param_1->f288c; param_1->f288c = 0; }
  if (param_1->f2890 != 0) { delete[] param_1->f2890; param_1->f2890 = 0; }
  if (param_1->f2898 != 0) { delete[] param_1->f2898; param_1->f2898 = 0; }
  if (param_1->f289c != 0) { delete[] param_1->f289c; param_1->f289c = 0; }
  if (param_1->f28a4 != 0) { delete[] param_1->f28a4; param_1->f28a4 = 0; }
  if (param_1->f28ac != 0) { delete[] param_1->f28ac; param_1->f28ac = 0; }
  i = 0;
  do {
    FUN_000143b0(buf, DAT_002e092c, i);
    FUN_000ffa60(buf);
    i = i + 1;
  } while (i < 7);
  i = 0;
  do {
    FUN_000143b0(buf, DAT_002e093c, i);
    FUN_000ffa60(buf);
    i = i + 1;
  } while (i < 8);
  i = 0;
  do {
    if (i != 5) {
      FUN_000143b0(buf, DAT_002e094c, i);
      FUN_000ffa60(buf);
    }
    i = i + 1;
  } while (i < 7);
}
