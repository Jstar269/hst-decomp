/* HSTMATCH module=EBOOT.BIN start=0x001fa23c end=0x001fa2b4 symbol=FUN_001fa23c lang=c99 */
/* Hand-written reconstruction (port of src/sharing_main/counter_step_00208924.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* Copies a->f1040 to b, then (while a->b521 and a->b1050 are set) steps the counter b->f33fc by one, clamped
   to [DAT_002ee40c, DAT_002ee410] (0 and 100 in the retail .data); the counter is cleared when a->b521 is clear
   or a->b1051 is set. The same body is inlined into FUN_001fa35c. Names provisional. */
struct A_001fa23c {
    char pad0[0x521];
    unsigned char b521;
    char pad522[0x1040 - 0x522];
    int f1040;
    char pad1044[0x1050 - 0x1044];
    unsigned char b1050;
    unsigned char b1051;
};

struct B_001fa23c {
    char pad0[0x1054];
    int f1054;
    char pad1058[0x33fc - 0x1058];
    unsigned int f33fc;
};

extern unsigned int DAT_002ee40c;
extern unsigned int DAT_002ee410;

void FUN_001fa23c(struct A_001fa23c *a, struct B_001fa23c *b)
{
    b->f1054 = a->f1040;
    if (a->b521 != 0) {
        if (a->b1050 != 0) {
            unsigned int v = b->f33fc + 1;
            b->f33fc = v < DAT_002ee40c ? DAT_002ee40c : (DAT_002ee410 < v ? DAT_002ee410 : v);
        }
    } else {
        b->f33fc = 0;
    }
    if (a->b1051 != 0) {
        b->f33fc = 0;
    }
}
