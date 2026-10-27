/* HSTMATCH module=hstp_trans_main.prx start=0x00208924 end=0x0020899c symbol=FUN_00208924 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Copies a->f1040 to b, then (while a->b521 and a->b1050 are set) steps the counter b->f33fc by one, clamped
   to [DAT_00396338, DAT_0039633c] (0 and 100 in the retail .data); the counter is cleared when a->b521 is clear
   or a->b1051 is set. The same body is inlined into FUN_00208a44. Names provisional. */
struct A_00208924 {
    char pad0[0x521];
    unsigned char b521;
    char pad522[0x1040 - 0x522];
    int f1040;
    char pad1044[0x1050 - 0x1044];
    unsigned char b1050;
    unsigned char b1051;
};

struct B_00208924 {
    char pad0[0x1054];
    int f1054;
    char pad1058[0x33fc - 0x1058];
    unsigned int f33fc;
};

extern unsigned int DAT_00396338;
extern unsigned int DAT_0039633c;

void FUN_00208924(struct A_00208924 *a, struct B_00208924 *b)
{
    b->f1054 = a->f1040;
    if (a->b521 != 0) {
        if (a->b1050 != 0) {
            unsigned int v = b->f33fc + 1;
            b->f33fc = v < DAT_00396338 ? DAT_00396338 : (DAT_0039633c < v ? DAT_0039633c : v);
        }
    } else {
        b->f33fc = 0;
    }
    if (a->b1051 != 0) {
        b->f33fc = 0;
    }
}
