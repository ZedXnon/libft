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

int check_string(const char *actual, const char *expected, const char *function_name, const int test_no, const char *info) {
    size_t actual_len = strlen(actual);
    size_t expected_len = strlen(expected);

    if (actual_len == expected_len && strcmp(actual, expected) == 0) {
        return 1;
    } else {
        printf("FAIL: %s - Test %d - %s\n", function_name, test_no, info);
        printf("Expected: \"%s\", Actual: \"%s\"\n", expected, actual);
        return 0;
    }
}


int check_memory(const void *memory, int size, const void *expected_memory,
                 int (*compare)(const void *, const void *), const char *function_name, const int test_no) {
    int success = 1;
    for (int i = 0; i < size; i++) {
        if (!compare(&((unsigned char*)memory)[i], &((unsigned char*)expected_memory)[i])) {
            success = 0;
            printf("FAIL: %s - Test %d - Incorrect value at index %d\n", function_name, test_no, i);
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
    char *test = ft_memset(buffer, 'A', sizeof(buffer));
    char *expected = memset(expected_buffer, 'A', sizeof(expected_buffer));
    success &= check_memory(buffer, sizeof(buffer), expected_buffer, compare_char, function_name, 1);

	// Test case 2: Check return value
	success &= check_memory(test, sizeof(test), expected, compare_char, function_name, 2);

    // Test case 3: Set buffer to 0
    ft_memset(buffer, 0, sizeof(buffer));
    memset(expected_buffer, 0, sizeof(expected_buffer));
    success &= check_memory(buffer, sizeof(buffer), expected_buffer, compare_char, function_name, 3);

	// Test case 4: Set buffer to 'B' (66 in ASCII)
	ft_memset(buffer, 'B', sizeof(buffer));
	memset(expected_buffer, 'B', sizeof(expected_buffer));
	success &= check_memory(buffer, sizeof(buffer), expected_buffer, compare_char, function_name, 4);

	// Test case 5: Set the first 5 elements to 'C' (67 in ASCII)
	ft_memset(buffer, 'C', 5);
	memset(expected_buffer, 'C', 5);
	success &= check_memory(buffer, sizeof(buffer), expected_buffer, compare_char, function_name, 5);


	if (success)
	{
        printf("SUCCESS: %s\n", function_name);
    }
}

void ft_bzero_test() {
    const char *function_name = "ft_bzero";
    char buffer[10];
    char expected_buffer[10];
	int success = 1;
    // Test case 1: Set buffer to 'A' and then zero it using ft_bzero
    memset(buffer, 'A', sizeof(buffer));
	memset(expected_buffer, 0, sizeof(expected_buffer));
    ft_bzero(buffer, sizeof(buffer));
    success &= check_memory(buffer, sizeof(buffer), expected_buffer, compare_char, function_name, 1);

    // Test case 2: Set buffer to '3' and zero only part of it
    memset(buffer, '3', sizeof(buffer));
	memset(expected_buffer, '3', sizeof(expected_buffer));
    ft_bzero(buffer, 5);
    memset(expected_buffer, 0, 5);
    success &= check_memory(buffer, 10, expected_buffer, compare_char, function_name, 2);

    // Test case 3: Zero an empty buffer
    ft_bzero(expected_buffer, 0);
    success &= check_memory(expected_buffer, 0, expected_buffer, compare_char, function_name, 3);

	// Test case 4: Zero an empty buffer with non-zero size
	char empty_buffer[10];
	memset(expected_buffer, 0, 10);
	ft_bzero(empty_buffer, sizeof(empty_buffer));
	success &= check_memory(empty_buffer, sizeof(empty_buffer), expected_buffer, compare_char, function_name, 4);

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

void ft_memcpy_test() {
    const char *function_name = "ft_memcpy";
    int success = 1;

    // Copying 0 bytes
	char buffer[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	char real_buffer[10];
	char expected_buffer[10];
	memset(real_buffer, 0, 10);
	memset(expected_buffer, 0, 10);
	char *actual = ft_memcpy(real_buffer, buffer, 0);
	char *expected = memcpy(expected_buffer, buffer, 0);
	success &= check_memory(real_buffer, sizeof(real_buffer), expected_buffer, compare_char, function_name, 1);
	
	// Testing reutrn value
	success &= check_memory(actual, sizeof(actual), expected, compare_char, function_name, 2);

	ft_memcpy(real_buffer, buffer, 7);
	memcpy(expected_buffer, buffer, 7);
	success &= check_memory(real_buffer, sizeof(real_buffer), expected_buffer, compare_char, function_name, 3);

    // Large Memory Blocks
    char buffer_large[1000];
	char test_buffer[1000];
    char expected_buffer_large[1000];
    memset(buffer_large, 'A', sizeof(buffer_large));
	expected = memcpy(expected_buffer_large, buffer_large, sizeof(expected_buffer_large));
    actual = ft_memcpy(test_buffer, buffer_large, sizeof(buffer_large));
    success &= check_memory(buffer_large, sizeof(buffer_large), expected_buffer_large, compare_char, function_name, 4);

	// Testing return value
	success &= check_memory(test_buffer, sizeof(test_buffer), expected_buffer_large, compare_char, function_name, 5);

    if (success) {
        printf("SUCCESS: %s\n", function_name);
    }
}

void ft_memmove_test() {
	const char *function_name = "ft_memmove";
    int success = 1;

    // Copying 0 bytes
	char buffer[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	char real_buffer[10];
	char expected_buffer[10];
	memset(real_buffer, 0, 10);
	memset(expected_buffer, 0, 10);
	char *actual = ft_memcpy(real_buffer, buffer, 0);
	char *expected = memcpy(expected_buffer, buffer, 0);
	success &= check_memory(real_buffer, sizeof(real_buffer), expected_buffer, compare_char, function_name, 1);
	
	// Testing reutrn value
	success &= check_memory(actual, sizeof(actual), expected, compare_char, function_name, 2);

	ft_memcpy(real_buffer, buffer, 7);
	memcpy(expected_buffer, buffer, 7);
	success &= check_memory(real_buffer, sizeof(real_buffer), expected_buffer, compare_char, function_name, 3);

    // Large Memory Blocks
    char buffer_large[1000];
	char test_buffer[1000];
    char expected_buffer_large[1000];
    memset(buffer_large, 'A', sizeof(buffer_large));
	expected = memcpy(expected_buffer_large, buffer_large, sizeof(expected_buffer_large));
    actual = ft_memcpy(test_buffer, buffer_large, sizeof(buffer_large));
    success &= check_memory(buffer_large, sizeof(buffer_large), expected_buffer_large, compare_char, function_name, 4);

	// Testing return value
	success &= check_memory(test_buffer, sizeof(test_buffer), expected_buffer_large, compare_char, function_name, 5);

	char overlap_buffer_1[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    char overlap_real_buffer_1[10];
    memset(overlap_real_buffer_1, 0, 10);
    char *overlap_actual_1 = ft_memcpy(overlap_real_buffer_1, overlap_buffer_1 + 3, 7);
    char *overlap_expected_1 = memcpy(overlap_real_buffer_1, overlap_buffer_1 + 3, 7);
    success &= check_memory(overlap_actual_1, sizeof(overlap_real_buffer_1), overlap_expected_1, compare_char, function_name, 6);
	
    
	// Overlapping Scenario 2: Destination before Source
    char overlap_buffer_2[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    char overlap_real_buffer_2[10];
    char overlap_expected_buffer_2[10];
    memset(overlap_real_buffer_2, 0, 10);
    memset(overlap_expected_buffer_2, 0, 10);
    ft_memcpy(overlap_real_buffer_2 + 3, overlap_buffer_2, 7);
    memcpy(overlap_expected_buffer_2 + 3, overlap_buffer_2, 7);
    success &= check_memory(overlap_real_buffer_2, sizeof(overlap_real_buffer_2), overlap_expected_buffer_2, compare_char, function_name, 7);

	

    if (success) {
        printf("SUCCESS: %s\n", function_name);
    }
}

void ft_strlcpy_test() {
    const char *function_name = "ft_strlcpy";
    int success = 1;
    
    // Test Case 1: Copying a string within the buffer size
    char src1[] = "hello";
    char dest1[10];
    char dest1_real[] = "hello";
    
    ft_strlcpy(dest1, src1, sizeof(dest1));
    success &= check_string(dest1, dest1_real, function_name, 1, "Copying within buffer size");

    // Test Case 2: Copying a string with a smaller buffer size
    char src2[] = "hello";
    char dest2[3];
    char dest2_real[] = "he";
    
    ft_strlcpy(dest2, src2, sizeof(dest2));

    success &= check_string(dest2, dest2_real, function_name, 2, "Copying to a smaller buffer");

    // Test Case 3: Copying an empty string
    char src3[] = "";
    char dest3[5];
    char dest3_real[] = "";
    
    ft_strlcpy(dest3, src3, sizeof(dest3));

    success &= check_string(dest3, dest3_real, function_name, 3, "Copying an empty string");

    // Test Case 4: Copying to an empty buffer
    char src4[] = "hello";
    char dest4[1];
    char dest4_real[] = "";
    
    ft_strlcpy(dest4, src4, sizeof(dest4));

    success &= check_string(dest4, dest4_real, function_name, 4, "Copying to an empty buffer");

    // Test Case 5: Copying an empty source string to a larger buffer
    char src5[] = "";
    char dest5[10];
    char dest5_real[] = "";
    
    ft_strlcpy(dest5, src5, sizeof(dest5));

    success &= check_string(dest5, dest5_real, function_name, 5, "Copying an empty source string to a larger buffer");

    // Test Case 6: Copying a non-empty source string to a buffer with size 0
    char src6[] = "hello";
    char dest6[1] = "\0";
    char dest6_real[] = "";

    ft_strlcpy(dest6, src6, 0);

    success &= check_string(dest6, dest6_real, function_name, 6, "Copying to a buffer with size 0");
    // Test Case 7: Copying a source string that is exactly the size of the destination buffer
    char src7[] = "hello";
    char dest7[5];
    char dest7_real[] = "hell";
    
    ft_strlcpy(dest7, src7, sizeof(dest7));

    success &= check_string(dest7, dest7_real, function_name, 7, "Copying a string with the size of the destination buffer");

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
	ft_memcpy_test();
	ft_memmove_test();
	ft_strlcpy_test();
	
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
