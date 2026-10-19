/* HSTMATCH module=EBOOT.BIN start=0x000e189c end=0x000e193c symbol=FUN_000e189c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: Vec4 local temporaries and field-wise destination copy; exact match verified; names and types await human review. */
typedef unsigned int uint;

typedef struct Vec4 {
    float x, y, z, w;
} Vec4;

extern uint DAT_002d6b4c[];
extern void FUN_0001d7e4(Vec4 *out, uint param_2);

void FUN_000e189c(char *param_1, int param_2)
{
    Vec4 v1;
    Vec4 v2;
    Vec4 *dst;

    FUN_0001d7e4(&v1, *(uint *)(*(int *)(param_1 + 0x3c) + 0x38));
    if (DAT_002d6b4c[param_2] != 0) {
        FUN_0001d7e4(&v2, DAT_002d6b4c[param_2]);
        v1 = v2;
    }
    dst = (Vec4 *)(param_1 + 0x80);
    dst->x = v1.x;
    dst->y = v1.y;
    dst->z = v1.z;
    dst->w = v1.w;
}
