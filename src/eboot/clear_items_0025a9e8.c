/* HSTMATCH module=EBOOT.BIN start=0x0025a9e8 end=0x0025aa90 symbol=FUN_0025a9e8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed struct, delete argument, buffer order, if/else and loop control flow; exact match verified; names and types await human review. */

extern void FUN_00000a00(void *p);
extern void FUN_0025a678(void *p, void *a, void *b);
extern void FUN_0025a80c(void *buf, void *p, int x);
extern void FUN_0025ab10(void *p);

struct Obj_0025a9e8 {
    int pad0;
    unsigned int state;   // +4
    int index;            // +8
    void **items;         // +12
    int flags;            // +16
    int count;            // +20
};

void FUN_0025a9e8(struct Obj_0025a9e8 *param_1)
{
    int buf1[6];
    int buf2[6];

    FUN_0025a80c(buf2, param_1, param_1->count);
    FUN_0025a80c(buf1, param_1, 0);
    FUN_0025a678(param_1, buf1, buf2);
    param_1->count = 0;
    if (param_1->state > 1) {
        while (param_1->state > 2) {
            FUN_00000a00(param_1->items[param_1->index]);
            FUN_0025ab10(param_1);
        }
        param_1->flags = 64;
    } else {
        param_1->flags = 0;
    }
}
