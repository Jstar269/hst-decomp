/* HSTMATCH module=EBOOT.BIN start=0x00193cdc end=0x00193e40 symbol=FUN_00193cdc lang=c++ */
/* Clone of src/eboot/load_challenge_table_00193a28.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* One-time loader of the second challenge table (path pointer at 0x2e1520, "data/menu/challenge/Challenge Vs..."):
   same shape as 0x1938d8 with 156-byte records (constructor 0x8d650), plus clearing the byte flag at 0x2e1526
   after a successful load. Names provisional. */
extern "C" {
void *FUN_0004cad0(const char *path, int *size, int align, int flag);
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_00000a90(unsigned size);
void *FUN_000008d8(void *block, void *ctor, void *dtor, unsigned size, unsigned n);
void FUN_0008d650(void);
void FUN_000104e0(void *p);
extern const char *DAT_002e1520;
extern unsigned char DAT_002e1526;
}
struct Record_00193cdc { char raw[0x9c]; };
struct Table_00193cdc {
    int count;
    Record_00193cdc *records;
    Table_00193cdc() : count(0), records(0) {}
};
extern "C" Table_00193cdc *DAT_00341744;
extern "C" int FUN_00193cdc(void)
{
    int ok = 0;
    if (DAT_00341744 == 0) {
        int size;
        void *buf = FUN_0004cad0(DAT_002e1520, &size, 16, 1);
        if (buf != 0) {
            int count;
            FUN_00011090(&count, buf, 4);
            if (size == count * (int)sizeof(Record_00193cdc) + 4) {
                DAT_00341744 = new Table_00193cdc;
                if (DAT_00341744 != 0) {
                    DAT_00341744->records = (Record_00193cdc *)FUN_000008d8(
                        FUN_00000a90(count * sizeof(Record_00193cdc) + 16), (void *)FUN_0008d650, 0,
                        sizeof(Record_00193cdc), count);
                    DAT_00341744->count = count;
                    FUN_00011090(DAT_00341744->records, (char *)buf + 4, count * sizeof(Record_00193cdc));
                    ok = 1;
                    if (DAT_002e1526)
                        DAT_002e1526 = 0;
                }
            }
            if (buf != 0)
                FUN_000104e0(buf);
        }
    }
    return ok;
}
