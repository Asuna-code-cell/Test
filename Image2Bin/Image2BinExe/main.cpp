#include <iostream>
#include <windows.h>
#include "../Image2BinLib/Image2BinLib.h"

int wmain(int argc, wchar_t* argv[])
{
    if (argc != 2)
    {
        std::wcout << L"用法: Image2BinExe order.xml\n";
        return 0;
    }
    // 1. 读 order.xml 得到输入/输出路径
    //    同样用“假代码”占位，先把路径写死
    const wchar_t* tifPath = L"D:\\VS----code\\Image2Bin\\bin\\test.tif";
    const wchar_t* binPath = L"D:\\VS----code\\Image2Bin\\bin\\test.dat";

    // 2. 读图像
    int w, h;
    unsigned short* img = Img_ReadTiff12(tifPath, &w, &h);
    if (!img)
    {
        std::wcout << L"读图失败\n";
        return 1;
    }
    std::wcout << L"图像尺寸: " << w << L" x " << h << std::endl;

    // 3. 写二进制
    if (Img_WriteBin12(binPath, img, w, h))
        std::wcout << L"生成成功: " << binPath << std::endl;
    else
        std::wcout << L"写文件失败\n";

    delete[] img;
    return 0;
}