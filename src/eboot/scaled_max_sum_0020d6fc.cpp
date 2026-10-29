/* HSTMATCH module=EBOOT.BIN start=0x0020d6fc end=0x0020d82c symbol=FUN_0020d6fc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Self { char pad[0x8a5]; unsigned char flag; };
struct Cfg { char pad[0x45]; unsigned char unk45; };
struct A { char pad[0x1c]; float unk1c; char pad2[0x38]; float unk58; float unk5c; };
struct B { char pad[0x58]; float unk58; float unk5c; char pad2[0x1a4]; float unk204; };

extern float DAT_002ef9bc;
extern float DAT_002ef9c0;
extern float DAT_002ef9c4;
extern Cfg *DAT_00338b44;
extern "C" B *FUN_00215a20(Self *);
extern "C" A *FUN_00215a58(void);
extern "C" A *FUN_00215ab8(void);

#define HUNDREDTH 0.01f

static inline float Max(const float &a, const float &b)
{
  return a > b ? a : b;
}

/* Largest of a global floor and a sum of two stat fields (which pair depends on the flag and the config byte), scaled by 0.01. */
extern "C" float FUN_0020d6fc(Self *self)
{
  if (self->flag != 0) {
    return Max(DAT_002ef9bc, FUN_00215a58()->unk5c + FUN_00215a20(self)->unk5c) * HUNDREDTH;
  }
  if (DAT_00338b44->unk45 != 0) {
    return Max(DAT_002ef9c0, FUN_00215a58()->unk58 + FUN_00215a20(self)->unk58) * HUNDREDTH;
  }
  return Max(DAT_002ef9c4, FUN_00215ab8()->unk1c + FUN_00215a20(self)->unk204) * HUNDREDTH;
}
