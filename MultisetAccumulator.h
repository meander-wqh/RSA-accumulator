#ifndef MULTISETACCUMULATOR_H
#define MULTISETACCUMULATOR_H

#include <pbc/pbc.h>
#include<string>
#include <set>



/*
    储存不相交证明。
*/
struct Nonmembership_Proof{
    // a
    std::string a;
    // d=g^b mod N
    std::string d;
};


/*
    RSA累加器
*/
class MultisetAccumulator{
public:
    MultisetAccumulator();

    /*
        对于给定的关键字集合，生成ACC

        param:
            w_set: 关键字的明文集合

        return:
            acc的十进制字符串形式
    */
    std::string get_acc(std::set<std::string> w_set);


    /*
        对于给定的x_p，生成ACC

        param:
            x_p: 集合对应的product

        return:
            acc的十进制字符串形式
    */
    std::string get_acc(std::string x_p);


    /*
        对于给定的关键字集合，计算对应素数的乘积

        param:
            w_set: 关键字的明文集合

        return:
            对应素数的乘积
    */
    std::string get_product(std::set<std::string> w_set);


    /*
        证明某关键字x不存在于某个集合(不存在证明)

        param:
            product:集合对应素数的乘积，十进制字符串形式
            x:关键字的明文
    */
    struct Nonmembership_Proof proove_nonmembership(std::string product,std::string w);

    struct Nonmembership_Proof proove_nonmembership_prime(std::string product,std::string x_s);


    /*
        证明某元素x存在于某个集合(存在证明)

        param:
            x:需要进行检测的元素
    */

   std::string proove_membership_prime(std::string x);


    /*
        给定从服务器获取的acc，不相交证明pi，验证关键字w不属于集合

        param:
            acc:
            pi:
            w:
        return:
            若w不属于集合，返回true。否则返回false
    */
    bool verify_nonmembership(std::string acc,struct Nonmembership_Proof pi,std::string w);

    /*
        param:
            pi: 证明proof
            x: 需要验证的元素 

        return:
            若w属于集合，返回true。否则返回false
    */
    bool verify_membership(std::string proof, std::string x);

    /*
        使用欧拉降幂公式计算 a^x mod N

        param:
            a,x:十进制字符串
        
        return:
            结果，一个十进制字符串
    */
    std::string mod_exp_Euler(std::string a,std::string x);

    /*
        更新acc

        param:
            x:更新的元素，op=0:delete, op=1:delete
        
        return:
            acc, 结果，一个十进制字符串
    */

   void update_acc_pow(std::string x, int op);

   /*
        返回acc

        param:
            无
        return:
            acc
    */
   std::string get_acc();

    /*
        更新product

        param:
            x:更新的元素，op=0:delete, op=1:delete
        return:
            如果是去除元素，并且元素不存在于product中，那么返回false
    */

   bool update_product(std::string x, int op);




private:
    // 安全的素数P
    std::string P;
    //P-1
    std::string P_1;

    // 安全的素数Q
    std::string Q;
    //Q-1
    std::string Q_1;

    // 模数N=PQ
    std::string N;

    // Phi_N
    std::string Phi_N;

    // 生成元g
    unsigned long g;

    // 计算acc需要的pow
    std::string POW;

    // product
    std::string Product;
};


#endif