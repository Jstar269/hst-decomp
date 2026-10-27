/* HSTMATCH module=EBOOT.BIN start=0x00193b8c end=0x00193cdc symbol=FUN_00193b8c lang=c++ data=0x002e14bc */
/* Clone of src/eboot/load_challenge_table_001938d8.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. Data: its string-pointer tables (1 tables, 1 strings, 0x002e14bc-0x002e14f4) are defined in place and placed with data= (tools/hstdatapool.py tables); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* One-time loader of the challenge table (path pointer at 0x2e14f0, "data/menu/challenge/Challenge Ma..."):
   read the file through 0x4cad0, check its size against a leading 108-byte-record count, create the table
   object (count + record array; the array comes from operator new[] 0xa90 and the array constructor helper
   0x8d8 with record constructor 0x8d1ec), copy the records, free the file buffer (0x104e0). Names provisional. */
extern "C" {
void *FUN_0004cad0(const char *path, int *size, int align, int flag);
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_00000a90(unsigned size);
void *FUN_000008d8(void *block, void *ctor, void *dtor, unsigned size, unsigned n);
void FUN_0008d1ec(void);
void FUN_000104e0(void *p);
const char *DAT_002e14f0 = "data/menu/challenge/Challenge_ExhibitionTable.bin";
}
struct Record_00193b8c { char raw[0x6c]; };
struct Table_00193b8c {
    int count;
    Record_00193b8c *records;
    Table_00193b8c() : count(0), records(0) {}
};
extern "C" Table_00193b8c *DAT_00341740;
extern "C" int FUN_00193b8c(void)
{
    int ok = 0;
    if (DAT_00341740 == 0) {
        int size;
        void *buf = FUN_0004cad0(DAT_002e14f0, &size, 16, 1);
        if (buf != 0) {
            int count;
            FUN_00011090(&count, buf, 4);
            if (size == count * (int)sizeof(Record_00193b8c) + 4) {
                DAT_00341740 = new Table_00193b8c;
                if (DAT_00341740 != 0) {
                    DAT_00341740->records = (Record_00193b8c *)FUN_000008d8(
                        FUN_00000a90(count * sizeof(Record_00193b8c) + 16), (void *)FUN_0008d1ec, 0,
                        sizeof(Record_00193b8c), count);
                    DAT_00341740->count = count;
                    FUN_00011090(DAT_00341740->records, (char *)buf + 4, count * sizeof(Record_00193b8c));
                    ok = 1;
                }
            }
            if (buf != 0)
                FUN_000104e0(buf);
        }
    }
    return ok;
}
