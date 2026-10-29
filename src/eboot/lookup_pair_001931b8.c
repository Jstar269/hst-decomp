/* HSTMATCH module=EBOOT.BIN start=0x001931b8 end=0x0019335c symbol=FUN_001931b8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/challenge_tables.h"

/* Challenge entry; each of its two references names a record in another table. */
typedef struct ChallengeEntry {
    char pad00[0x33];
    u8 ref_a;           /* 0x33 CHALLENGE_REF_* */
    u8 ref_b;           /* 0x34 CHALLENGE_REF_* */
    char pad35[9];
    char name_a[0x10];  /* 0x3e name of the record ref_a refers to */
    char name_b[0x10];  /* 0x4e name of the record ref_b refers to */
} ChallengeEntry;

extern ChallengeTableBig *DAT_00341730;
extern ChallengeIndex *DAT_00341748;
extern ChallengeRecBig *FUN_00193364(const char *);
extern void FUN_00196478(TreeNode **, TreeMap *, const char **);

/* Record of the first table with this name, or 0. */
static inline ChallengeRecBig *LookupVal(const char *key)
{
    TreeNode *it;
    if (DAT_00341730 != 0) {
        FUN_00196478(&it, &DAT_00341748->unk30, &key);
        if (it != (TreeNode *)&DAT_00341748->unk30.root) {
            return DAT_00341730->records + it->value;
        }
    }
    return 0;
}

/* Resolves the entry's two references into record pointers; either output may be 0 to skip it. */
void FUN_001931b8(ChallengeRecBig **out_a, ChallengeRecBig **out_b, const ChallengeEntry *entry)
{
    if (entry == 0) return;
    if (out_a != 0) {
        switch (entry->ref_a) {
        default:
            *out_a = 0;
            break;
        case CHALLENGE_REF_TABLE_A:
            *out_a = LookupVal(entry->name_a);
            break;
        case CHALLENGE_REF_VSPC:
            *out_a = FUN_00193364(entry->name_a);
            break;
        }
    }
    if (out_b == 0) return;
    switch (entry->ref_b) {
    default:
        *out_b = 0;
        break;
    case CHALLENGE_REF_TABLE_A:
        *out_b = LookupVal(entry->name_b);
        break;
    case CHALLENGE_REF_VSPC:
        *out_b = FUN_00193364(entry->name_b);
        break;
    }
}
