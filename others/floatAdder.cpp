/*論回でつくったALUの加算機にそのまま浮動小数点を突っ込んでみる。
 *当然、仮数部から指数部（E -> Sも）への桁上げが発生すること、指
 *数部の多きさによって仮数部の重みが違うことから、正しい演算結果
 *は得られない 
 */


#include <iostream>
#include <stdint.h>
#include <optional>
#include <bitset>
#include <string>
#include <sstream>
#include <algorithm>

std::optional<uint32_t> ConvertFloatBitsToUint(float n){
    return (uint32_t)(*(uint32_t*)&n);
}

std::optional<float> ConvertBitsToFloat(uint32_t n){
    return (float)(*(float*)&n);
}

std::string ToString(uint32_t s, uint32_t e, uint32_t m){ 
    std::stringstream ss;
    ss << std::bitset<1>(s) << std::bitset<8>(e) << std::bitset<23>(m);

    return ss.str();
}

uint32_t ALU_Adder(uint32_t a, uint32_t b){
    return a + b;
}

uint32_t FixedALU_Adder(uint32_t a, uint32_t b){
    
    if(a < b) std::swap(a, b);

    uint32_t sign, exp, mantissa;
    uint32_t sign2, exp2, mantissa2;


    sign = a >> 31;
    sign2 = b >> 31;


    exp = (a << 1) >> 24;
    exp2 = (b << 1) >> 24;

    int shiftCount = 0;
    while(exp != exp2){
        ++exp2;
        ++shiftCount;
    }

    mantissa = (a << 9) >> 9;

    mantissa2 = (b << 9) >> 9;
    mantissa2 = mantissa2 >> shiftCount;

    //符号を直さないと
    //std::cout << std::bitset<23>(mantissa2);
    uint32_t res = std::stoull(ToString(sign, exp, (mantissa + mantissa2)), nullptr, 2);
    std::cout << std::bitset<23>(mantissa) << std::endl;
    std::cout << std::bitset<23>(mantissa2) << std::endl;

    //this works, but why?
    uint32_t offset = 0b1;
    offset = offset << (23 - shiftCount);

    return res + offset;
}

int main(){

    float f1 {170.523f} ;
    float f2  {1.9f} ;

    //uint32_tは符号なし３２ビットの整数
    std::optional<uint32_t> bit1 {ConvertFloatBitsToUint(f1)};
    std::optional<uint32_t> bit2 {ConvertFloatBitsToUint(f2)};

    int a, b;
    if(bit1 && bit2){
        std::cout << f1 << ':' << std::bitset<32>(bit1.value()) << std::endl;
        a = bit1.value();

        std::cout << f2 << ":   " << std::bitset<32>(bit2.value()) << std::endl;
        b = bit2.value();
    }

    float answer {f1 + f2};

    //this is intentionally wrong
    uint32_t result   {FixedALU_Adder(a, b)};
    
    std::optional<float> f3 {ConvertBitsToFloat(result)};
    std::optional<uint32_t> bit3 {ConvertFloatBitsToUint(f3.value())};

    if(f3 && bit3){
       std::cout << "正しい答え: " << answer << "(" << std::bitset<32>(ConvertFloatBitsToUint(answer).value()) << ")"<<std::endl;
       std::cout << "計算結果:   " << f3.value() << "(" << std::bitset<32>(bit3.value()) << ")"<<std::endl;   
    }
}