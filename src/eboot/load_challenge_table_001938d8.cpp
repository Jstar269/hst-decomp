/* HSTMATCH module=EBOOT.BIN start=0x001938d8 end=0x00193a28 symbol=FUN_001938d8 lang=c++ data=0x002e1424 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string-pointer tables (1 tables, 1 strings, 0x002e1424-0x002e1458) are defined in place and placed with data= (tools/hstdatapool.py tables); before, the source named them through address externs. */
/* One-time loader of the challenge table (path pointer at 0x2e1454, "data/menu/challenge/Challenge Ma..."):
   read the file through 0x4cad0, check its size against a leading 108-byte-record count, create the table
   object (count + record array; the array comes from operator new[] 0xa90 and the array constructor helper
   0x8d8 with record constructor 0x8d1ec), copy the records, free the file buffer (0x104e0). Names provisional. */
/* Table file layout: a 4-byte record count, then the records; the record array is allocated with a 16-byte header. */
#define TABLE_FILE_COUNT_SIZE 4
#define TABLE_FILE_ALIGN 16
#define ARRAY_HEADER_SIZE 16

extern "C" {
void *FUN_0004cad0(const char *path, int *size, int align, int flag);
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_00000a90(unsigned size);
void *FUN_000008d8(void *block, void *ctor, void *dtor, unsigned size, unsigned n);
void FUN_0008d1ec(void);
void FUN_000104e0(void *p);
const char *DAT_002e1454 = "data/menu/challenge/Challenge_MatchTable.bin";
}
/* Opaque table record; only its size is known. */
struct MatchRecord { char raw[0x6c]; };
/* Loaded table: record count and the record array. */
struct MatchTable {
    int count;
    MatchRecord *records;
    MatchTable() : count(0), records(0) {}
};
extern "C" MatchTable *DAT_00341734;
/* One-time loader of the match table: returns 1 when it was loaded, 0 when it already existed or the file is bad. */
extern "C" int FUN_001938d8(void)
{
    int ok = 0;
    if (DAT_00341734 == 0) {
        int file_size;
        void *file = FUN_0004cad0(DAT_002e1454, &file_size, TABLE_FILE_ALIGN, 1);
        if (file != 0) {
            int count;
            FUN_00011090(&count, file, TABLE_FILE_COUNT_SIZE);
            if (file_size == count * (int)sizeof(MatchRecord) + TABLE_FILE_COUNT_SIZE) {
                DAT_00341734 = new MatchTable;
                if (DAT_00341734 != 0) {
                    DAT_00341734->records = (MatchRecord *)FUN_000008d8(
                        FUN_00000a90(count * sizeof(MatchRecord) + ARRAY_HEADER_SIZE), (void *)FUN_0008d1ec, 0,
                        sizeof(MatchRecord), count);
                    DAT_00341734->count = count;
                    FUN_00011090(DAT_00341734->records, (char *)file + TABLE_FILE_COUNT_SIZE, count * sizeof(MatchRecord));
                    ok = 1;
                }
            }
            if (file != 0)
                FUN_000104e0(file);
        }
    }
    return ok;
}
