/* HSTMATCH module=EBOOT.BIN start=0x000bd97c end=0x000bda40 symbol=FUN_000bd97c lang=c99 */
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

int FUN_000bd97c(struct Obj *obj) {
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
