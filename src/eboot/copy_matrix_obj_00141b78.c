/* HSTMATCH module=EBOOT.BIN start=0x00141b78 end=0x00141c10 symbol=FUN_00141b78 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed 16-element float matrix and int id; exact match verified; names and types await human review. */

struct Obj {
    int id;
    char pad[12];
    float m[16];
};

void FUN_00141b78(void *self, struct Obj *dest, const struct Obj *src)
{
    if (dest == 0) {
        return;
    }
    dest->id = src->id;
    dest->m[0] = src->m[0];
    dest->m[1] = src->m[1];
    dest->m[2] = src->m[2];
    dest->m[3] = src->m[3];
    dest->m[4] = src->m[4];
    dest->m[5] = src->m[5];
    dest->m[6] = src->m[6];
    dest->m[7] = src->m[7];
    dest->m[8] = src->m[8];
    dest->m[9] = src->m[9];
    dest->m[10] = src->m[10];
    dest->m[11] = src->m[11];
    dest->m[12] = src->m[12];
    dest->m[13] = src->m[13];
    dest->m[14] = src->m[14];
    dest->m[15] = src->m[15];
}
