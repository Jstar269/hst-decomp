/* HSTMATCH module=EBOOT.BIN start=0x002230dc end=0x00223144 symbol=FUN_002230dc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: typed subobject struct and natural for-loop; exact match verified; names and types await human review. */

struct Sub {
    char pad[0x60];
    float f96;
    float f100;
};

struct Obj {
    char pad[0x68];
    struct Sub *sub[2];
    char pad2[0xb4 - 0x70];
    float f180;
    float f184;
};

extern void FUN_00103480(struct Obj *);

void FUN_002230dc(struct Obj *param_1, float param_2, float param_3)
{
    int i;
    param_1->f180 = param_2 - 182.0f;
    param_1->f184 = param_3 - 50.0f;

    for (i = 0; i < 2; i++) {
        if (param_1->sub[i] != 0 && i == 0) {
            param_1->sub[i]->f96 = param_1->f180;
            param_1->sub[i]->f100 = param_1->f184;
        }
    }
    FUN_00103480(param_1);
}
