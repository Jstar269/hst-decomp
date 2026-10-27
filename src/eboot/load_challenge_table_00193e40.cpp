/* HSTMATCH module=EBOOT.BIN start=0x00193e40 end=0x00193f78 symbol=FUN_00193e40 lang=c++ data=0x002e1458 */
/* Hand-written reconstruction from the disassembly (adapted from the sibling loader src/eboot/load_challenge_table_001938d8.cpp: record size 0x70, constructor 0x193f78, path pointer 0x2e1488, table pointer 0x341738); exact match verified; names and types await human review. Data: its string-pointer tables (1 tables, 1 strings, 0x002e1458-0x002e148c) are defined in place and placed with data= (tools/hstdatapool.py tables); before, the source named them through address externs. */
extern "C" {
void *FUN_0004cad0(const char *path, int *size, int align, int flag);
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_00000a90(unsigned size);
void *FUN_000008d8(void *block, void *ctor, void *dtor, unsigned size, unsigned n);
void FUN_00193f78(void);
void FUN_000104e0(void *p);
const char *DAT_002e1488 = "data/menu/challenge/Challenge_StampTable.bin";
}
struct Record_00193e40 { char raw[0x70]; };
struct Table_00193e40 {
    int count;
    Record_00193e40 *records;
    Table_00193e40() : count(0), records(0) {}
};
extern "C" Table_00193e40 *DAT_00341738;
extern "C" int FUN_00193e40(void)
{
    int ok = 0;
    if (DAT_00341738 == 0) {
        int size;
        void *buf = FUN_0004cad0(DAT_002e1488, &size, 16, 1);
        if (buf != 0) {
            int count;
            FUN_00011090(&count, buf, 4);
            if (size == count * (int)sizeof(Record_00193e40) + 4) {
                DAT_00341738 = new Table_00193e40;
                if (DAT_00341738 != 0) {
                    DAT_00341738->records = (Record_00193e40 *)FUN_000008d8(
                        FUN_00000a90(count * sizeof(Record_00193e40) + 16), (void *)FUN_00193f78, 0,
                        sizeof(Record_00193e40), count);
                    DAT_00341738->count = count;
                    FUN_00011090(DAT_00341738->records, (char *)buf + 4, count * sizeof(Record_00193e40));
                    ok = 1;
                }
            }
            if (buf != 0)
                FUN_000104e0(buf);
        }
    }
    return ok;
}
