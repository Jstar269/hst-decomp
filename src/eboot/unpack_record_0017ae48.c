/* HSTMATCH module=EBOOT.BIN start=0x0017ae48 end=0x0017b030 symbol=FUN_0017ae48 lang=c99 */
/* LoadMenuParamCsv: generic name/type/min/max/value menu parameter files; see docs/DATA-TABLES.md */
/* Clone of src/sharing_main/unpack_record_0018753c.c (hstclone.py tag u1r5e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; matching idiom: nested range check with aligned offset; exact match verified; names and types await human review. */

extern char DAT_002e0694;

extern void FUN_000651b8(void *p2, void *p3, int zero1, int zero2, const void *p5);
extern int FUN_000650e0(void *p2);
extern void *FUN_0006517c(void *p2, int idx, int field);
extern float FUN_00065140(void *p2, int idx, int field);
extern int FUN_00065104(void *p2, int idx, int field);
extern void FUN_00014b74(void *dst, const void *src, unsigned int size);

void FUN_0017ae48(void *out, void *csv, void *path)
{
    FUN_000651b8(csv, path, 0, 0, &DAT_002e0694);
    int count = FUN_000650e0(csv);

    int offset = 0;
    for (int i = 1; i < count; i++) {
        FUN_0006517c(csv, i, 0);
        char *type_str = (char *)FUN_0006517c(csv, i, 1);
        char type = *type_str;

        if (type == 'f') {
            float val = FUN_00065140(csv, i, 4);
            float min = FUN_00065140(csv, i, 2);
            float max = FUN_00065140(csv, i, 3);
            if (min <= val && val <= max) {
                *(float *)((char *)out + (offset & -4)) = val;
                offset += 4;
            }
        } else if (type == 'i') {
            int val = FUN_00065104(csv, i, 4);
            int min = FUN_00065104(csv, i, 2);
            int max = FUN_00065104(csv, i, 3);
            if (min <= val) {
                if (val <= max) {
                    *(int *)((char *)out + (offset & -4)) = val;
                    offset += 4;
                }
            }
        } else if (type == 's') {
            void *str = FUN_0006517c(csv, i, 4);
            FUN_00014b74((char *)out + offset, str, 0x20);
            offset += 8;
        }
    }
}
