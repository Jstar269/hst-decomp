/* HSTMATCH module=EBOOT.BIN start=0x00289654 end=0x0028966c symbol=FUN_00289654 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct { int count; Link head; } LinkList;

LinkList *FUN_00289654(LinkList *l)
{
    l->count = 0;
    l->head.prev = &l->head;
    l->head.next = &l->head;
    return l;
}
