/* HSTMATCH module=hstp_trans_main.prx start=0x0019f9c8 end=0x0019fb6c symbol=FUN_0019f9c8 lang=c99 */
/* Clone of src/eboot/lookup_pair_001931b8.c (hstclone.py tag fm1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char *DAT_003eaa70;
extern int DAT_003eaa88;
extern int FUN_0019fb74(const char *);
extern void FUN_001a2d70(void *, int, void *);

static inline int LookupVal(const char *key)
{
    int it;
    if (DAT_003eaa70 != 0) {
        FUN_001a2d70(&it, DAT_003eaa88 + 48, &key);
        if (it != DAT_003eaa88 + 52) {
            return *(int *)(DAT_003eaa70 + 4) + *(int *)(it + 16) * 156;
        }
    }
    return 0;
}

void FUN_0019f9c8(int *param_1, int *param_2, const char *param_3)
{
    if (param_3 == 0) return;
    if (param_1 != 0) {
        switch ((unsigned char)param_3[0x33]) {
        default:
            *param_1 = 0;
            break;
        case 1:
            *param_1 = LookupVal(param_3 + 0x3e);
            break;
        case 2:
            *param_1 = FUN_0019fb74(param_3 + 0x3e);
            break;
        }
    }
    if (param_2 == 0) return;
    switch ((unsigned char)param_3[0x34]) {
    default:
        *param_2 = 0;
        break;
    case 1:
        *param_2 = LookupVal(param_3 + 0x4e);
        break;
    case 2:
        *param_2 = FUN_0019fb74(param_3 + 0x4e);
        break;
    }
}
