/* HSTMATCH module=hstp_trans_main.prx start=0x001a04ec end=0x001a0650 symbol=FUN_001a04ec lang=c++ data=0x00388bd0 */
/* Clone of src/eboot/load_challenge_table_00193a28.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. Data: its string-pointer tables (1 tables, 1 strings, 0x00388bd0-0x00388c00) are defined in place and placed with data= (tools/hstdatapool.py tables); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* One-time loader of the second challenge table (path pointer at 0x388bfc, "data/menu/challenge/Challenge Vs..."):
   same shape as 0x1938d8 with 156-byte records (constructor 0x8ede8), plus clearing the byte flag at 0x388c02
   after a successful load. Names provisional. */
extern "C" {
void *FUN_0004cd8c(const char *path, int *size, int align, int flag);
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_00000a90(unsigned size);
void *FUN_000008d8(void *block, void *ctor, void *dtor, unsigned size, unsigned n);
void FUN_0008ede8(void);
void FUN_000104e0(void *p);
const char *DAT_00388bfc = "data/menu/challenge/Challenge_PcList.bin";
extern unsigned char DAT_00388c02;
}
struct Record_001a04ec { char raw[0x9c]; };
struct Table_001a04ec {
    int count;
    Record_001a04ec *records;
    Table_001a04ec() : count(0), records(0) {}
};
extern "C" Table_001a04ec *DAT_003eaa84;
extern "C" int FUN_001a04ec(void)
{
    int ok = 0;
    if (DAT_003eaa84 == 0) {
        int size;
        void *buf = FUN_0004cd8c(DAT_00388bfc, &size, 16, 1);
        if (buf != 0) {
            int count;
            FUN_00011090(&count, buf, 4);
            if (size == count * (int)sizeof(Record_001a04ec) + 4) {
                DAT_003eaa84 = new Table_001a04ec;
                if (DAT_003eaa84 != 0) {
                    DAT_003eaa84->records = (Record_001a04ec *)FUN_000008d8(
                        FUN_00000a90(count * sizeof(Record_001a04ec) + 16), (void *)FUN_0008ede8, 0,
                        sizeof(Record_001a04ec), count);
                    DAT_003eaa84->count = count;
                    FUN_00011090(DAT_003eaa84->records, (char *)buf + 4, count * sizeof(Record_001a04ec));
                    ok = 1;
                    if (DAT_00388c02)
                        DAT_00388c02 = 0;
                }
            }
            if (buf != 0)
                FUN_000104e0(buf);
        }
    }
    return ok;
}
