#include<stdio.h>
#define MAX 40

typedef enum{lparen, rparen, plus, minus, times, divide, mod, eos, operand} precedence;
char EXPR[MAX];
float stack[20];
int top = -1;

precedence get_token(char *symbol, int *n) {
    *symbol = EXPR[(*n)++];
    switch (*symbol) {
        case '(': return lparen;
        case ')': return rparen;
        case '+': return plus;
        case '-': return minus;
        case '*': return times;
        case '/': return divide;
        case '%': return mod;
        case '\0': return eos;
        default: return operand;
    }
}

void push(float num) {
    stack[++top] = num;
}

float pop() {
    return stack[top--];
}

float eval() {
    precedence token;
    char symbol;
    float op1, op2;
    int n = 0;
    token = get_token(&symbol, &n);
    while (token != eos) {
        if (token == operand)
            push(symbol - '0');
        else {
            op2 = pop();
            op1 = pop();
            switch (token) {
                case plus:
                    push(op1 + op2);
                    break;
                case minus:
                    push(op1 - op2);
                    break;
                case times:
                    push(op1 * op2);
                    break;
                case divide:
                    push(op1 / op2);
                    break;
                case mod:
                    push((int)op1 % (int)op2);
                    break;
            }
        }
        token = get_token(&symbol, &n);
    }
    return pop();
}

int main() {
    float res;
    printf("\nEnter the postfix expression\n");
    scanf("%s", EXPR);
    res = eval();
    printf("\nAfter evaluation:\t%.2f\n", res);

    return 0;
}
