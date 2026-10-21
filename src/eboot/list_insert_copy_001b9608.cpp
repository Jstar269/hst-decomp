/* HSTMATCH module=EBOOT.BIN start=0x001b9608 end=0x001b9708 symbol=FUN_001b9608 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
void *FUN_00000bcc(unsigned size);
struct Reent_001b9608 { int pad[3]; void *err; };
Reent_001b9608 *FUN_0000fe3c(void);
void FUN_001b5c44(...);
void FUN_0000d518(void);
void FUN_00000a00(void *);
extern char DAT_002c6210[];
}
inline void *operator new(unsigned, void *p) { return p; }
struct Vec4_001b9608 { float x, y, z, w; };
struct Node_001b9608 { Node_001b9608 *next; Node_001b9608 *prev; Vec4_001b9608 v; };
struct Guard_001b9608 { int *p; Node_001b9608 *n; ~Guard_001b9608() { if (n) FUN_00000a00(n); } };
extern "C" int FUN_001b9608(Node_001b9608 **out, int *count, Node_001b9608 **head, const Vec4_001b9608 *src)
{
    int *cp = count + 1;
    Node_001b9608 *n = (Node_001b9608 *)FUN_00000bcc(0x18);
    if (n == 0) {
        FUN_001b5c44(FUN_0000fe3c()->err, DAT_002c6210);
        FUN_0000d518();
    }
    Guard_001b9608 g;
    g.p = cp;
    g.n = n;
    new (&n->v) Vec4_001b9608(*src);
    g.n = 0;
    Node_001b9608 *h = *head;
    h->next->prev = n;
    n->next = h->next;
    h->next = n;
    n->prev = h;
    *count = *count + 1;
    *out = n;
    return 0;
}
