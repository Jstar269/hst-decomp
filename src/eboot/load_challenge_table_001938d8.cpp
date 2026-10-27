/* HSTMATCH module=EBOOT.BIN start=0x001938d8 end=0x00193a28 symbol=FUN_001938d8 lang=c++ data=0x002e1424 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string-pointer tables (1 tables, 1 strings, 0x002e1424-0x002e1458) are defined in place and placed with data= (tools/hstdatapool.py tables); before, the source named them through address externs. */
/* One-time loader of the challenge table (path pointer at 0x2e1454, "data/menu/challenge/Challenge Ma..."):
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
const char *DAT_002e1454 = "data/menu/challenge/Challenge_MatchTable.bin";
}
struct Record_001938d8 { char raw[0x6c]; };
struct Table_001938d8 {
    int count;
    Record_001938d8 *records;
    Table_001938d8() : count(0), records(0) {}
};
extern "C" Table_001938d8 *DAT_00341734;
extern "C" int FUN_001938d8(void)
{
    int ok = 0;
    if (DAT_00341734 == 0) {
        int size;
        void *buf = FUN_0004cad0(DAT_002e1454, &size, 16, 1);
        if (buf != 0) {
            int count;
            FUN_00011090(&count, buf, 4);
            if (size == count * (int)sizeof(Record_001938d8) + 4) {
                DAT_00341734 = new Table_001938d8;
                if (DAT_00341734 != 0) {
                    DAT_00341734->records = (Record_001938d8 *)FUN_000008d8(
                        FUN_00000a90(count * sizeof(Record_001938d8) + 16), (void *)FUN_0008d1ec, 0,
                        sizeof(Record_001938d8), count);
                    DAT_00341734->count = count;
                    FUN_00011090(DAT_00341734->records, (char *)buf + 4, count * sizeof(Record_001938d8));
                    ok = 1;
                }
            }
            if (buf != 0)
                FUN_000104e0(buf);
        }
    }
    return ok;
}
