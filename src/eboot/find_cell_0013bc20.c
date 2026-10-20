/* HSTMATCH module=EBOOT.BIN start=0x0013bc20 end=0x0013bc7c symbol=FUN_0013bc20 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
typedef struct { int key; int a; int b; } Cell;
typedef struct { unsigned char pad[0x1450]; Cell *cells; volatile unsigned int count; } Self;

int FUN_0013bc20(Self *self, int key, int which)
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
