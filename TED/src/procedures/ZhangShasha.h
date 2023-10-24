#ifndef ZHANGSHASHA_H
#define ZHANGSHASHA_H

#include <tree.h>

namespace ZhangShasha {
    /**
     * Computes the Tree Edit Distance (TED) between T1 and T2 using the dynamic 
     * programming algorithm described by ZhangShasha in 1989 in the paper 
     * Simple Fast Algorithms for the Editing Distance between Trees and Related Problems. 
     * 
     * It requires O(n^4) time.
    */
    int ted(const Tree& t1, const Tree& t2);
}

#endif