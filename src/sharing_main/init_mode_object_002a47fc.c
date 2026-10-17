/* HSTMATCH module=hstp_trans_main.prx start=0x002a47fc end=0x002a48c4 symbol=FUN_002a47fc lang=c99 */
/* Clone of src/eboot/init_mode_object_002931f0.c (hstclone.py tag c034907): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: parameters retyped (float first, object, mode), typed struct fields, the else-if ladder on mode is a switch with cases 0 and 1 sharing one body (cases 2-4 another), the global pointer read once into a local; exact match verified; names and types await human review. */
typedef struct Glob { char pad[0xc]; int f0c; char pad2[0x42]; unsigned char f52; } Glob;
extern Glob *DAT_003daec8;

typedef struct Obj {
  char pad0[4];
  float f04;
  float f08;
  char pad0c[8];
  int f14;
  int arr[7];
  char pad34[4];
  float f38;
  char pad3c[4];
  unsigned char f40;
  char pad41[3];
  int f44;
  int f48;
  unsigned char f4c;
  unsigned char f4d;
  char pad4e[2];
  float f50;
  unsigned char f54;
} Obj;

void FUN_002a47fc(float p, Obj *o, int mode)
{
  Glob *g;
  o->f40 = 0;
  o->f04 = 30.0f;
  o->f08 = 30.0f;
  o->f38 = 0.0f;
  o->f38 = 31.0f;
  o->f4c = 0;
  o->f4d = 1;
  o->f50 = p;
  o->f54 = 0;
  if (mode == 3) {
    o->f54 = 1;
  }
  if (mode >= 0 && mode < 7) {
    o->f14 = o->arr[mode];
    o->f48 = mode;
    switch (mode) {
    case 0:
    case 1:
      o->f44 = 0;
      break;
    case 2:
    case 3:
    case 4:
      o->f44 = 1;
      break;
    }
  }
  g = DAT_003daec8;
  g->f0c = 0;
  g->f52 = 0;
}
