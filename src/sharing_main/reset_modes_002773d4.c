/* HSTMATCH module=hstp_trans_main.prx start=0x002773d4 end=0x002774e4 symbol=FUN_002773d4 lang=c99 */
/* Clone of src/eboot/reset_modes_002664cc.c (hstclone.py tag ds1011s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_000587ac(void *p, int a1, int a2, float f);
extern void FUN_00059ac0(void *p, int a1, int a2);
extern void FUN_00059c1c(void *p, int a1, float f);
extern void FUN_0005ff00(void *p, float f);
extern void FUN_00059d68(void *p, int a1);

static inline void ModeA_002773d4(void *p, int x)
{
    FUN_000587ac(p, 0, x, 0.0f);
}

static inline void ModeB_002773d4(void *p, int y)
{
    FUN_00059ac0(p, y, -1);
    *(char *)((char *)p + 0xc0) = (char)y;
}

static inline void ModeC_002773d4(void *p)
{
    FUN_00059c1c(p, -1, 0.0f);
    FUN_0005ff00(p, 0.0f);
}

static inline void ModeD_002773d4(void *p)
{
    FUN_00059d68(p, -1);
    *(float *)((char *)p + 0xd0) = *(float *)((char *)p + 0xc4);
}

void FUN_002773d4(char *self, int x, int y)
{
    ModeA_002773d4(*(void **)(self + 0x70), x);
    ModeB_002773d4(*(void **)(self + 0x70), y);
    ModeC_002773d4(*(void **)(self + 0x70));
    ModeD_002773d4(*(void **)(self + 0x70));
    if (*(void **)(self + 0x74) == 0)
        return;
    ModeA_002773d4(*(void **)(self + 0x74), x);
    ModeB_002773d4(*(void **)(self + 0x74), y);
    ModeC_002773d4(*(void **)(self + 0x74));
    ModeD_002773d4(*(void **)(self + 0x74));
}
