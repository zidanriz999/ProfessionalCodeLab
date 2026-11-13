
#include <stdio.h>
#include <string.h>

int main() {
    char exp[100];
    int stack[100], top = -1;
    int value[26] = {0}, used[26] = {0};
    int i, a, b, result, x;

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++) {

      
        if (exp[i] >= 'a' && exp[i] <= 'z') {
            x = exp[i] - 'a';

            if (!used[x]) {
                printf("Enter the value of %c: ", exp[i]);
                scanf("%d", &value[x]);
                used[x] = 1;
            }

            stack[++top] = value[x];
        }

               else if (exp[i] >= '0' && exp[i] <= '9') {
            stack[++top] = exp[i] - '0';
        }

  
        else {
            b = stack[top--];
            a = stack[top--];

            switch (exp[i]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;

                case '^':
                    result = 1;
                    for (int j = 0; j < b; j++)
                        result *= a;
                    break;
            }

            stack[++top] = result;
        }
    }

    printf("Output = %d\n", stack[top]);

    return 0;
}
