#include <cstdio>

typedef unsigned int uint;

class World
{
private:
    uint x = 0, z = 0, b = 0;
    uint **blocks = nullptr;

public:
    World(uint ix, uint iz, uint ib)
    {
        this->x = ix;
        this->z = iz;
        this->b = ib;
        this->blocks = new uint *[this->x]();
        for (uint dx = 0; dx < this->x; dx++)
            this->blocks[dx] = new uint[this->z]();
    }
    void setHeight(uint x, uint z, uint y) { this->blocks[x][z] = y; }
    uint getHeight(uint x, uint z) { return this->blocks[x][z]; }
    uint totalBlocks()
    {
        uint result = 0;
        for (uint dx = 0; dx < x; dx++)
            for (uint dz = 0; dz < z; dz++)
                result = result + this->blocks[x][z];
        return result;
    }
    // bool isFlattable(uint targetHeight)
    // {
    //     long block = b;
    //     for (int dx = 0; dx < x; dx++)
    //         for (int dz = 0; dz < z; dz++)
    //             if (blocks[dx][dz] >= targetHeight)
    //                 block = block + (blocks[dx][dz] - targetHeight);
    //             else
    //                 block = block - (targetHeight - blocks[dx][dz]);
    //     return block >= 0;
    // }
    long flatWorldTime(uint targetHeight)
    {
        long time = 0;
        long block = b;
        for (int dx = 0; dx < x; dx++)
            for (int dz = 0; dz < z; dz++)
                if (blocks[dx][dz] >= targetHeight)
                {
                    block = block + (blocks[dx][dz] - targetHeight);
                    time = time + (2 * (blocks[dx][dz] - targetHeight));
                }
                else
                {
                    block = block - (targetHeight - blocks[dx][dz]);
                    time = time + (targetHeight - blocks[dx][dz]);
                }
        return block >= 0 ? time : -1;
    }
};

int main(void)
{
    uint n = 0, m = 0, b = 0;
    scanf("%u %u %u", &n, &m, &b);
    World w(n, m, b);
    for (uint x = 0; x < n; x++)
        for (uint z = 0, input = 0; z < m; z++)
        {
            scanf("%u", &input);
            w.setHeight(x, z, input);
        }
    long minTime = -1;
    uint maxHeight = 0;
    for (uint y = 0; y <= 256; y++)
    {
        long expTime = w.flatWorldTime(y);
        if (expTime == -1)
            break;
        if (expTime <= minTime || minTime == -1)
        {
            minTime = expTime;
            maxHeight = y;
        }
    }
    printf("%ld %u\n", minTime, maxHeight);
    return 0;
}