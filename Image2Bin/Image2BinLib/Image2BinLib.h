#pragma once
#ifdef IMAGEBINLIB_EXPORTS
#  define IMAGEBIN_API __declspec(dllexport)
#else
#  define IMAGEBIN_API __declspec(dllimport)
#endif

// 读 12bit TIFF，返回灰度矩阵（每像素 unsigned short）
extern "C" IMAGEBIN_API unsigned short* Img_ReadTiff12(const wchar_t* filePath, int* width, int* height);

// 获取某像素（行主序）
extern "C" IMAGEBIN_API unsigned short Img_GetPixel(unsigned short* img, int width, int row, int col);

// 写压缩后的 12bit 数据（3字节/2像素）
extern "C" IMAGEBIN_API bool Img_WriteBin12(const wchar_t* filePath,
    unsigned short* img,
    int width,
    int height);
