/* HSTMATCH module=hstp_trans_main.prx start=0x001a0650 end=0x001a0788 symbol=FUN_001a0650 lang=c++ data=0x00388b34 */
/* Clone of src/eboot/load_challenge_table_00193e40.cpp (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. Data: its string-pointer tables (1 tables, 1 strings, 0x00388b34-0x00388b68) are defined in place and placed with data= (tools/hstdatapool.py tables); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly (adapted from the sibling loader src/eboot/load_challenge_table_001938d8.cpp: record size 0x70, constructor 0x1a0788, path pointer 0x388b64, table pointer 0x3eaa78); exact match verified; names and types await human review. */
extern "C" {
void *FUN_0004cd8c(const char *path, int *size, int align, int flag);
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_00000a90(unsigned size);
void *FUN_000008d8(void *block, void *ctor, void *dtor, unsigned size, unsigned n);
void FUN_001a0788(void);
void FUN_000104e0(void *p);
const char *DAT_00388b64 = "data/menu/challenge/Challenge_StampTable.bin";
}
struct Record_001a0650 { char raw[0x70]; };
struct Table_001a0650 {
    int count;
    Record_001a0650 *records;
    Table_001a0650() : count(0), records(0) {}
};
extern "C" Table_001a0650 *DAT_003eaa78;
extern "C" int FUN_001a0650(void)
{
    int ok = 0;
    if (DAT_003eaa78 == 0) {
        int size;
        void *buf = FUN_0004cd8c(DAT_00388b64, &size, 16, 1);
        if (buf != 0) {
            int count;
            FUN_00011090(&count, buf, 4);
            if (size == count * (int)sizeof(Record_001a0650) + 4) {
                DAT_003eaa78 = new Table_001a0650;
                if (DAT_003eaa78 != 0) {
                    DAT_003eaa78->records = (Record_001a0650 *)FUN_000008d8(
                        FUN_00000a90(count * sizeof(Record_001a0650) + 16), (void *)FUN_001a0788, 0,
                        sizeof(Record_001a0650), count);
                    DAT_003eaa78->count = count;
                    FUN_00011090(DAT_003eaa78->records, (char *)buf + 4, count * sizeof(Record_001a0650));
                    ok = 1;
                }
            }
            if (buf != 0)
                FUN_000104e0(buf);
        }
    }
    return ok;
}
