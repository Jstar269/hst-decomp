/* Read cursor over a byte stream, advanced by the small reader helpers. */
#ifndef HST_STREAM_CURSOR_H
#define HST_STREAM_CURSOR_H

typedef struct StreamCursor {
    const unsigned char *pos; /* 0x0, next byte to read */
} StreamCursor;

#endif
