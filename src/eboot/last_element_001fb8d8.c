/* HSTMATCH module=EBOOT.BIN start=0x001fb8d8 end=0x001fb8fc symbol=FUN_001fb8d8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Self {
    char pad0[140];
    int arr[21];
    int count;                   /* 224 */
} Self;

int FUN_001fb8d8(Self *self)
{
    int n = self->count;
    if (n > 0)
        return self->arr[--n];
    return 0;
}
