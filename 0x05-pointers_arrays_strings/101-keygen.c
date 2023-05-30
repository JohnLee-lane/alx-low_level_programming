#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 61

char *generate_password() {
    char *password = malloc(sizeof(char) * PASSWORD_LENGTH);
    int i, random_value;

    srand(time(NULL)); /* Initialize random number generator with current time */

    for (i = 0; i < PASSWORD_LENGTH - 1; i++) {
        random_value = rand() % 62; /* Generate random number from 0 to 61 */
        if (random_value < 26) {
            password[i] = 'a' + random_value; /* Map value to lowercase letter */
        } else if (random_value < 52) {
            password[i] = 'A' + (random_value - 26); /* Map value to uppercase letter */
        } else {
            password[i] = '0' + (random_value - 52); /* Map value to digit */
        }
    }

    password[PASSWORD_LENGTH - 1] = '\0'; /* Add null terminator */

    return password;
}

int main(void) {
    char *password = generate_password();
    printf("%s", password);
    free(password);
    return 0;
}
