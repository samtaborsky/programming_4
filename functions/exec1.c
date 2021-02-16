#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bc1 6                       // comb(k)
#define bc2 2                       // comb(n)
#define dig_sum -23456              // sumOfDigits()
#define rev_num -23456              // reverseNumber()
#define str_count "AaBbCcDdEe"      // countVowels()
#define prime 89                    // isPrime()
#define pass "Abcdefghi2021##"      // isPasswordStrong()

//-----------------------------------------------
// the function calculates the binomial coefficient C(n,k)
// Example: comb(6,2) should return 15

long comb(int n, int k) {
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;

    return comb(n - 1, k - 1) + comb(n - 1, k);
}

//-----------------------------------------------
// the function returns the sum of all digits - the sum is a non-negative value for both,
// positive and negative numbers
// Example: sumOfDigits(-23456) should return 20 (= 2 + 3 + 4 + 5 + 6)

int sumOfDigits(long long int number) {
    int mod, sum = 0;
    if (number < 0) {
        number = llabs(number);
    }
    while (number > 0) {
        mod = number % 10;
        sum += mod;
        number /= 10;
    }
    return sum;
}

//-----------------------------------------------
// the function returns a number with digits in the reversed order (respecting the sign of the input),
// Example: reverseNumber(-23456) should return -65432, reverseNumber(100) should return 1 (=001)

int reverseNumber(int number) {
    int mod, reverse = 0;
    while (number != 0) {
        mod = number % 10;
        reverse = reverse * 10 + mod;
        number /= 10;
    }
    return reverse;
}

//-----------------------------------------------
// the function counts vowels in the piece of text
// Example: countVowels("AaBbCcDdEe") should return 4

int countVowels(char text[]){
    int pos = 0, count = 0;
    do {
        if (text[pos] == 'a' || text[pos] == 'A' || text[pos] == 'e' || text[pos] == 'E' || text[pos] == 'i' ||
            text[pos] == 'I' || text[pos] =='o' || text[pos] =='O' || text[pos] == 'u' || text[pos] == 'U') {
            count++;
        }
        pos++;
    }
    while (text[pos] != '\0');
    return count;
}

//-----------------------------------------------
// the function should return one of two values - one of them indicates the number is a prime,
// the other one a composite number

int isPrime(int number) {
    int check = 0;
    for (int i = 2; i < number / 2; ++i) {
        if (number % i == 0) {
            check = 1;
            break;
        }
    }
    if (number == 1) {
        return 1; // neither prime nor non-prime, but returns 1 as non-prime
    }
    else {
        if (check == 1) {
            return 1; // number is non-prime
        }
        else {
            return 0; // number is prime
        }
    }
}

//-----------------------------------------------
// the function should check, if a password is strong enough. A strong password:
// - must be 15 characters long or more,
// - must contain 3 out of 4 types characters: lowercase letters, uppercase letters, digits, other symbols
// The return value should indicate one of 4 possible values - the first one would mean "Strong",
// the second one "Not long enough", the third one "Two or less types of characters used", the fourth one would be
// a combination of the second and third situation. The function must not display any message.

int isPasswordStrong(char password[]) {
    int types = 0, pos = 0, upper = 0, lower = 0, dig = 0, other = 0;
    do {
        if (password[pos] >= 97 && password[pos] <= 122) {
            lower = 1;
        }
        else if (password[pos] >= 65 && password[pos] <= 90) {
            upper = 1;
        }
        else if (password[pos] >= 48 && password[pos] <= 57) {
            dig = 1;
        }
        else if ((password[pos] >= 33 && password[pos] <= 47) || (password[pos] >= 58 && password[pos] <= 64) ||
                 (password[pos] >= 91 && password[pos] <= 96) || (password[pos] >= 123 && password[pos] <= 126)) {
            other = 1;
        }
        pos++;
    }
    while (password[pos] != '\0');
    types = lower + upper + dig + other;

    if (strlen(password) >= 15 && types >= 3) {
        return 0; // strong
    }
    else if (strlen(password) < 15 && types >= 3) {
        return 1; // not long enough
    }
    else if (strlen(password) >= 15 && types < 3) {
        return 2; // not enough char types
    }
    else if (strlen(password) < 15 && types < 3) {
        return 3; // not long enough + not enough char types
    }
}

int main(void) {
    // for testing, please edit the values in the definitions section

    printf("comb(%d, %d) = %ld\n", bc1, bc2, comb(bc1, bc2));
    printf("sumOfDigits(%d) = %d\n", dig_sum, sumOfDigits(dig_sum));
    printf("reverseNumber(%d) = %d\n", rev_num, reverseNumber(rev_num));
    printf("countVowels(%s) = %d\n", str_count, countVowels(str_count));

    int n = isPrime(prime);
    if (n == 0) {
        printf("%d is prime\n", prime);
    }
    else if (n == 1) {
        printf("%d is non-prime or 1\n", prime);
    }

    int p = isPasswordStrong(pass);
    if (p == 0) {
        printf("%s is strong\n", pass);
    }
    else if (p == 1) {
        printf("%s is not long enough\n", pass);
    }
    else if (p == 2) {
        printf("%s is not enough char types\n", pass);
    }
    else if (p == 3) {
        printf("%s is not long enough + not enough char types\n", pass);
    }

    return 0;
}