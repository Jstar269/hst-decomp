/* HSTMATCH module=EBOOT.BIN start=0x00193a28 end=0x00193b8c symbol=FUN_00193a28 lang=c++ data=0x002e148c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string-pointer tables (1 tables, 1 strings, 0x002e148c-0x002e14bc) are defined in place and placed with data= (tools/hstdatapool.py tables); before, the source named them through address externs. */
/* One-time loader of the second challenge table (path pointer at 0x2e14b8, "data/menu/challenge/Challenge Vs..."):
   same shape as 0x1938d8 with 156-byte records (constructor 0x8d650), plus clearing the byte flag at 0x2e1525
   after a successful load. Names provisional. */
/* Table file layout: a 4-byte record count, then the records; the record array is allocated with a 16-byte header. */
#define TABLE_FILE_COUNT_SIZE 4
#define TABLE_FILE_ALIGN 16
#define ARRAY_HEADER_SIZE 16

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
/* Opaque table record; only its size is known. */
struct VsPcRecord { char raw[0x9c]; };
/* Loaded table: record count and the record array. */
struct VsPcTable {
    int count;
    VsPcRecord *records;
    VsPcTable() : count(0), records(0) {}
};
extern "C" VsPcTable *DAT_0034173c;
/* One-time loader of the VsPc list table: returns 1 when it was loaded, 0 when it already existed or the file is bad. */
extern "C" int FUN_00193a28(void)
{
    int ok = 0;
    if (DAT_0034173c == 0) {
        int file_size;
        void *file = FUN_0004cad0(DAT_002e14b8, &file_size, TABLE_FILE_ALIGN, 1);
        if (file != 0) {
            int count;
            FUN_00011090(&count, file, TABLE_FILE_COUNT_SIZE);
            if (file_size == count * (int)sizeof(VsPcRecord) + TABLE_FILE_COUNT_SIZE) {
                DAT_0034173c = new VsPcTable;
                if (DAT_0034173c != 0) {
                    DAT_0034173c->records = (VsPcRecord *)FUN_000008d8(
                        FUN_00000a90(count * sizeof(VsPcRecord) + ARRAY_HEADER_SIZE), (void *)FUN_0008d650, 0,
                        sizeof(VsPcRecord), count);
                    DAT_0034173c->count = count;
                    FUN_00011090(DAT_0034173c->records, (char *)file + TABLE_FILE_COUNT_SIZE, count * sizeof(VsPcRecord));
                    ok = 1;
                    if (DAT_002e1525)
                        DAT_002e1525 = 0;
                }
            }
            if (file != 0)
                FUN_000104e0(file);
        }
    }
    return ok;
}
