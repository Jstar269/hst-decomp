/* HSTMATCH module=EBOOT.BIN start=0x00280188 end=0x002803d8 symbol=FUN_00280188 lang=c++ data=0x002fe8cc */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002fe8cc-0x002fe8d3) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
// matching idioms: empty `Tag` by-value third argument of FUN_000545bc (retail `move v0,zero; seb a2,v0`); `i++` placed before the re-read of the element count (while loop) so it lands in the jal delay slot; trailing unused empty `False` parameter for the 80-byte frame.

struct False_280188 {};
struct Tag_280188 {};

struct Vec_280188 {  /* growable int array */
    int *data;         /* 0x00 */
    unsigned size;     /* 0x04 */
    unsigned capacity; /* 0x08 */
};

extern "C" {
extern void FUN_00286490(struct Vec_280188 *vec, int n);
extern int FUN_000650e0(int obj);
extern int FUN_00065104(int obj, int idx, int sub);
extern int FUN_0006517c(int obj, int idx, int sub);
extern void FUN_002803d8(char *fmt, ...);
extern void FUN_000545bc(struct Vec_280188 *vec, int *val, Tag_280188 flag);
extern void FUN_00054600(struct Vec_280188 *vec, int flag);
extern unsigned FUN_0001342c(void);
extern unsigned char FUN_0000d62c(int v);
}

extern "C" int FUN_00280188(int *table, unsigned char *out, int key, int sub, False_280188)
{
    struct Vec_280188 listA;
    struct Vec_280188 listB;
    int i, count;
    int valA, valB, result;
    unsigned matches, pick;

    listA.data = 0;
    listA.size = 0;
    listA.capacity = 0;
    listB.data = 0;
    listB.size = 0;
    listB.capacity = 0;
    if (listA.capacity < 0x20)
        FUN_00286490(&listA, 0x20);
    if (listB.capacity < 0x20)
        FUN_00286490(&listB, 0x20);

    i = 0;
    count = FUN_000650e0(*table);
    while (i < count) {
        FUN_002803d8("%d:%s\n", FUN_00065104(*table, i, 0),
                     FUN_0006517c(*table, i, sub + 2));
        if (key == FUN_00065104(*table, i, 0)) {
            valA = FUN_0006517c(*table, i, sub + 2);
            if (listA.size < listA.capacity) {
                listA.size = listA.size + 1;
                *(int *)((char *)listA.data + listA.size * 4 - 4) = valA;
            } else {
                FUN_000545bc(&listA, &valA, Tag_280188());
            }
            valB = FUN_0006517c(*table, i, 1);
            if (listB.size < listB.capacity) {
                listB.size = listB.size + 1;
                *(int *)((char *)listB.data + listB.size * 4 - 4) = valB;
            } else {
                FUN_000545bc(&listB, &valB, Tag_280188());
            }
        }
        i++;
        count = FUN_000650e0(*table);
    }

    matches = listA.size;
    if (matches == 0 || listB.size == 0) {
        FUN_00054600(&listB, 0);
        FUN_00054600(&listA, 0);
        return 0;
    }
    {
        pick = FUN_0001342c() % matches;
        *out = FUN_0000d62c(listB.data[pick] + 5);
        result = listA.data[pick];
        FUN_00054600(&listB, 0);
        FUN_00054600(&listA, 0);
        return result;
    }
}
