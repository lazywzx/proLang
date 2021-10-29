#include<iostream>

// 统计输入连续值的个数

int main()
{
    std::cout << "Enter some numbers: " << std::endl;

    // currVal: 保存当前值；Val: 保存新输入的值
    int currVal = 0, Val = 0;
    if (std::cin >> currVal)
    {
        int cnt = 1;    // 计数当前值
        while (std::cin >> Val)
        {
            if (Val == currVal)
            {
                ++cnt;
            }
            else
            {
                std::cout << currVal << " occurs " << cnt 
                          << " times." << std::endl;
                currVal = Val;  // 保存新值
                cnt = 1;    // 复位计数器
            }
        }
        std::cout << currVal << " occurs " << cnt 
                  << " times." << std::endl;
    }

    return 0;
}
