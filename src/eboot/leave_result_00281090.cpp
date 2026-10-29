/* HSTMATCH module=EBOOT.BIN start=0x00281090 end=0x00281128 symbol=FUN_00281090 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct GObj { virtual ~GObj(); };
extern "C" void FUN_000ba78c(GObj *p);
extern "C" void FUN_000ba504(GObj *p);
extern "C" void FUN_00103628(void *a, int b);
struct Tag {};
extern "C" void FUN_00116414(void *a, int b, Tag c);

/* Screen object; only the byte at 0x2c00 is touched here. */
struct ScreenObj {
  char pad00[0x2c00];
  char unk2c00;          /* 0x2c00 */
};

/* Global holder (DAT_003415ac): a sub-object at 0x8c whose first-word companion sits at 0x90. */
struct Holder {
  char pad00[0x8c];
  char sub8c[4];         /* 0x8c, passed by address */
  int unk90;             /* 0x90 */
};

extern GObj *DAT_00338ac4;
extern Holder *DAT_003415ac;

/* Clears the flag, destroys the global object if present and releases the holder's sub-object. */
extern "C" void FUN_00281090(ScreenObj *self)
{
  self->unk2c00 = 0;
  if (DAT_00338ac4 != 0) {
    FUN_000ba78c(DAT_00338ac4);
    FUN_000ba504(DAT_00338ac4);
    if (DAT_00338ac4 != 0) {
      delete DAT_00338ac4;
      DAT_00338ac4 = 0;
    }
  }
  FUN_00103628(DAT_003415ac, 1);
  FUN_00116414(DAT_003415ac->sub8c, DAT_003415ac->unk90, Tag());
}
