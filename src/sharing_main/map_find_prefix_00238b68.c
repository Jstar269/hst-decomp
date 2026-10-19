/* HSTMATCH module=hstp_trans_main.prx start=0x00238b68 end=0x00238c14 symbol=FUN_00238b68 lang=c99 */
/* Clone of src/eboot/map_find_prefix_002295f4.c (hstclone.py tag s10172123g5r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: structured do-while loop with post-decrement skip check; exact match verified; names and types await human review. */

extern char *FUN_00014d64(const char *haystack, const char *needle);
extern void FUN_000652ac(void **it);

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

char *FUN_00238b68(struct Map *map, const char *str, int skip_count)
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
            FUN_000652ac((void **)&it);
        } while (it != (struct Node *)&map->header);
    }

    return res;
}
