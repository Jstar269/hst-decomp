/* HSTMATCH module=hstp_trans_main.prx start=0x000508a0 end=0x00050920 symbol=FUN_000508a0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-sh2/v0) corrected by hand: switch statement on obj->kind with inner result variable assigned to outer result; exact match verified; names and types await human review. */
typedef unsigned char uchar;

typedef struct {
    char pad[0x18];
    void *ptr;
    char pad2[0x8c - 0x1c];
    uchar kind;
} Obj;

extern Obj *FUN_00050aec(void);
extern int FUN_00023a50(void *p, int param_3, int zero);
extern int FUN_0003e280(void *p, int param_3);

int FUN_000508a0(int param_1, int param_2, int param_3)
{
    int res = 0;
    Obj *obj = FUN_00050aec();
    if (obj != 0) {
        int r;
        switch (obj->kind) {
        case 3:
            r = FUN_00023a50(obj->ptr, param_3, 0);
            break;
        case 1:
            r = FUN_0003e280(obj->ptr, param_3);
            break;
        default:
            r = 0;
            break;
        }
        res = r;
    }
    return res;
}
