#include <iostream>
#include <stdint.h>
#include <optional>
#include <bitset>

std::optional<uint32_t> ConvertFloatBitsToUint(float n){
    return (uint32_t)(*(uint32_t*)&n);
}

std::optional<float> ConvertBitsToFloat(uint32_t n){
    return (float)(*(float*)&n);
}

uint32_t ALU_Adder(uint32_t a, uint32_t b){
    return a + b;
}

int main(){

    float f1 {2.5f} ;
    float f2  {2.9f} ;

    //uint32_tは符号なし３２ビットの整数
    std::optional<uint32_t> bit1 {ConvertFloatBitsToUint(f1)};
    std::optional<uint32_t> bit2 {ConvertFloatBitsToUint(f2)};

    int a, b;
    if(bit1 && bit2){
        std::cout << f1 << ':' << std::bitset<32>(bit1.value()) << std::endl;
        a = bit1.value();

        std::cout << f2 << ':' << std::bitset<32>(bit2.value()) << std::endl;
        b = bit2.value();
    }

    float answer {f1 + f2};
    uint32_t result   {ALU_Adder(a, b)};

    std::cout << std::bitset<32>(result) << std::endl;
    
    std::optional<float> f3 {ConvertBitsToFloat(result)};
    std::optional<uint32_t> bit3 {ConvertFloatBitsToUint(f3.value())};

    if(f3){
        std::cout << "正しい答え: " << answer << std::endl;
        std::cout << "計算結果: " << f3.value() << "(" << std::bitset<32>(bit3.value()) << ")"<<std::endl;   
    }
}