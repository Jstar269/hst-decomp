/* HSTMATCH module=EBOOT.BIN start=0x001931b8 end=0x0019335c symbol=FUN_001931b8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char *DAT_00341730;
extern int DAT_00341748;
extern int FUN_00193364(const char *);
extern void FUN_00196478(void *, int, void *);

static inline int LookupVal(const char *key)
{
    int it;
    if (DAT_00341730 != 0) {
        FUN_00196478(&it, DAT_00341748 + 48, &key);
        if (it != DAT_00341748 + 52) {
            return *(int *)(DAT_00341730 + 4) + *(int *)(it + 16) * 156;
        }
    }
    return 0;
}

void FUN_001931b8(int *param_1, int *param_2, const char *param_3)
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
            *param_1 = FUN_00193364(param_3 + 0x3e);
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
        *param_2 = FUN_00193364(param_3 + 0x4e);
        break;
    }
}
