/* HSTMATCH module=hstp_trans_main.prx start=0x00177bcc end=0x00177c3c symbol=FUN_00177bcc lang=c++ */
/* Clone of src/eboot/clamp_bound_0016ba08.cpp (hstclone.py tag c160307): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned short ushort;

extern int DAT_00387a3c;
extern int DAT_00387a40;
extern "C" int FUN_00177d4c();

static inline int Clamp(const int &v, const int &lo, const int &hi)
{
  return v < lo ? lo : (hi < v ? hi : v);
}

extern "C" void FUN_00177bcc(ushort param_1)
{
  int iVar1 = FUN_00177d4c();
  *(ushort *)(iVar1 + 0x103a) = (ushort)Clamp(param_1, DAT_00387a3c, DAT_00387a40);
}
