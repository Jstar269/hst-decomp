/* Script command objects (0x14d000 range): node base, set-variable command, variable blocks and the run context. */
#ifndef HST_SCRIPT_NODE_H
#define HST_SCRIPT_NODE_H

#include "hst/types.h"

/* Number of int (and of float) variables in a ScriptVars block. */
#define SCRIPT_VAR_COUNT 64

/* Variable class selected by the 4-bit type field of a set-variable command. */
enum {
    VAR_KIND_INT_A = 0,   /* int through accessor FUN_0022a940 */
    VAR_KIND_FLOAT_A = 1, /* float through accessor FUN_0022a958 */
    VAR_KIND_INT_B = 2,   /* int through accessor FUN_0022a970 */
    VAR_KIND_FLOAT_B = 3, /* float through accessor FUN_0022a98c */
    VAR_KIND_LOCAL_INT = 4,
    VAR_KIND_LOCAL_FLOAT = 5,
    VAR_KIND_GLOBAL_INT = 8,
    VAR_KIND_GLOBAL_FLOAT = 9
};

typedef union ScriptValue {
    int i;
    float f;
} ScriptValue;

/* Common base of every command object: vtable pointer plus a byte cleared by the base constructor. */
typedef struct ScriptNode {
    const void *vtable; /* 0x00 */
    u8 unk04;           /* 0x04, padded to 8 bytes */
} ScriptNode;

/* Node carrying one float. */
typedef struct FloatNode {
    ScriptNode base; /* 0x00 */
    float value;     /* 0x08 */
} FloatNode;

/* Set-variable command read from a stream: class (type), variable index and the value to store. */
typedef struct VarCmd {
    ScriptNode base;     /* 0x00 */
    int type;            /* 0x08, VAR_KIND_* */
    int index;           /* 0x0c */
    ScriptValue value;   /* 0x10 */
} VarCmd;

/* Local variable block: ints then floats. */
typedef struct ScriptVars {
    char pad00[0xc];
    int ints[SCRIPT_VAR_COUNT];     /* 0x0c */
    float floats[SCRIPT_VAR_COUNT]; /* 0x10c */
} ScriptVars;

/* Run context: local variables and the nesting depth used to indent the debug log. */
typedef struct ScriptRunCtx {
    ScriptVars *vars; /* 0x00 */
    char pad04[8];
    int unk0c;        /* 0x0c */
    char pad10[8];
    int depth;        /* 0x18 */
} ScriptRunCtx;

#endif
