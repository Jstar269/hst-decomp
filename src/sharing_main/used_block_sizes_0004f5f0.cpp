/* HSTMATCH module=hstp_trans_main.prx start=0x0004f5f0 end=0x0004f668 symbol=FUN_0004f5f0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Walks the block list at DAT_003d4574 and returns, through the two out-pointers, the largest and the
   total size (end - begin) of the blocks whose flag at +8 is set. The maximum is a reference-returning
   inline Max (retail picks the larger value by address: the size local lives at sp+12). */
struct Node {
    int f0;
    Node *next;
    unsigned char used;
    char pad9[3];
    unsigned begin;
    unsigned end;
};

extern "C" Node *DAT_003d4574;

template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }

extern "C" void FUN_0004f5f0(unsigned *maxp, unsigned *total)
{
    *maxp = 0;
    *total = 0;
    for (Node *n = DAT_003d4574; n != 0; n = n->next) {
        if (n->used) {
            unsigned size = n->end - n->begin;
            *maxp = Max(*maxp, size);
            *total += size;
        }
    }
}
