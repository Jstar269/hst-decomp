/* HSTMATCH module=hstp_trans_main.prx start=0x0018a524 end=0x0018a544 symbol=FUN_0018a524 */
/* Clone of src/eboot/FUN_0017de30.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
typedef struct { char pad[0x34]; float t; char pad2[8]; unsigned char dirty; } Timer34;

void FUN_0018a524(Timer34 *t, float dt, int mark)
{
    t->t += dt;
    if (mark) t->dirty = 1;
}
