/* HSTMATCH module=hstp_trans_main.prx start=0x002608f4 end=0x00260960 symbol=FUN_002608f4 lang=c99 */
/* Clone of src/eboot/item_index_of_key_002505a0.c (hstclone.py tag ds1018ar4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Node { int id; } Node;
typedef struct Mgr {
    char pad[0x350];
    Node **items;
    int count;
} Mgr;

int FUN_002608f4(Mgr *m, int key, int skip)
{
    int r = 0;
    int i = 0;

    if (skip != 0) {
        r = 0;
    } else {
        Node **p = m->items;
        Node **end = p + m->count;
        int more = !(p == end);

        while (more) {
            if (key == (*p)->id) {
                r = i;
                break;
            }
            p++;
            i++;
            more = !(p == end);
        }
    }
    return r;
}
