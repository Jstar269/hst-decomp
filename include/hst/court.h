/* Court object: two polymorphic bases followed by state words and a set of growable arrays. */
#ifndef HST_COURT_H
#define HST_COURT_H

#include "hst/vec_reserve.h"

typedef struct Court {
    void *vptr;                 /* 0x0000 */
    char base0[0x3c];
    void *vptr1;                /* 0x0040: second base */
    char base1[0x1360 - 0x44];
    int unk1360;
    int mode;                   /* 0x1364 */
    unsigned char unk1368;
    int unk136c;
    int unk1370[5];
    int unk1384[2];
    RawVec vec138c;             /* 0x138c */
    RawVec vec1398;             /* 0x1398 */
    RawVec vec13a4;             /* 0x13a4 */
    RawVec vec13b0;             /* 0x13b0 */
    RawVec vec13bc;             /* 0x13bc */
    unsigned char unk13c8;
    RawVec vec13cc;             /* 0x13cc */
    RawVec vec13d8;             /* 0x13d8 */
    RawVec vec13e4;             /* 0x13e4 */
    RawVec vec13f0;             /* 0x13f0 */
    RawVec list13fc;            /* 0x13fc: 4-byte elements */
    RawVec vec1408;             /* 0x1408 */
    unsigned char unk1414;
    unsigned char unk1415;
    int unk1418;
    unsigned char unk141c;
    unsigned char unk141d;
    unsigned char unk141e;
    unsigned char unk141f;
    char pad1420[0xc];
    unsigned char unk142c;
    RawVec list1430;            /* 0x1430: 16-byte elements */
    int unk143c;
    unsigned char unk1440;
    int unk1444;
    int unk1448;
    int unk144c;
    RawVec vec1450;             /* 0x1450 */
    int unk145c;
    char pad1460[0x50];
    unsigned char unk14b0;
    unsigned char unk14b1;
    unsigned char unk14b2;
    int unk14b4;
} Court;

#endif
