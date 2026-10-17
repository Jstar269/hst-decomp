/* HSTMATCH module=hstp_trans_main.prx start=0x001a00e8 end=0x001a0238 symbol=FUN_001a00e8 lang=c++ */
/* Clone of src/eboot/load_challenge_table_001938d8.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* One-time loader of the challenge table (path pointer at 0x388b30, "data/menu/challenge/Challenge Ma..."):
   read the file through 0x4cad0, check its size against a leading 108-byte-record count, create the table
   object (count + record array; the array comes from operator new[] 0xa90 and the array constructor helper
   0x8d8 with record constructor 0x8e93c), copy the records, free the file buffer (0x104e0). Names provisional. */
extern "C" {
void *FUN_0004cd8c(const char *path, int *size, int align, int flag);
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_00000a90(unsigned size);
void *FUN_000008d8(void *block, void *ctor, void *dtor, unsigned size, unsigned n);
void FUN_0008e93c(void);
void FUN_000104e0(void *p);
extern const char *DAT_00388b30;
}
struct Record_001a00e8 { char raw[0x6c]; };
struct Table_001a00e8 {
    int count;
    Record_001a00e8 *records;
    Table_001a00e8() : count(0), records(0) {}
};
extern "C" Table_001a00e8 *DAT_003eaa74;
extern "C" int FUN_001a00e8(void)
{
    int ok = 0;
    if (DAT_003eaa74 == 0) {
        int size;
        void *buf = FUN_0004cd8c(DAT_00388b30, &size, 16, 1);
        if (buf != 0) {
            int count;
            FUN_00011090(&count, buf, 4);
            if (size == count * (int)sizeof(Record_001a00e8) + 4) {
                DAT_003eaa74 = new Table_001a00e8;
                if (DAT_003eaa74 != 0) {
                    DAT_003eaa74->records = (Record_001a00e8 *)FUN_000008d8(
                        FUN_00000a90(count * sizeof(Record_001a00e8) + 16), (void *)FUN_0008e93c, 0,
                        sizeof(Record_001a00e8), count);
                    DAT_003eaa74->count = count;
                    FUN_00011090(DAT_003eaa74->records, (char *)buf + 4, count * sizeof(Record_001a00e8));
                    ok = 1;
                }
            }
            if (buf != 0)
                FUN_000104e0(buf);
        }
    }
    return ok;
}
