/* HSTMATCH module=hstp_trans_main.prx start=0x001c72f4 end=0x001c73f4 symbol=FUN_001c72f4 lang=c++ */
/* Clone of src/eboot/list_insert_copy_001b9608.cpp (hstclone.py tag ds1011s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
void *FUN_00000bcc(unsigned size);
struct Reent_001c72f4 { int pad[3]; void *err; };
Reent_001c72f4 *FUN_0000fe3c(void);
void FUN_001c328c(...);
void FUN_0000d530(void);
void FUN_00000a00(void *);
extern char DAT_002d6720[];
}
inline void *operator new(unsigned, void *p) { return p; }
struct Vec4_001c72f4 { float x, y, z, w; };
struct Node_001c72f4 { Node_001c72f4 *next; Node_001c72f4 *prev; Vec4_001c72f4 v; };
struct Guard_001c72f4 { int *p; Node_001c72f4 *n; ~Guard_001c72f4() { if (n) FUN_00000a00(n); } };
extern "C" int FUN_001c72f4(Node_001c72f4 **out, int *count, Node_001c72f4 **head, const Vec4_001c72f4 *src)
{
    int *cp = count + 1;
    Node_001c72f4 *n = (Node_001c72f4 *)FUN_00000bcc(0x18);
    if (n == 0) {
        FUN_001c328c(FUN_0000fe3c()->err, DAT_002d6720);
        FUN_0000d530();
    }
    Guard_001c72f4 g;
    g.p = cp;
    g.n = n;
    new (&n->v) Vec4_001c72f4(*src);
    g.n = 0;
    Node_001c72f4 *h = *head;
    h->next->prev = n;
    n->next = h->next;
    h->next = n;
    n->prev = h;
    *count = *count + 1;
    *out = n;
    return 0;
}
