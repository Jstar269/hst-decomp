/* HSTMATCH module=hstp_trans_main.prx start=0x0018753c end=0x00187724 symbol=FUN_0018753c lang=c99 */
/* Hand-written reconstruction from the disassembly; matching idiom: nested range check with aligned offset; exact match verified; names and types await human review. */

extern char DAT_00387ccc;

extern void FUN_00066260(void *p2, void *p3, int zero1, int zero2, const void *p5);
extern int FUN_00065fa4(void *p2);
extern void *FUN_000661a8(void *p2, int idx, int field);
extern float FUN_000660f0(void *p2, int idx, int field);
extern int FUN_00066038(void *p2, int idx, int field);
extern void FUN_00014b74(void *dst, const void *src, unsigned int size);

void FUN_0018753c(void *param_1, void *param_2, void *param_3)
{
    FUN_00066260(param_2, param_3, 0, 0, &DAT_00387ccc);
    int count = FUN_00065fa4(param_2);

    int offset = 0;
    for (int i = 1; i < count; i++) {
        FUN_000661a8(param_2, i, 0);
        char *type_str = (char *)FUN_000661a8(param_2, i, 1);
        char type = *type_str;

        if (type == 'f') {
            float val = FUN_000660f0(param_2, i, 4);
            float min = FUN_000660f0(param_2, i, 2);
            float max = FUN_000660f0(param_2, i, 3);
            if (min <= val && val <= max) {
                *(float *)((char *)param_1 + (offset & -4)) = val;
                offset += 4;
            }
        } else if (type == 'i') {
            int val = FUN_00066038(param_2, i, 4);
            int min = FUN_00066038(param_2, i, 2);
            int max = FUN_00066038(param_2, i, 3);
            if (min <= val) {
                if (val <= max) {
                    *(int *)((char *)param_1 + (offset & -4)) = val;
                    offset += 4;
                }
            }
        } else if (type == 's') {
            void *str = FUN_000661a8(param_2, i, 4);
            FUN_00014b74((char *)param_1 + offset, str, 0x20);
            offset += 8;
        }
    }
}
