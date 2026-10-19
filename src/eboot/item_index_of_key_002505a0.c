/* HSTMATCH module=EBOOT.BIN start=0x002505a0 end=0x0025060c symbol=FUN_002505a0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Node { int id; } Node;
typedef struct Mgr {
    char pad[0x350];
    Node **items;
    int count;
} Mgr;

int FUN_002505a0(Mgr *m, int key, int skip)
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
