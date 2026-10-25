/* HSTMATCH module=EBOOT.BIN start=0x0001d3ac end=0x0001d594 symbol=FUN_0001d3ac lang=c99 */
extern float sqrtf(float);

void FUN_0001d3ac(float *q, float *m)
{
    float m00 = m[0];
    float m11 = m[5];
    float m22 = m[10];
    float t = m22 + m00 + m11;
    float x;
    float y;
    float z;
    float w;

    if (t >= 0.0f) {
        float s = sqrtf(t + 1.0f);
        w = s * 0.5f;
        float d = 0.5f / s;
        y = d * (m[2] - m[8]);
        z = d * (m[4] - m[1]);
        x = d * (m[9] - m[6]);
    } else {
        float f = m00;
        if (m00 <= m11)
            f = m11;
        if (f <= m22)
            f = m22;
        if (f == m00) {
            float s = sqrtf((m00 - (m11 + m22)) + 1.0f);
            w = s * 0.5f;
            float d = 0.5f / s;
            y = d * (m[1] + m[4]);
            z = d * (m[8] + m[2]);
            x = d * (m[9] - m[6]);
        } else if (f == m11) {
            float s = sqrtf((m11 - (m22 + m00)) + 1.0f);
            z = s * 0.5f;
            float d = 0.5f / s;
            x = d * (m[6] + m[9]);
            w = d * (m[1] + m[4]);
            y = d * (m[2] - m[8]);
        } else {
            float s = sqrtf((m22 - (m00 + m11)) + 1.0f);
            w = s * 0.5f;
            float d = 0.5f / s;
            x = d * (m[8] + m[2]);
            y = d * (m[6] + m[9]);
            z = d * (m[4] - m[1]);
        }
    }
    q[0] = x;
    q[1] = y;
    q[2] = z;
    q[3] = w;
}
// near miss from lane fm11 (unreviewed)
