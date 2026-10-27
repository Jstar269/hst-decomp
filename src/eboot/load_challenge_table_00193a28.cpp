/* HSTMATCH module=EBOOT.BIN start=0x00193a28 end=0x00193b8c symbol=FUN_00193a28 lang=c++ data=0x002e148c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string-pointer tables (1 tables, 1 strings, 0x002e148c-0x002e14bc) are defined in place and placed with data= (tools/hstdatapool.py tables); before, the source named them through address externs. */
/* One-time loader of the second challenge table (path pointer at 0x2e14b8, "data/menu/challenge/Challenge Vs..."):
   same shape as 0x1938d8 with 156-byte records (constructor 0x8d650), plus clearing the byte flag at 0x2e1525
   after a successful load. Names provisional. */
extern "C" {
void *FUN_0004cad0(const char *path, int *size, int align, int flag);
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_00000a90(unsigned size);
void *FUN_000008d8(void *block, void *ctor, void *dtor, unsigned size, unsigned n);
void FUN_0008d650(void);
void FUN_000104e0(void *p);
const char *DAT_002e14b8 = "data/menu/challenge/Challenge_VsPcList.bin";
extern unsigned char DAT_002e1525;
}
struct Record_00193a28 { char raw[0x9c]; };
struct Table_00193a28 {
    int count;
    Record_00193a28 *records;
    Table_00193a28() : count(0), records(0) {}
};
extern "C" Table_00193a28 *DAT_0034173c;
extern "C" int FUN_00193a28(void)
{
    int ok = 0;
    if (DAT_0034173c == 0) {
        int size;
        void *buf = FUN_0004cad0(DAT_002e14b8, &size, 16, 1);
        if (buf != 0) {
            int count;
            FUN_00011090(&count, buf, 4);
            if (size == count * (int)sizeof(Record_00193a28) + 4) {
                DAT_0034173c = new Table_00193a28;
                if (DAT_0034173c != 0) {
                    DAT_0034173c->records = (Record_00193a28 *)FUN_000008d8(
                        FUN_00000a90(count * sizeof(Record_00193a28) + 16), (void *)FUN_0008d650, 0,
                        sizeof(Record_00193a28), count);
                    DAT_0034173c->count = count;
                    FUN_00011090(DAT_0034173c->records, (char *)buf + 4, count * sizeof(Record_00193a28));
                    ok = 1;
                    if (DAT_002e1525)
                        DAT_002e1525 = 0;
                }
            }
            if (buf != 0)
                FUN_000104e0(buf);
        }
    }
    return ok;
}
