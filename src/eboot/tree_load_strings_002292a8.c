/* HSTMATCH module=EBOOT.BIN start=0x002292a8 end=0x002293d4 symbol=FUN_002292a8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reconstructed FUN_002293d4(param_1) delay-slot save, Pair local layout at 36(sp), and branch structure; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/tree_map.h"

extern void FUN_000009e4(u32);
extern u32 FUN_00000a90(int);
extern void FUN_000104e0(void *);
extern void *FUN_000149a8(u32, void *);
extern int FUN_00014a40(void *);
extern void *FUN_0004cad0(int, int *, int, int);
extern void FUN_002293d4(TreeMap *);
extern void FUN_00229868(void *, TreeMap *, void *);
extern void FUN_0022999c(void *, TreeMap *, void *);

/* One name-table entry: the heap string and its position in the file. */
struct Pair {
    u32 key;
    int val;
};

/* Reloads the name tree from a file: a count, then offsets of NUL-terminated strings. Returns 1 on success. */
int FUN_002292a8(TreeMap *map, int file)
{
    int file_size;
    u32 name;
    TreeNode *found;
    u8 insert_out[8];
    struct Pair entry;

    FUN_002293d4(map);
    int *data = (int *)FUN_0004cad0(file, &file_size, 16, 1);
    if (data == 0 || file_size <= 0) {
        return 0;
    }
    *(u8 *)(file_size + (int)data + -1) = 0;

    int count = *data;
    int *offsets = data + 1;
    int i = 0;

    if (count > 0) {
        do {
            int offset = *offsets++;
            void *str = (char *)data + offset;
            int slen = FUN_00014a40(str);
            name = FUN_00000a90(slen + 1);
            FUN_000149a8(name, str);

            FUN_00229868(&found, map, &name);
            if (found != (TreeNode *)&map->root) {
                FUN_000009e4(name);
            } else {
                entry.key = name;
                entry.val = i;
                FUN_0022999c(insert_out, map, &entry);
            }
            i++;
        } while (i < count);
    }

    FUN_000104e0(data);
    return 1;
}
