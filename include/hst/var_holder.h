/* Object that carries a script variable block at 0xf0 (the accessors return a slot pointer for the block). */
#ifndef HST_VAR_HOLDER_H
#define HST_VAR_HOLDER_H

typedef struct VarHolder {
    char pad00[0xf0];
    char vars[4];       /* 0xf0 start of the variable block */
} VarHolder;

#endif
