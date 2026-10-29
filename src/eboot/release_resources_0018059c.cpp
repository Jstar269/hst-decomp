/* HSTMATCH module=EBOOT.BIN start=0x0018059c end=0x001808c4 symbol=FUN_0018059c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: one polymorphic VirtualDtorObj class with virtual deleting dtor for the object pointers, an element class with a constructor for the eight delete[] members (16-byte cookie, FUN_000009e4(p - 16)) and a POD pointer for the global array (plain FUN_000009e4(p)), the if/else flipped to if (unk1f48 != 0) with its explicit inner null test (three tests in retail), each member released as if (p != 0) { delete p; p = 0; }; readability pass; exact match verified; names and types await human review. */
struct VirtualDtorObj { virtual ~VirtualDtorObj(); };
struct ArrayElem { int x; ArrayElem() {} };
/* Screen object: only the owned members released here are named. */
struct Obj {
  char pad0[0x1f48];
  VirtualDtorObj *unk1f48;
  char pad1[0x2864 - 0x1f4c];
  VirtualDtorObj *unk2864;
  char pad2[0x2878 - 0x2868];
  VirtualDtorObj *unk2878;
  ArrayElem *unk287c;
  VirtualDtorObj *unk2880;
  ArrayElem *unk2884;
  VirtualDtorObj *unk2888;
  ArrayElem *unk288c;
  ArrayElem *unk2890;
  VirtualDtorObj *unk2894;
  ArrayElem *unk2898;
  ArrayElem *unk289c;
  VirtualDtorObj *unk28a0;
  ArrayElem *unk28a4;
  VirtualDtorObj *unk28a8;
  ArrayElem *unk28ac;
};
extern int *DAT_00341520; /* global array released with the members */
extern char DAT_002e092c[];
extern char DAT_002e093c[];
extern char DAT_002e094c[];
extern "C" void FUN_000143b0(char *, const char *, int);
extern "C" void FUN_000ffa60(char *);

/* Release every owned member (single objects with a virtual destructor, element arrays), then the numbered resources by name. */
extern "C" void FUN_0018059c(Obj *self)
{
  char buf[128];
  int i; /* resource index */

  if (self->unk1f48 != 0) {
    if (self->unk1f48 != 0) { delete self->unk1f48; self->unk1f48 = 0; }
    if (self->unk2864 != 0) { delete self->unk2864; self->unk2864 = 0; }
  } else {
    if (self->unk2878 != 0) { delete self->unk2878; self->unk2878 = 0; }
    if (self->unk2880 != 0) { delete self->unk2880; self->unk2880 = 0; }
    if (self->unk2888 != 0) { delete self->unk2888; self->unk2888 = 0; }
    if (self->unk2894 != 0) { delete self->unk2894; self->unk2894 = 0; }
    if (self->unk28a0 != 0) { delete self->unk28a0; self->unk28a0 = 0; }
    if (self->unk28a8 != 0) { delete self->unk28a8; self->unk28a8 = 0; }
  }
  if (DAT_00341520 != 0) { delete[] DAT_00341520; DAT_00341520 = 0; }
  if (self->unk287c != 0) { delete[] self->unk287c; self->unk287c = 0; }
  if (self->unk2884 != 0) { delete[] self->unk2884; self->unk2884 = 0; }
  if (self->unk288c != 0) { delete[] self->unk288c; self->unk288c = 0; }
  if (self->unk2890 != 0) { delete[] self->unk2890; self->unk2890 = 0; }
  if (self->unk2898 != 0) { delete[] self->unk2898; self->unk2898 = 0; }
  if (self->unk289c != 0) { delete[] self->unk289c; self->unk289c = 0; }
  if (self->unk28a4 != 0) { delete[] self->unk28a4; self->unk28a4 = 0; }
  if (self->unk28ac != 0) { delete[] self->unk28ac; self->unk28ac = 0; }
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
