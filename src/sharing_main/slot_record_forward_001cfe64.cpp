/* HSTMATCH module=hstp_trans_main.prx start=0x001cfe64 end=0x001cff20 symbol=FUN_001cfe64 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Forwards its 25 arguments to FUN_001c949c with the slot index replaced by the address of the record at +0x18 of
   the 0x120-byte slot DAT_003eaaf0[idx]. Only the 17 stack arguments are re-stored (lbu for the bool/byte ones,
   lw for the words); the parameter types follow the callee's reads and the callers' stores (lhu shorts, `x != 0`
   bools). The callee copies 156 bytes from the last argument, strcpy's the name to +0xcc and stores the rest. */
struct Slot {
  char pad[0x18];
  char rec[0x108];
};

extern "C" {
extern Slot DAT_003eaaf0[];
void FUN_001c949c(void *rec, const char *name, int id, unsigned short a, unsigned short b, unsigned short c,
                  unsigned short d, short e, bool f0, bool f1, bool f2, int i3, int i4, int i5, int i6, void *p7,
                  int i8, int i9, unsigned char c10, int i11, unsigned char c12, int i13, int i14,
                  unsigned char c15, void *src);

void FUN_001cfe64(int idx, const char *name, int id, unsigned short a, unsigned short b, unsigned short c,
                  unsigned short d, short e, bool f0, bool f1, bool f2, int i3, int i4, int i5, int i6, void *p7,
                  int i8, int i9, unsigned char c10, int i11, unsigned char c12, int i13, int i14,
                  unsigned char c15, void *src)
{
  FUN_001c949c(DAT_003eaaf0[idx].rec, name, id, a, b, c, d, e, f0, f1, f2, i3, i4, i5, i6, p7, i8, i9, c10, i11,
               c12, i13, i14, c15, src);
}
}
