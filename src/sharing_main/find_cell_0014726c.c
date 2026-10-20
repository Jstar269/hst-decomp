/* HSTMATCH module=hstp_trans_main.prx start=0x0014726c end=0x001472c8 symbol=FUN_0014726c lang=c99 */
/* Clone of src/eboot/find_cell_0013bc20.c (hstclone.py tag s10200333g2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
typedef struct { int key; int a; int b; } Cell;
typedef struct { unsigned char pad[0x1450]; Cell *cells; volatile unsigned int count; } Self;

int FUN_0014726c(Self *self, int key, int which)
{
    int result = 45;
    unsigned int i;

    /* volatile: retail reloads the count on every loop iteration instead of hoisting it. */
    for (i = 0; i < self->count; i++) {
        Cell *cell = &self->cells[i];
        if (key == cell->key) {
            if (which == 1)
                result = cell->a;
            else
                result = cell->b;
        }
    }
    return result;
}
