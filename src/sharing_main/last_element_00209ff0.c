/* HSTMATCH module=hstp_trans_main.prx start=0x00209ff0 end=0x0020a014 symbol=FUN_00209ff0 lang=c99 */
/* Clone of src/eboot/last_element_001fb8d8.c (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Self {
    char pad0[140];
    int arr[21];
    int count;                   /* 224 */
} Self;

int FUN_00209ff0(Self *self)
{
    int n = self->count;
    if (n > 0)
        return self->arr[--n];
    return 0;
}
