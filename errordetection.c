#include <stdio.h>

int main() {
    char data[100];
  
    printf("Enter the data: ");
    scanf("%s", data);

    // Calculate the length of the input data and count the number of '1's
    int length = 0;
    int count = 0;
    while (data[length] != '\0') {
        if (data[length] == '1') {
            count++;
        }
        length++;
    }

    // Adding parity bit for odd parity
    if (count % 2 == 0) { // If the number of 1s is even, we need to add 1 to make it odd
        for (int i = length; i >= 0; i--) {
            data[i + 1] = data[i];
        }
        data[0] = '1';
        
        printf("After adding '1' at the front of the data for odd parity: \n");
        printf("%s\n", data);
    } else { // If the number of 1s is already odd, we add 0 to keep it odd
        for (int i = length; i >= 0; i--) {
            data[i + 1] = data[i];
        }
        data[0] = '0';
        
        printf("After adding '0' at the front of the data for odd parity: \n");
        printf("%s\n", data);
    }

    return 0;
}
