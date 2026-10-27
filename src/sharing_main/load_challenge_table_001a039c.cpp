/* HSTMATCH module=hstp_trans_main.prx start=0x001a039c end=0x001a04ec symbol=FUN_001a039c lang=c++ data=0x00388b98 */
/* Clone of src/eboot/load_challenge_table_001938d8.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. Data: its string-pointer tables (1 tables, 1 strings, 0x00388b98-0x00388bd0) are defined in place and placed with data= (tools/hstdatapool.py tables); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* One-time loader of the challenge table (path pointer at 0x388bcc, "data/menu/challenge/Challenge Ma..."):
   read the file through 0x4cad0, check its size against a leading 108-byte-record count, create the table
   object (count + record array; the array comes from operator new[] 0xa90 and the array constructor helper
   0x8d8 with record constructor 0x8e93c), copy the records, free the file buffer (0x104e0). Names provisional. */
extern "C" {
void *FUN_0004cd8c(const char *path, int *size, int align, int flag);
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_00000a90(unsigned size);
void *FUN_000008d8(void *block, void *ctor, void *dtor, unsigned size, unsigned n);
void FUN_0008e93c(void);
void FUN_000104e0(void *p);
const char *DAT_00388bcc = "data/menu/challenge/Challenge_ExhibitionTable.bin";
}
struct Record_001a039c { char raw[0x6c]; };
struct Table_001a039c {
    int count;
    Record_001a039c *records;
    Table_001a039c() : count(0), records(0) {}
};
extern "C" Table_001a039c *DAT_003eaa80;
extern "C" int FUN_001a039c(void)
{
    int ok = 0;
    if (DAT_003eaa80 == 0) {
        int size;
        void *buf = FUN_0004cd8c(DAT_00388bcc, &size, 16, 1);
        if (buf != 0) {
            int count;
            FUN_00011090(&count, buf, 4);
            if (size == count * (int)sizeof(Record_001a039c) + 4) {
                DAT_003eaa80 = new Table_001a039c;
                if (DAT_003eaa80 != 0) {
                    DAT_003eaa80->records = (Record_001a039c *)FUN_000008d8(
                        FUN_00000a90(count * sizeof(Record_001a039c) + 16), (void *)FUN_0008e93c, 0,
                        sizeof(Record_001a039c), count);
                    DAT_003eaa80->count = count;
                    FUN_00011090(DAT_003eaa80->records, (char *)buf + 4, count * sizeof(Record_001a039c));
                    ok = 1;
                }
            }
            if (buf != 0)
                FUN_000104e0(buf);
        }
    }
    return ok;
}
