/* HSTMATCH module=hstp_trans_main.prx start=0x000b43f0 end=0x000b44f8 symbol=FUN_000b43f0 lang=c99 */
/* Clone of src/eboot/remap_two_keys_000b1404.c (hstclone.py tag s10181937g6r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: unused leading int parameter (a0 is dead on entry) so the two pointer arguments arrive in a1/a2. */

int FUN_000b43f0(int unused, int *a, int *b)
{
    int old1 = *a;
    int old2 = *b;

    switch (*a) {
    case 70:
    case 74:
        *a = 72;
        break;
    case 71:
    case 75:
        *a = 73;
        break;
    }
    switch (*b) {
    case 86:
    case 94:
    case 96:
        *b = 88;
        break;
    case 87:
    case 95:
    case 97:
        *b = 89;
        break;
    case 100:
        *b = 98;
        break;
    case 101:
        *b = 99;
        break;
    }
    return (*a != old1) || (*b != old2);
}
