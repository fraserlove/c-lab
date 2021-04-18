#include "Calculator.h"

#include <stdio.h>

int main() {
    char expr[MAX_EXPR_SIZE];

    scanf("%[0-9e.+-*/ ]", expr);
    Calculator RPNCalc = newCalculator(expr);
    printf("%.2f\n", evaluateExpression(RPNCalc));
    destroyCalculator(RPNCalc);
    return 0;
}