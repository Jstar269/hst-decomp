/* HSTMATCH module=EBOOT.BIN start=0x0001b73c end=0x0001b788 symbol=FUN_0001b73c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct
{
    unsigned int pad00;
    unsigned int mod;
} Hash;

unsigned int FUN_0001b73c(Hash *self, const char *s)
{
    unsigned int hash = 0;
    signed char c = *s;

    if (c)
    {
        do
        {
            hash = ((hash << 3) & 0xfffffff8u) | ((hash >> 29) & 7u);
            hash ^= (unsigned int)(c << 7);
            s++;
            c = *s;
        } while (c);
    }
    return hash % self->mod;
}
