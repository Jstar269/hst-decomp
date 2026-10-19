/* HSTMATCH module=EBOOT.BIN start=0x002295f4 end=0x002296a0 symbol=FUN_002295f4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: structured do-while loop with post-decrement skip check; exact match verified; names and types await human review. */

extern char *FUN_00014d64(const char *haystack, const char *needle);
extern void FUN_000643e8(void **it);

struct Node {
    void *pad[3];
    char *value;
};

struct Map {
    void *pad;
    void *header;
    void *pad2;
    struct Node *begin;
};

char *FUN_002295f4(struct Map *map, const char *str, int skip_count)
{
    struct Node *it = map->begin;
    char *res = 0;

    if (it != (struct Node *)&map->header) {
        do {
            char *val = it->value;
            if (FUN_00014d64(val, str) == val) {
                if (skip_count-- <= 0) {
                    res = it->value;
                    break;
                }
            }
            FUN_000643e8((void **)&it);
        } while (it != (struct Node *)&map->header);
    }

    return res;
}
