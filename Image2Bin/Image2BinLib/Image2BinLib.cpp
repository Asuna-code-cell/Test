#include "pch.h"
#include "Image2BinLib.h"
#include <fstream>
#include <vector>

unsigned short* Img_ReadTiff12(const wchar_t* filePath, int* width, int* height)
{
    // 零基础可直接用现成的 tinytiff 或 libtiff，这里先用“假读取”占位，
    // 保证能编译通过。后续把老师给的 test.tif 读进来即可。
    *width = 3072;
    *height = 10000;
    auto* buf = new unsigned short[*width * *height];
    // TODO: 调用 TIFFOpen / TIFFReadEncodedStrip 等真正读取
    return buf;
}

unsigned short Img_GetPixel(unsigned short* img, int width, int row, int col)
{
    return img[row * width + col];
}

bool Img_WriteBin12(const wchar_t* filePath, unsigned short* img, int width, int height)
{
    std::ofstream fs(filePath, std::ios::binary);
    if (!fs) return false;

    for (int i = 0; i < width * height; )
    {
        // 每次取 2 个 12bit 像素，拼成 3 字节
        unsigned short p0 = img[i++];
        unsigned short p1 = (i < width * height) ? img[i++] : 0;

        unsigned char b[3];
        b[0] = static_cast<unsigned char>(p0 & 0xFF);
        b[1] = static_cast<unsigned char>(((p0 >> 8) & 0x0F) | ((p1 & 0x0F) << 4));
        b[2] = static_cast<unsigned char>((p1 >> 4) & 0xFF);

        fs.write(reinterpret_cast<char*>(b), 3);
    }
    return true;
}