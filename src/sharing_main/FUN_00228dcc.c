/* HSTMATCH module=hstp_trans_main.prx start=0x00228dcc end=0x00228e80 symbol=FUN_00228dcc lang=c99 */
/* Clone of src/eboot/FUN_002198b4.c (hstclone.py tag s10172123g5r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: inlined sequential random coordinate generation; exact match verified; names and types await human review. */

extern int FUN_0001342c(void);

struct Obj {
    char pad[144];
    float x;
    float y;
    float z;
    float w;
};

void FUN_00228dcc(struct Obj *self)
{
    float rx = (1.0f - ((float)FUN_0001342c() * 2.0f) / 2147483648.0f) * 2.5f;
    float rz = (1.0f - ((float)FUN_0001342c() * 2.0f) / 2147483648.0f) * 2.5f;

    self->x = rx;
    *(int *)&self->y = 0xc0600000;
    self->z = rz;
    *(int *)&self->w = 0;
}
