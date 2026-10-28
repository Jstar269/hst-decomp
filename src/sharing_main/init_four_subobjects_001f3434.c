/* HSTMATCH module=hstp_trans_main.prx start=0x001f3434 end=0x001f3544 symbol=FUN_001f3434 lang=c99 */
/* Clone of src/eboot/init_four_subobjects_001e521c.c (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

typedef struct Sub_001f3434 {
  char pad[0x20];
  int color;
  char pad2[0x8c - 0x24];
} Sub_001f3434;

typedef struct Obj_001f3434 {
  char pad0[0x270];
  int f270;
  char pad1[0x438 - 0x274];
  unsigned char f438;
  char pad2[0x4c8 - 0x439];
  Sub_001f3434 sub[4];
} Obj_001f3434;

extern char DAT_00394098[];
extern float FUN_00066bb0(int, char *, int);
extern void FUN_00105470(int, int);
extern int FUN_001fc5ec();
extern void FUN_002268b4(void *, int, float, float);
extern void FUN_002268dc(void *, int, int, int);

void FUN_001f3434(Obj_001f3434 *o)
{
  int c;
  float f;

  o->f438 = 1;
  c = o->sub[0].color;
  f = FUN_00066bb0(FUN_001fc5ec(), DAT_00394098, 1);
  FUN_002268dc(&o->sub[0], c, -1, (int)f);
  c = o->sub[2].color;
  f = FUN_00066bb0(FUN_001fc5ec(), DAT_00394098, 1);
  FUN_002268dc(&o->sub[2], c, -1, (int)f);
  c = o->sub[1].color;
  f = FUN_00066bb0(FUN_001fc5ec(), DAT_00394098, 1);
  FUN_002268dc(&o->sub[1], c, -1, (int)f);
  FUN_00105470(o->f270, 0);
  FUN_002268b4(&o->sub[3], 0x19, 1.0f, 2.0f);
  FUN_002268dc(&o->sub[3], -1, o->sub[3].color & 0xffffff, 0x19);
}
