/* HSTMATCH module=EBOOT.BIN start=0x0004ffc4 end=0x00050044 symbol=FUN_0004ffc4 lang=c99 */
/* Clone of src/sharing_main/dispatch_obj_kind_000508a0.c (hstclone.py tag s10170158a1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-sh2/v0) corrected by hand: switch statement on obj->kind with inner result variable assigned to outer result; exact match verified; names and types await human review. */
typedef unsigned char uchar;

typedef struct {
    char pad[0x18];
    void *ptr;
    char pad2[0x8c - 0x1c];
    uchar kind;
} Obj;

extern Obj *FUN_00050210(void);
extern int FUN_00023a28(void *p, int param_3, int zero);
extern int FUN_0003e258(void *p, int param_3);

int FUN_0004ffc4(int param_1, int param_2, int param_3)
{
    int res = 0;
    Obj *obj = FUN_00050210();
    if (obj != 0) {
        int r;
        switch (obj->kind) {
        case 3:
            r = FUN_00023a28(obj->ptr, param_3, 0);
            break;
        case 1:
            r = FUN_0003e258(obj->ptr, param_3);
            break;
        default:
            r = 0;
            break;
        }
        res = r;
    }
    return res;
}
