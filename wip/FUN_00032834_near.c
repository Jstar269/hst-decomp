/* HSTMATCH module=EBOOT.BIN start=0x00032834 end=0x00032854 symbol=FUN_00032834 lang=c99 */
extern void FUN_00032608(void *, int, void *);
struct Y { char pad[48]; int f30; };

void FUN_00032834(void *x, struct Y *y)
{
    void *p = (char *)x + 24;
    y->f30 = y->f30 | 0x1000;
    FUN_00032608(y, 3, p);
}
// NEAR (7 vs 8 words, 32 bytes): retail materialises `a0+24` into a0 (`addiu a0,a0,24`) and then copies it
// (`move a2,a0`), and both happen BEFORE the `ori`/`sw` of the flag update; every spelling that names the
// pointer as a local still folds the addiu into `addiu a2,a0,24`.
// near miss from lane dsn3 (unreviewed)
