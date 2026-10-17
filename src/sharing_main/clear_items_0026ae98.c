/* HSTMATCH module=hstp_trans_main.prx start=0x0026ae98 end=0x0026af40 symbol=FUN_0026ae98 lang=c99 */
/* Clone of src/eboot/clear_items_0025a9e8.c (hstclone.py tag u5fr4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed struct, delete argument, buffer order, if/else and loop control flow; exact match verified; names and types await human review. */

extern void FUN_00000a00(void *p);
extern void FUN_0026ab28(void *p, void *a, void *b);
extern void FUN_0026acbc(void *buf, void *p, int x);
extern void FUN_0026afc0(void *p);

struct Obj_0026ae98 {
    int pad0;
    unsigned int state;   // +4
    int index;            // +8
    void **items;         // +12
    int flags;            // +16
    int count;            // +20
};

void FUN_0026ae98(struct Obj_0026ae98 *param_1)
{
    int buf1[6];
    int buf2[6];

    FUN_0026acbc(buf2, param_1, param_1->count);
    FUN_0026acbc(buf1, param_1, 0);
    FUN_0026ab28(param_1, buf1, buf2);
    param_1->count = 0;
    if (param_1->state > 1) {
        while (param_1->state > 2) {
            FUN_00000a00(param_1->items[param_1->index]);
            FUN_0026afc0(param_1);
        }
        param_1->flags = 64;
    } else {
        param_1->flags = 0;
    }
}
