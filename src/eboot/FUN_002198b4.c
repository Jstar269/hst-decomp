/* HSTMATCH module=EBOOT.BIN start=0x002198b4 end=0x00219968 symbol=FUN_002198b4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: inlined sequential random coordinate generation; exact match verified; names and types await human review. */

extern int FUN_0001342c(void);

struct Obj {
    char pad[144];
    float x;
    float y;
    float z;
    float w;
};

void FUN_002198b4(struct Obj *self)
{
    float rx = (1.0f - ((float)FUN_0001342c() * 2.0f) / 2147483648.0f) * 2.5f;
    float rz = (1.0f - ((float)FUN_0001342c() * 2.0f) / 2147483648.0f) * 2.5f;

    self->x = rx;
    *(int *)&self->y = 0xc0600000;
    self->z = rz;
    *(int *)&self->w = 0;
}
