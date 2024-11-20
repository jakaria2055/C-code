#include <stdio.h>

// Function to find the length of a char array
int a_length(char array[]) {
    int count = 0;
    while (array[count] != '\0') {
        count++;
    }
    return count;
}

// Function to check if the bit stream has an odd number of 1s
int has_odd_parity(char array[]) {
    int length = a_length(array);
    int count = 0;
    
    for (int i = 0; i < length; i++) {
        if (array[i] == '1') {
            count++;
        }
    }
    
    // Odd parity check: true if count of 1's is odd
    return count % 2 != 0;
}

int main() {
    char data[100];
    
    // Taking bit stream input from user
    printf("Enter the bit stream: ");
    scanf("%s", data);
    
    // Check if bit stream has odd parity
    if (has_odd_parity(data)) {
        printf("The bit stream has odd parity. No error detected.\n");
    } else {
        printf("The bit stream does not have odd parity. Error detected.\n");
    }

    return 0;
}
