/* HSTMATCH module=hstp_trans_main.prx start=0x000c0ef8 end=0x000c0fbc symbol=FUN_000c0ef8 lang=c99 */
/* Clone of src/eboot/check_entry_count_000bd97c.c (hstclone.py tag s10172123g8r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

typedef unsigned char u8;

extern int FUN_0001100c(const void *s1, const void *s2, int n);

struct Obj {
    char pad0[62];
    char target[6];
    char pad1[20];
    char entries[16 * 7];
    char pad2[200];
    int count;
    char pad3[136];
    u8 flags2[16];
};

static inline int FindMatch(struct Obj *obj, const char *target) {
    int i = 0;
    char *p = (char *)obj;
    for (; i < 16; i++, p += 7) {
        if (*(u8 *)(p + 94) == 0)
            continue;
        if (FUN_0001100c(p + 88, target, 6) != 0)
            continue;
        return i;
    }
    return -1;
}

int FUN_000c0ef8(struct Obj *obj) {
    const char *target = obj->target;
    int match = FindMatch(obj, target);
    int count = 0;
    int j = 0;
    do {
        if (obj->flags2[j] != 0 || j == match) {
            count++;
        }
        j++;
    } while (j < 16);

    return obj->count == count;
}
