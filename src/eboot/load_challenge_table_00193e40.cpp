/* HSTMATCH module=EBOOT.BIN start=0x00193e40 end=0x00193f78 symbol=FUN_00193e40 lang=c++ data=0x002e1458 */
/* Hand-written reconstruction from the disassembly (adapted from the sibling loader src/eboot/load_challenge_table_001938d8.cpp: record size 0x70, constructor 0x193f78, path pointer 0x2e1488, table pointer 0x341738); exact match verified; names and types await human review. Data: its string-pointer tables (1 tables, 1 strings, 0x002e1458-0x002e148c) are defined in place and placed with data= (tools/hstdatapool.py tables); before, the source named them through address externs. */
/* Table file layout: a 4-byte record count, then the records; the record array is allocated with a 16-byte header. */
#define TABLE_FILE_COUNT_SIZE 4
#define TABLE_FILE_ALIGN 16
#define ARRAY_HEADER_SIZE 16

extern "C" {
void *FUN_0004cad0(const char *path, int *size, int align, int flag);
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_00000a90(unsigned size);
void *FUN_000008d8(void *block, void *ctor, void *dtor, unsigned size, unsigned n);
void FUN_00193f78(void);
void FUN_000104e0(void *p);
const char *DAT_002e1488 = "data/menu/challenge/Challenge_StampTable.bin";
}
/* Opaque table record; only its size is known. */
struct StampRecord { char raw[0x70]; };
/* Loaded table: record count and the record array. */
struct StampTable {
    int count;
    StampRecord *records;
    StampTable() : count(0), records(0) {}
};
extern "C" StampTable *DAT_00341738;
/* One-time loader of the stamp table: returns 1 when it was loaded, 0 when it already existed or the file is bad. */
extern "C" int FUN_00193e40(void)
{
    int ok = 0;
    if (DAT_00341738 == 0) {
        int file_size;
        void *file = FUN_0004cad0(DAT_002e1488, &file_size, TABLE_FILE_ALIGN, 1);
        if (file != 0) {
            int count;
            FUN_00011090(&count, file, TABLE_FILE_COUNT_SIZE);
            if (file_size == count * (int)sizeof(StampRecord) + TABLE_FILE_COUNT_SIZE) {
                DAT_00341738 = new StampTable;
                if (DAT_00341738 != 0) {
                    DAT_00341738->records = (StampRecord *)FUN_000008d8(
                        FUN_00000a90(count * sizeof(StampRecord) + ARRAY_HEADER_SIZE), (void *)FUN_00193f78, 0,
                        sizeof(StampRecord), count);
                    DAT_00341738->count = count;
                    FUN_00011090(DAT_00341738->records, (char *)file + TABLE_FILE_COUNT_SIZE, count * sizeof(StampRecord));
                    ok = 1;
                }
            }
            if (file != 0)
                FUN_000104e0(file);
        }
    }
    return ok;
}
