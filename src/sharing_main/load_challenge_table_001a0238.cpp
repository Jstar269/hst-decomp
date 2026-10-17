/* HSTMATCH module=hstp_trans_main.prx start=0x001a0238 end=0x001a039c symbol=FUN_001a0238 lang=c++ */
/* Clone of src/eboot/load_challenge_table_00193a28.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* One-time loader of the second challenge table (path pointer at 0x388b94, "data/menu/challenge/Challenge Vs..."):
   same shape as 0x1938d8 with 156-byte records (constructor 0x8ede8), plus clearing the byte flag at 0x388c01
   after a successful load. Names provisional. */
extern "C" {
void *FUN_0004cd8c(const char *path, int *size, int align, int flag);
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_00000a90(unsigned size);
void *FUN_000008d8(void *block, void *ctor, void *dtor, unsigned size, unsigned n);
void FUN_0008ede8(void);
void FUN_000104e0(void *p);
extern const char *DAT_00388b94;
extern unsigned char DAT_00388c01;
}
struct Record_001a0238 { char raw[0x9c]; };
struct Table_001a0238 {
    int count;
    Record_001a0238 *records;
    Table_001a0238() : count(0), records(0) {}
};
extern "C" Table_001a0238 *DAT_003eaa7c;
extern "C" int FUN_001a0238(void)
{
    int ok = 0;
    if (DAT_003eaa7c == 0) {
        int size;
        void *buf = FUN_0004cd8c(DAT_00388b94, &size, 16, 1);
        if (buf != 0) {
            int count;
            FUN_00011090(&count, buf, 4);
            if (size == count * (int)sizeof(Record_001a0238) + 4) {
                DAT_003eaa7c = new Table_001a0238;
                if (DAT_003eaa7c != 0) {
                    DAT_003eaa7c->records = (Record_001a0238 *)FUN_000008d8(
                        FUN_00000a90(count * sizeof(Record_001a0238) + 16), (void *)FUN_0008ede8, 0,
                        sizeof(Record_001a0238), count);
                    DAT_003eaa7c->count = count;
                    FUN_00011090(DAT_003eaa7c->records, (char *)buf + 4, count * sizeof(Record_001a0238));
                    ok = 1;
                    if (DAT_00388c01)
                        DAT_00388c01 = 0;
                }
            }
            if (buf != 0)
                FUN_000104e0(buf);
        }
    }
    return ok;
}
