#include "Crypto_Primitives.h"
#include "MultisetAccumulator.h"
#include "BigInteger.h"
#include <iostream>
#include <chrono>
using namespace std;

int main(){
    MultisetAccumulator Acc;

    /* 功能测试 */
    Acc.update_acc_pow("1",1);
    Acc.update_product("1",1);

    Acc.update_acc_pow("2",1);
    Acc.update_product("2",1);

    Acc.update_acc_pow("3",1);
    Acc.update_product("3",1);
    std::string pi = Acc.proove_membership_prime("3");

    if(Acc.verify_membership(pi, "3")){
        std::cout << "true" << std::endl;
    }else{
        std::cout << "false" << std::endl;
    }

    if(Acc.update_product("3",0)){
        Acc.update_acc_pow("3",0);
        pi = Acc.proove_membership_prime("3");

        if(Acc.verify_membership(pi, "3")){
            std::cout << "true" << std::endl;
        }else{
            std::cout << "false" << std::endl;
        }
    }

    /* 时间测试 */
    // BigInteger product(1);
    // int g=13;
    // std::string N="92540059651567610024194486489383252364422717166295481558146780071654243501741";

    // for(int i=0;i<100000;i++){
    //     auto start_p = std::chrono::high_resolution_clock::now();
    //     BigInteger p;
    //     BigInteger::generate_prime(p, std::to_string(i));
    //     auto end_p = std::chrono::high_resolution_clock::now();
    //     auto duration_p = std::chrono::duration_cast<std::chrono::microseconds>(end_p - start_p).count();


    //     auto start_m = std::chrono::high_resolution_clock::now();
    //     BigInteger::mul(product, product, p);
    //     auto end_m = std::chrono::high_resolution_clock::now();
    //     auto duration_m = std::chrono::duration_cast<std::chrono::microseconds>(end_m - start_m).count();

    //     auto start_e = std::chrono::high_resolution_clock::now();
    //     BigInteger G(g);
    //     BigInteger Acc;
    //     BigInteger n(N);
    //     BigInteger::mod_exp(Acc, G, product, n);
    //     auto end_e = std::chrono::high_resolution_clock::now();
    //     auto duration_e = std::chrono::duration_cast<std::chrono::microseconds>(end_e - start_e).count();

    //     if (i % 1000 == 0){
    //         std::cout << "index: " << i << std::endl;
    //         std::cout << "P Execution time: " << duration_p << " microseconds" << std::endl;
    //         std::cout << "M Execution time: " << duration_m << " microseconds" << std::endl;
    //         std::cout << "E Execution time: " << duration_e << " microseconds" << std::endl;
            
    //         std::cout << "Product length: " << product.to_string().length() << std::endl;  
    //     }
        
    // }

    return 0;
}
