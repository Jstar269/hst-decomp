/* Vertex batch written by the textured-quad effect sources, and the entry kind that marks a finished effect. */
#ifndef HST_FADE_QUADS_H
#define HST_FADE_QUADS_H

#define QUAD_KIND_DEAD 6 /* kind value of an entry that is finished and skipped */
#define QUAD_VERTS 4     /* vertices written per entry */

typedef struct QuadVert {
    unsigned char r, g, b, a;
    float x, y, z;
    float u, v, q;
} QuadVert; /* size 0x20 */

/* Double-buffered vertex batch: idx selects the buffer being filled. */
typedef struct QuadBatch {
    char pad[0x54];
    int idx;           /* 0x54 */
    char pad58[0xc];
    QuadVert *buf[2];  /* 0x64 */
} QuadBatch;

#endif
