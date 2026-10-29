/* HSTMATCH module=EBOOT.BIN start=0x00204c88 end=0x00204f18 symbol=FUN_00204c88 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

#include "hst/chrsel_unit.h"

/* Attribute value meaning "leave this one alone". */
#define ATTR_UNSET 0x7fffffff

extern char DAT_0030ebf4;
extern char DAT_002ef624;
extern char DAT_002ef640;
extern char DAT_002ef644;
extern int DAT_002c9398[]; /* kind of each attribute slot */
extern int DAT_002ef520[]; /* name of each attribute slot, used in the load message */
static inline int Kind(const int *t, int i) { if (i >= 0 && i < CHRSEL_ATTR_COUNT) return t[i]; return 0; }

extern void FUN_00092c38(int, int);
extern int FUN_00092720(int, int, int, int, int);
extern void FUN_0001ca58(void *, ...);
extern unsigned char FUN_00092790(int, int, int, int, unsigned char);
extern void FUN_0001cb88(void *);
extern void FUN_00092d10(int, int);
extern void FUN_000931ec(int, int, void *, unsigned char);

/* Applies the six attribute ids of a unit to its object: loads each changed attribute, reports the results of
   kinds 0, 2 and 5 through the out bytes, then sets the object's flag bytes. */
void FUN_00204c88(int obj, unsigned char *out_kind0, unsigned char *out_kind2, unsigned char *out_kind5,
                  int *attrs, unsigned char byte_a, unsigned char byte_b, unsigned char byte_c,
                  int arg_a, int arg_b, unsigned char arg_c)
{
    unsigned char arg_c_copy;
    *out_kind0 = 0;
    *out_kind2 = 0;

    int i;
    int value;
    int kind;
    const int *kinds;
    const int *names;

    *out_kind5 = 0;

    i = 0;
    kinds = DAT_002c9398;
    names = DAT_002ef520;
    arg_c_copy = arg_c;
    for (; i < CHRSEL_ATTR_COUNT; i++) {
        kind = Kind(kinds, i);

        value = attrs[i];
        if (value == ATTR_UNSET) {
            continue;
        }

        if (value >= 0) {
            if (kind == 5) {
                value = value / 10;
            }
            if ((unsigned int)(kind - 3) < 2 && value == 0) {
                FUN_00092c38(obj, kind);
            }
            if (FUN_00092720(obj, kind, value, arg_a, 0) == 0) {
                FUN_0001ca58(&DAT_0030ebf4, &DAT_002ef624, names[i], names[i], value, &DAT_002ef640);
                unsigned char result = FUN_00092790(obj, kind, value, arg_a, arg_c_copy);
                if (kind == 2) {
                    *out_kind2 = result;
                } else if (kind == 0) {
                    *out_kind0 = result;
                } else if (kind == 5) {
                    *out_kind5 = result;
                }
                FUN_0001cb88(&DAT_0030ebf4);
            }
        } else {
            FUN_00092c38(obj, kind);
        }

        if (kind == 2 && arg_b != *(int *)(obj + 0x68)) {
            FUN_0001ca58(&DAT_0030ebf4, &DAT_002ef644, arg_b);
            FUN_00092d10(obj, arg_b);
            FUN_0001cb88(&DAT_0030ebf4);
        }
    }

    char pair[2] = {0};
    pair[0] = byte_a;
    pair[1] = byte_b;
    FUN_000931ec(obj, 1, pair, byte_c);
}

// The two table bases are locals assigned in the loop preheader (`kinds = DAT_002c9398; names = DAT_002ef520;`, kinds read
// through Kind(kinds, i)) between `i = 0;` and the arg_c copy: MWCC keeps statement order in the preheader, so the
// spilled copy's `sb v0,56(sp)` follows the two base `addiu`s as in retail. Reading the globals directly inside the loop
// lets loop-invariant motion append the bases AFTER the copy (3 words off), whatever position the copy has.
