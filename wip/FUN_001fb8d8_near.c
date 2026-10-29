/* HSTMATCH module=EBOOT.BIN start=0x001fb8d8 end=0x001fb8fc symbol=FUN_001fb8d8 lang=c99 */
typedef struct Self {
    char pad0[140];
    int arr[21];
    int count;                   /* 224 */
} Self;
int FUN_001fb8d8(Self *self)
{
    int n = self->count;
    int k = n - 1;

    return n > 0 ? self->arr[k] : 0;
}
// near miss from lane dsn3 (unreviewed)
