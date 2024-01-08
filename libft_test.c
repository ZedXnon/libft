/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwoidt <dwoidt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 21:20:36 by dwoidt            #+#    #+#             */
/*   Updated: 2024/01/07 21:20:36 by dwoidt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <string.h>


void print_memory(const void *memory, int size) {
    printf("Memory Content: ");
    for (int i = 0; i < size; i++) {
        printf("%02X ", ((unsigned char *)memory)[i]);
    }
    printf("\n");
}

int check_memory(const void *memory, int size, const void *expected_memory,
                 int (*compare)(const void *, const void *), const char * function_name) {
    int success = 1;
    for (int i = 0; i < size; i++) {
        if (!compare(&((unsigned char*)memory)[i], &((unsigned char*)expected_memory)[i])) {
            success = 0;
            printf("FAIL: %s - Incorrect value at index %d\n", function_name, i);
            printf("Expected: %02X, Actual: %02X\n", ((unsigned char*)expected_memory)[i],
                   ((unsigned char*)memory)[i]);
            print_memory(memory, size);
            break;
        }
    }
    return success;
}

int check_result(int actual, int expected, const char *function_name) {
    if (actual == expected) {
        return 1;
    } else {
        printf("FAIL: %s - (Expected: %d, Actual: %d)\n", function_name, expected, actual);
        return 0;
    }
}

int compare_char_ptr(const void *a, const void *b) {
    return (*(char **)a == *(char **)b);
}

int compare_char(const void *a, const void *b) {
    return (*(unsigned char *)a == *(unsigned char *)b);
}

// Test function for ft_isalpha
void ft_isalpha_test() {
    const char *function_name = "ft_isalpha";
    int success = 1;

    success &= check_result(ft_isalpha('a'), 1, function_name);
    success &= check_result(ft_isalpha('A'), 1, function_name);
    success &= check_result(ft_isalpha('z'), 1, function_name);
    success &= check_result(ft_isalpha('Z'), 1, function_name);
    success &= check_result(ft_isalpha('1'), 0, function_name);
    success &= check_result(ft_isalpha('\t'), 0, function_name);
    success &= check_result(ft_isalpha('\n'), 0, function_name);

    if (success) {
        printf("SUCCESS: %s\n", function_name);
    }
}

void ft_toupper_test() {
    const char *function_name = "ft_toupper";
    int success = 1;

    success &= check_result(ft_toupper('a'), 'A', function_name);
    success &= check_result(ft_toupper('A'), 'A', function_name);
    success &= check_result(ft_toupper('z'), 'Z', function_name);
    success &= check_result(ft_toupper('Z'), 'Z', function_name);
    success &= check_result(ft_toupper('1'), '1', function_name);
    success &= check_result(ft_toupper('\t'), '\t', function_name);
    success &= check_result(ft_toupper('\n'), '\n', function_name);

    if (success) {
        printf("SUCCESS: %s\n", function_name);
    }
}
// Test function for ft_isdigit
void ft_isdigit_test() {
    const char *function_name = "ft_isdigit";
    int success = 1;

    success &= check_result(ft_isdigit('0'), 1, function_name);
    success &= check_result(ft_isdigit('5'), 1, function_name);
    success &= check_result(ft_isdigit('9'), 1, function_name);
    success &= check_result(ft_isdigit('a'), 0, function_name);
    success &= check_result(ft_isdigit('A'), 0, function_name);
    success &= check_result(ft_isdigit('@'), 0, function_name);
    success &= check_result(ft_isdigit('\t'), 0, function_name);
    success &= check_result(ft_isdigit('\n'), 0, function_name);

    if (success) {
        printf("SUCCESS: %s\n", function_name);
    }
}

void ft_tolower_test() {
    const char *function_name = "ft_tolower";
    int success = 1;

    success &= check_result(ft_tolower('a'), 'a', function_name);
    success &= check_result(ft_tolower('A'), 'a', function_name);
    success &= check_result(ft_tolower('z'), 'z', function_name);
    success &= check_result(ft_tolower('Z'), 'z', function_name);
    success &= check_result(ft_tolower('1'), '1', function_name);
    success &= check_result(ft_tolower('\t'), '\t', function_name);
    success &= check_result(ft_tolower('\n'), '\n', function_name);

    if (success) {
        printf("SUCCESS: %s\n", function_name);
    }
}

void ft_isalnum_test() {
    const char *function_name = "ft_isalnum";
    int success = 1;

    success &= check_result(ft_isalnum('a'), 1, function_name);
    success &= check_result(ft_isalnum('5'), 1, function_name);
    success &= check_result(ft_isalnum('@'), 0, function_name);
    success &= check_result(ft_isalnum('\t'), 0, function_name);
    success &= check_result(ft_isalnum('\n'), 0, function_name);

    if (success) {
        printf("SUCCESS: %s\n", function_name);
    }
}

// Test function for ft_isascii
void ft_isascii_test() {
    const char *function_name = "ft_isascii";
    int success = 1;

    success &= check_result(ft_isascii('a'), 1, function_name);
    success &= check_result(ft_isascii(127), 1, function_name);
    success &= check_result(ft_isascii(128), 0, function_name);
    success &= check_result(ft_isascii('\t'), 1, function_name);
    success &= check_result(ft_isascii('\n'), 1, function_name);
	success &= check_result(ft_isascii(0), 1, function_name);

    if (success) {
        printf("SUCCESS: %s\n", function_name);
    }
}

// Test function for ft_isprint
void ft_isprint_test() {
    const char *function_name = "ft_isprint";
    int success = 1;

    success &= check_result(ft_isprint('a'), 1, function_name);
    success &= check_result(ft_isprint(32), 1, function_name);
    success &= check_result(ft_isprint(31), 0, function_name);
    success &= check_result(ft_isprint(127), 0, function_name);
	success &= check_result(ft_isprint(126), 1, function_name);
    success &= check_result(ft_isprint('\t'), 0, function_name);
    success &= check_result(ft_isprint('\n'), 0, function_name);

    if (success) {
        printf("SUCCESS: %s\n", function_name);
    }
}

// Test function for ft_strlen
void ft_strlen_test() {
    const char *function_name = "ft_strlen";
    int success = 1;

    success &= check_result(ft_strlen(""), 0, function_name);
    success &= check_result(ft_strlen("Hello"), 5, function_name);
    success &= check_result(ft_strlen("1234567890"), 10, function_name);

    if (success) {
        printf("SUCCESS: %s\n", function_name);
    }
}

void ft_memset_test() {
    const char *function_name = "ft_memset";
    char buffer[10];
    char expected_buffer[10];
	int success = 1;

    // Test case 1: Set buffer to 'A' (65 in ASCII)
    ft_memset(buffer, 'A', sizeof(buffer));
    memset(expected_buffer, 'A', sizeof(expected_buffer));
    success &= check_memory(buffer, sizeof(buffer), expected_buffer, compare_char, function_name);

    // Test case 2: Set buffer to 0
    ft_memset(buffer, 0, sizeof(buffer));
    memset(expected_buffer, 0, sizeof(expected_buffer));
    success &= check_memory(buffer, sizeof(buffer), expected_buffer, compare_char, function_name);
	if (success)
	{
        printf("SUCCESS: %s\n", function_name);
    }
}

void ft_bzero_test() {
    const char *function_name = "ft_bzero";
    char buffer[10];
    char expected_buffer[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int success = 1;

    // Test case 1: Set buffer to 'A' and then zero it using ft_bzero
    memset(buffer, 'A', sizeof(buffer));
    ft_bzero(buffer, sizeof(buffer));
    success &= check_memory(buffer, sizeof(buffer), expected_buffer, compare_char, function_name);
   
    // Test case 2: Set buffer to 'A' and zero only part of it
    memset(buffer, 'A', sizeof(buffer));
    ft_bzero(buffer, 5);
    memset(expected_buffer, 0, 5);
    success &= check_memory(buffer, 5, expected_buffer, compare_char, function_name);

    // Test case 3: Zero an empty buffer
    ft_bzero(expected_buffer, 0);
    success &= check_memory(expected_buffer, 0, expected_buffer, compare_char, function_name);
	if (success)
	{
        printf("SUCCESS: %s\n", function_name);
    }
}

void ft_atoi_test() {
    const char *function_name = "ft_atoi";
    int success = 1;

    // Test case 1: Basic positive integer
    success &= check_result(ft_atoi("123"), 123, function_name);

    // Test case 2: Basic negative integer
    success &= check_result(ft_atoi("-456"), -456, function_name);

    // Test case 3: String with leading spaces
    success &= check_result(ft_atoi("   789"), 789, function_name);

    // Test case 4: String with trailing spaces
    success &= check_result(ft_atoi("456   "), 456, function_name);

    // Test case 5: String with both leading and trailing spaces
    success &= check_result(ft_atoi("  -123  "), -123, function_name);

    // Test case 6: Integer with positive sign
    success &= check_result(ft_atoi("+789"), 789, function_name);

    // Test case 7: Integer with multiple signs
    success &= check_result(ft_atoi("--456"), 456, function_name);

    // Test case 8: Integer with overflow
    success &= check_result(ft_atoi("2147483648"), 2147483647, function_name);  // Overflow should return INT_MAX

    // Test case 9: Integer with underflow
    success &= check_result(ft_atoi("-2147483649"), -2147483648, function_name);  // Underflow should return INT_MIN

    // Test case 10: Empty string
    success &= check_result(ft_atoi(""), 0, function_name);

    // Test case 11: String with non-numeric characters
    success &= check_result(ft_atoi("abc"), 0, function_name);

    // Test case 12: String with non-numeric characters and then a valid number
    success &= check_result(ft_atoi("xyz123"), 0, function_name);

    if (success) {
        printf("SUCCESS: %s\n", function_name);
    }
}

int main(void) {
    ft_isalpha_test();
    ft_isdigit_test();
	ft_isalnum_test();
    ft_isascii_test();
    ft_isprint_test();
    ft_strlen_test();
	ft_memset_test();
	ft_bzero_test();
	// ft_memcpy_test();
	// ft_memmove_test();
	// ft_strlcpy_test();
	// ft_strlcat_test();

	ft_toupper_test();
	ft_tolower_test();
	// ft_strchr_test();
	// ft_strrchr_test();
	// ft_strncmp_test();
	// ft_memchr_test();
	// ft_memcmp_test();
	// ft_strnstr_test();
	// ft_atoi_test();

	// ft_substr_test();
	// ft_strjoin_test();
	// ft_strtrim_test();
	// ft_split_test();
	// ft_iota_test();
	// ft_strmapi_test();
	// ft_striteri_test();
	// ft_putchar_fd_test();
	// ft_putstr_fd_test();
	// ft_putendl_fd_test();
	// ft_putnbr_fd_test();
    return 0;
}
