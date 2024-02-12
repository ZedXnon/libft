/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwoidt <dwoidt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:45:57 by dwoidt            #+#    #+#             */
/*   Updated: 2024/02/01 19:45:57 by dwoidt           ###   ########.fr       */
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

int check_pointer(const void *actual, const void *expected, int expected_equal,
                   const char *function_name, const int test_no) {
    if ((actual == expected) != expected_equal) {
        printf("FAIL: %s - Test %d - Pointers are%s equal\n", function_name, test_no, expected_equal ? "" : " not");
        printf("Expected pointer: %p, Actual pointer: %p\n", expected, actual);
		return (0);
    }
	else
	{
		return (1);
	}
}


int check_int_array(const int *actual, const int *expected, int size, const char *function_name, const int test_no) {
    int success = 1;

    if (expected == NULL) {
        if (actual != NULL) {
            success = 0;
            printf("FAIL: %s - Test %d - Expected is NULL, but actual is not.\n", function_name, test_no);
        }
        return (success);
    }

    for (int i = 0; i < size; i++) {
        if (actual[i] != expected[i]) {
            success = 0;
            printf("FAIL: %s - Test %d - Incorrect value at index %d\n", function_name, test_no, i);
            printf("Expected: %d, Actual: %d\n", expected[i], actual[i]);
            break;
        }
    }

    return (success);
}


int check_string(const char *actual, const char *expected, const char *function_name, const int test_no, const char *info) {
    size_t actual_len = strlen(actual);
    size_t expected_len = strlen(expected);

    if (actual_len == expected_len && strcmp(actual, expected) == 0) {
        return 1;
    } else {
        printf("FAIL: %s - Test %d - %s\n", function_name, test_no, info);
        printf("Expected: \"%s\", Actual: \"%s\"\n", expected, actual);
        return (0);
    }
}

int check_char(const char *actual, const char *expected, const char *function_name, const int test_no, const char *info) {
	int success = 1;
	if ((expected == NULL && actual != NULL) || (actual == NULL && expected != NULL))
	{
		success = 0;
	}
	if (((actual == NULL || expected == NULL) && actual != expected) || actual[0] != *expected)
	{
		success = 0;
	}
	if (!success)
	{
		printf("FAIL: %s - Test %d - %s\n", function_name, test_no, info);
    	printf("Expected: \"%s\", Actual: \"%s\"\n", expected, actual);
	}
	return (success);
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

int check_result(int actual, int expected, const char *function_name, int test_no) {
    if (actual == expected) {
        return 1;
    } else {
        printf("FAIL: %s - (Expected: %d, Actual: %d) - Test %d\n", function_name, expected, actual, test_no);
        return 0;
    }
}

int compare_char_ptr(const void *a, const void *b) {
    return (*(char **)a == *(char **)b);
}

int compare_char(const void *a, const void *b) {
    return (*(unsigned char *)a == *(unsigned char *)b);
}

int compare_int(const void *a, const void *b) {
    const int *int_a = (const int *)a;
    const int *int_b = (const int *)b;
    
    return (*int_a == *int_b) ? 1 : 0;
}


// Test function for ft_isalpha
void ft_isalpha_test() {
    const char *function_name = "ft_isalpha";
    int success = 1;

    success &= check_result(ft_isalpha('a'), 1, function_name, 1);
    success &= check_result(ft_isalpha('A'), 1, function_name, 2);
    success &= check_result(ft_isalpha('z'), 1, function_name, 3);
    success &= check_result(ft_isalpha('Z'), 1, function_name, 4);
    success &= check_result(ft_isalpha('1'), 0, function_name, 5);
    success &= check_result(ft_isalpha('\t'), 0, function_name, 6);
    success &= check_result(ft_isalpha('\n'), 0, function_name, 7);

    if (success) {
        printf("SUCCESS: %s\n", function_name);
    }
}

void ft_toupper_test() {
    const char *function_name = "ft_toupper";
    int success = 1;

    success &= check_result(ft_toupper('a'), 'A', function_name, 1);
    success &= check_result(ft_toupper('A'), 'A', function_name, 2);
    success &= check_result(ft_toupper('z'), 'Z', function_name, 3);
    success &= check_result(ft_toupper('Z'), 'Z', function_name, 4);
    success &= check_result(ft_toupper('1'), '1', function_name, 5);
    success &= check_result(ft_toupper('\t'), '\t', function_name, 6);
    success &= check_result(ft_toupper('\n'), '\n', function_name, 7);

    if (success) {
        printf("SUCCESS: %s\n", function_name);
    }
}
// Test function for ft_isdigit
void ft_isdigit_test() {
    const char *function_name = "ft_isdigit";
    int success = 1;

    success &= check_result(ft_isdigit('0'), 1, function_name, 1);
    success &= check_result(ft_isdigit('5'), 1, function_name, 2);
    success &= check_result(ft_isdigit('9'), 1, function_name, 3);
    success &= check_result(ft_isdigit('a'), 0, function_name, 4);
    success &= check_result(ft_isdigit('A'), 0, function_name, 5);
    success &= check_result(ft_isdigit('@'), 0, function_name, 6);
    success &= check_result(ft_isdigit('\t'), 0, function_name, 7);
    success &= check_result(ft_isdigit('\n'), 0, function_name, 8);

    if (success) {
        printf("SUCCESS: %s\n", function_name);
    }
}

void ft_tolower_test() {
    const char *function_name = "ft_tolower";
    int success = 1;

    success &= check_result(ft_tolower('a'), 'a', function_name, 1);
    success &= check_result(ft_tolower('A'), 'a', function_name, 2);
    success &= check_result(ft_tolower('z'), 'z', function_name, 3);
    success &= check_result(ft_tolower('Z'), 'z', function_name, 4);
    success &= check_result(ft_tolower('1'), '1', function_name, 5);
    success &= check_result(ft_tolower('\t'), '\t', function_name, 6);
    success &= check_result(ft_tolower('\n'), '\n', function_name, 7);

    if (success) {
        printf("SUCCESS: %s\n", function_name);
    }
}

void ft_isalnum_test() {
    const char *function_name = "ft_isalnum";
    int success = 1;

    success &= check_result(ft_isalnum('a'), 1, function_name, 1);
    success &= check_result(ft_isalnum('5'), 1, function_name, 2);
    success &= check_result(ft_isalnum('@'), 0, function_name, 3);
    success &= check_result(ft_isalnum('\t'), 0, function_name, 4);
    success &= check_result(ft_isalnum('\n'), 0, function_name, 5);

    if (success) {
        printf("SUCCESS: %s\n", function_name);
    }
}

// Test function for ft_isascii
void ft_isascii_test() {
    const char *function_name = "ft_isascii";
    int success = 1;

    success &= check_result(ft_isascii('a'), 1, function_name, 1);
    success &= check_result(ft_isascii(127), 1, function_name, 2);
    success &= check_result(ft_isascii(128), 0, function_name, 3);
    success &= check_result(ft_isascii('\t'), 1, function_name, 4);
    success &= check_result(ft_isascii('\n'), 1, function_name, 5);
	success &= check_result(ft_isascii(0), 1, function_name, 6);

    if (success) {
        printf("SUCCESS: %s\n", function_name);
    }
}

// Test function for ft_isprint
void ft_isprint_test() {
    const char *function_name = "ft_isprint";
    int success = 1;

    success &= check_result(ft_isprint('a'), 1, function_name, 1);
    success &= check_result(ft_isprint(32), 1, function_name, 2);
    success &= check_result(ft_isprint(31), 0, function_name, 3);
    success &= check_result(ft_isprint(127), 0, function_name, 4);
	success &= check_result(ft_isprint(126), 1, function_name, 5);
    success &= check_result(ft_isprint('\t'), 0, function_name, 6);
    success &= check_result(ft_isprint('\n'), 0, function_name, 7);

    if (success) {
        printf("SUCCESS: %s\n", function_name);
    }
}

// Test function for ft_strlen
void ft_strlen_test() {
    const char *function_name = "ft_strlen";
    int success = 1;

    success &= check_result(ft_strlen(""), 0, function_name, 1);
    success &= check_result(ft_strlen("Hello"), 5, function_name, 2);
    success &= check_result(ft_strlen("1234567890"), 10, function_name, 3);

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
    success &= check_result(ft_atoi("123"), 123, function_name, 1);

    // Test case 2: Basic negative integer
    success &= check_result(ft_atoi("-456"), -456, function_name, 2);

    // Test case 3: String with leading spaces
    success &= check_result(ft_atoi("   789"), 789, function_name, 3);

    // Test case 4: String with trailing spaces
    success &= check_result(ft_atoi("456   "), 456, function_name, 4);

    // Test case 5: String with both leading and trailing spaces
    success &= check_result(ft_atoi("  -123  "), -123, function_name, 5);

    // Test case 6: Integer with positive sign
    success &= check_result(ft_atoi("+789"), 789, function_name, 6);

    // Test case 7: Integer with multiple signs
    success &= check_result(ft_atoi("--456"), 456, function_name, 7);

    // Test case 8: Integer with overflow
    success &= check_result(ft_atoi("2147483648"), 2147483647, function_name, 8);  // Overflow should return INT_MAX

    // Test case 9: Integer with underflow
    success &= check_result(ft_atoi("-2147483649"), -2147483648, function_name, 9);  // Underflow should return INT_MIN

    // Test case 10: Empty string
    success &= check_result(ft_atoi(""), 0, function_name, 10);

    // Test case 11: String with non-numeric characters
    success &= check_result(ft_atoi("abc"), 0, function_name, 11);

    // Test case 12: String with non-numeric characters and then a valid number
    success &= check_result(ft_atoi("xyz123"), 0, function_name, 12);

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

void ft_strlcat_test()
{
    const char *function_name = "ft_strlcat";
    int success = 1;

    // Test Case 1: Concatenating strings within the buffer size
    char dest1[15] = "hello";
    char src1[] = "world";
    char dest1_real[] = "helloworld";
    
    size_t result1 = ft_strlcat(dest1, src1, sizeof(dest1));
    success &= check_string(dest1, dest1_real, function_name, 1, "Concatenating within buffer size");
    success &= check_result(result1, strlen(dest1_real), function_name, 1);

    // Test Case 2: Concatenating to a smaller buffer
    char dest2[7] = "hello";
    char src2[] = "world";
    char dest2_real[] = "hellow";
    
    size_t result2 = ft_strlcat(dest2, src2, sizeof(dest2));
    success &= check_string(dest2, dest2_real, function_name, 2, "Concatenating to a smaller buffer");
    success &= check_result(result2, strlen(dest2_real), function_name, 2);

    // Test Case 3: Concatenating an empty source string
    char dest3[10] = "hello";
    char src3[] = "";
    char dest3_real[] = "hello";
    
    size_t result3 = ft_strlcat(dest3, src3, sizeof(dest3));
    success &= check_string(dest3, dest3_real, function_name, 3, "Concatenating an empty source string");
    success &= check_result(result3, strlen(dest3_real), function_name, 3);

    // Test Case 4: Concatenating to an empty destination string
    char dest4[1] = "";
    char src4[] = "world";
    char dest4_real[] = "w";
    
    size_t result4 = ft_strlcat(dest4, src4, sizeof(dest4));
    success &= check_string(dest4, dest4_real, function_name, 4, "Concatenating to an empty destination string");
    success &= check_result(result4, strlen(dest4_real), function_name, 4);

    // Test Case 5: Concatenating an empty source string to a larger buffer
    char dest5[10] = "hello";
    char src5[] = "";
    char dest5_real[] = "hello";
    
    size_t result5 = ft_strlcat(dest5, src5, sizeof(dest5));
    success &= check_string(dest5, dest5_real, function_name, 5, "Concatenating an empty source string to a larger buffer");
    success &= check_result(result5, strlen(dest5_real), function_name, 5);

    // Test Case 6: Concatenating a non-empty source string to a buffer with size 0
    char dest6[1] = "";
    char src6[] = "world";
    char dest6_real[] = "";
    
    size_t result6 = ft_strlcat(dest6, src6, 0);
    success &= check_string(dest6, dest6_real, function_name, 6, "Concatenating to a buffer with size 0");
    success &= check_result(result6, strlen(dest6_real), function_name, 6);

    // Test Case 7: Concatenating a source string that is exactly the size of the destination buffer
    char dest7[10] = "hello";
    char src7[] = "world";
    char dest7_real[] = "helloworld";
    
    size_t result7 = ft_strlcat(dest7, src7, sizeof(dest7));
    success &= check_string(dest7, dest7_real, function_name, 7, "Concatenating a string with the size of the destination buffer");
    success &= check_result(result7, strlen(dest7_real), function_name, 7);

    // Additional Edge Cases:

    // Test Case 8: Concatenating to an empty destination string with larger buffer size
    char dest8[10] = "";
    char src8[] = "world";
    char dest8_real[] = "world";
    
    size_t result8 = ft_strlcat(dest8, src8, sizeof(dest8));
    success &= check_string(dest8, dest8_real, function_name, 8, "Concatenating to an empty destination string with larger buffer size");
    success &= check_result(result8, strlen(dest8_real), function_name, 8);

    // Test Case 9: Concatenating an empty source string to a larger buffer with larger buffer size
    char dest9[15] = "hello";
    char src9[] = "";
    char dest9_real[] = "hello";
    
    size_t result9 = ft_strlcat(dest9, src9, sizeof(dest9));
    success &= check_string(dest9, dest9_real, function_name, 9, "Concatenating an empty source string to a larger buffer with larger buffer size");
    success &= check_result(result9, strlen(dest9_real), function_name, 9);

    // Test Case 10: Concatenating to a buffer with size 0
    char dest10[10] = "hello";
    char src10[] = "world";
    char dest10_real[] = "hello";
    
    size_t result10 = ft_strlcat(dest10, src10, 0);
    success &= check_string(dest10, dest10_real, function_name, 10, "Concatenating to a buffer with size 0");
    success &= check_result(result10, strlen(dest10_real), function_name, 10);

    // Test Case 11: Concatenating a source string that is exactly one less than needed for the destination buffer
    char dest11[10] = "hello";
    char src11[] = "world";
    char dest11_real[] = "helloworld";
    
    size_t result11 = ft_strlcat(dest11, src11, sizeof(dest11) - 1);
    success &= check_string(dest11, dest11_real, function_name, 11, "Concatenating a source string that is exactly one less than needed for the destination buffer");
    success &= check_result(result11, strlen(dest11_real), function_name, 11);

    // Test Case 12: Concatenating a source string that is exactly one more than needed for the destination buffer
    char dest12[10] = "hello";
    char src12[] = "world";
    char dest12_real[] = "helloworl";
    
    size_t result12 = ft_strlcat(dest12, src12, sizeof(dest12) - 1);
    success &= check_string(dest12, dest12_real, function_name, 12, "Concatenating a source string that is exactly one more than needed for the destination buffer");
    success &= check_result(result12, strlen(dest12_real), function_name, 12);

    // Test Case 13: Concatenating to a buffer larger than needed
    char dest13[20] = "hello";
    char src13[] = "world";
    char dest13_real[] = "helloworld";
    
    size_t result13 = ft_strlcat(dest13, src13, sizeof(dest13));
    success &= check_string(dest13, dest13_real, function_name, 13, "Concatenating to a buffer larger than needed");
    success &= check_result(result13, strlen(dest13_real), function_name, 13);

    // Test Case 14: Concatenating to a buffer larger than needed with additional null characters
    char dest14[20] = "hello";
    char src14[] = "world";
    char dest14_real[] = "helloworld";
    
    size_t result14 = ft_strlcat(dest14, src14, sizeof(dest14));
    success &= check_string(dest14, dest14_real, function_name, 14, "Concatenating to a buffer larger than needed with additional null characters");
    success &= check_result(result14, strlen(dest14_real), function_name, 14);

    // Test Case 15: Concatenating large strings
    char dest15[50] = "hello";
    char src15[50] = "world";
    char dest15_real[] = "helloworld";
    
    size_t result15 = ft_strlcat(dest15, src15, sizeof(dest15));
    success &= check_string(dest15, dest15_real, function_name, 15, "Concatenating large strings");
    success &= check_result(result15, strlen(dest15_real), function_name, 15);


	if (success) {
        printf("SUCCESS: %s\n", function_name);
    }
}

void ft_calloc_test()
{
	int success = 1;
	const char *function_name = "ft_calloc";

	int *test1 = (int *)ft_calloc(15, sizeof(int));
	int expected1[15] = {0};
	success &= check_int_array(test1, expected1, 15, function_name, 1);

	char *test2 = (char *)ft_calloc(9, sizeof(char));
	char expected2[9] = {0};
	success &= check_memory(test2, 9, expected2, compare_char, function_name, 2);

	int *test3 = (int *)ft_calloc(0, sizeof(int));
	success &= check_int_array(test3, NULL, 0, function_name, 3);


	if (success)
	{
		printf("Success %s\n", function_name);
	}
}

void ft_strdup_test()
{
	int success = 1;
	const char *function_name = "ft_strdup";

	char string[] = "Hello";
	char *clone = ft_strdup(string);
	success &= check_string(clone, string, function_name, 1, "checking string");

	char string2[] = "";
	char *clone2 = ft_strdup(string2);
	success &= check_string(clone2, string2, function_name, 2, "empty string");
	
	char string3[] = "Hello";
    char *clone3 = ft_strdup(string3);
    check_pointer(clone3, string3, 0, function_name, 3); 

    success &= check_string(clone3, string3, function_name, 4, "Comparing strings");

	char large_string[10000];
	char *clone5 = ft_strdup(large_string);
	success &= check_string(clone5, large_string, function_name, 5, "Comparing large strings");

	char string6[] = "Hello";
	char *clone6 = ft_strdup(string6);
	success &= check_string(clone6, string6, function_name, 6, "Comparing strings with null-termination");

	if (success)
	{
		printf("Success %s\n", function_name);
	}
}

void ft_strchr_test()
{
	int success = 1;
	const char *function_name = "ft_strchr";
	char *string = "Stringr rdddd";
	char *c = "r";
	success &= check_char(ft_strchr(string, *c), c, function_name, 1, "Checking if letter is found in string");
	char *string2 = "Test";

	if (ft_strchr(string2, *c) == NULL)
	{
		success &= 1;
	}
	else
	{
		printf("%s - Failed NULL check in Test 2\n", function_name);
		success = 0;
	}

	char *string3 = "restrdsfds";
	char *string4 = "Trersr";

	success &= check_char(ft_strchr(string3, *c), c, function_name, 3, "Checking if letter is found in string");
	success &= check_char(ft_strchr(string4, *c), c, function_name, 4, "Checking if letter is found in string");

	if (ft_strchr(string, *c) == strchr(string, *c))
	{
		success &= 1;
	}
	else
	{
		printf("%s - Failed memory address check in Test 5\n", function_name);
		success &= 0;
	}

	if (success)
	{
		printf("Success %s\n", function_name);
	}
}

void ft_strrchr_test()
{
	int success = 1;
	const char *function_name = "ft_strrchr";
	char *string = "Stringr rdddd";
	char *c = "r";
	success &= check_char(ft_strrchr(string, *c), c, function_name, 1, "Checking if letter is found in string");
	char *string2 = "Test";

	if (ft_strrchr(string2, *c) == NULL)
	{
		success &= 1;
	}
	else
	{
		printf("%s - Failed NULL check in Test 2\n", function_name);
		success = 0;
	}

	char *string3 = "restrdsfds";
	char *string4 = "Trersr";

	success &= check_char(ft_strrchr(string3, *c), c, function_name, 3, "Checking if letter is found in string");
	success &= check_char(ft_strrchr(string4, *c), c, function_name, 4, "Checking if letter is found in string");

	if (ft_strrchr(string, *c) == strrchr(string, *c))
	{
		success &= 1;
	}
	else
	{
		printf("%s - Failed memory address check in Test 5\n", function_name);
		success &= 0;
	}

	if (success)
	{
		printf("Success %s\n", function_name);
	}
}

void ft_strncmp_test()
{
	int success = 1;
	const char *function_name = "ft_strncmp";
	char *string1 = "Test1";
	char *string2 = "Test2";
	char *string3 = "Tet2";

	success &= check_result(ft_strncmp(string1, string2, 200) == strncmp(string1, string2, 200), 1, function_name, 1);
	success &= check_result(ft_strncmp(string3, string2, 2) == strncmp(string3, string2, 2), 1, function_name, 2);
	success &= check_result(ft_strncmp(string2, string2, 3) == strncmp(string2, string2, 3), 1, function_name, 3);
	success &= check_result(ft_strncmp(string2, string2, 0) == strncmp(string2, string2, 0), 1, function_name, 4);
	success &= check_result(ft_strncmp("", "", 0) == strncmp("", "", 0), 1, function_name, 5);
	success &= check_result(ft_strncmp(string1, string2, -1) == strncmp(string1, string2, -1), 1, function_name, 6);
	success &= check_result(ft_strncmp("abc", "ABC", 3) == strncmp("abc", "ABC", 3), 1, function_name, 7);
	success &= check_result(ft_strncmp("abc\0def", "abc\0ghi", 7) == strncmp("abc\0def", "abc\0ghi", 7), 1, function_name, 8);
	success &= check_result(ft_strncmp("short", "longer", 5) == strncmp("short", "longer", 5), 1, function_name, 9);
	success &= check_result(ft_strncmp(string1, string2, 1000) == strncmp(string1, string2, 1000), 1, function_name, 10);

	if (success)
	{
		printf("Success %s\n", function_name);
	}
}

void ft_memchr_test()
{
	int success = 1;
	const char *function_name = "ft_memchr";
	char *string = "This is a test.";
	char *expected = "a test.";
	char *result = ft_memchr(string, 'a', 15);
	
	success &= check_memory(result, sizeof(result), expected, compare_char, function_name, 1);
	success &= check_pointer(ft_memchr(string, ' ', 10), memchr(string, ' ', 10), 1, function_name, 2);
	success &= check_pointer(ft_memchr(string, ' ', 0), memchr(string, ' ', 0), 1, function_name, 3);
	success &= check_pointer(ft_memchr(string, *"", 200), memchr(string, *"", 200), 1, function_name, 4);
	success &= check_pointer(ft_memchr(string, 't', 1000), memchr(string, 't', 1000), 1, function_name, 5);
	success &= check_pointer(ft_memchr(string, *"test", 1000), memchr(string, *"test", 1000), 1, function_name, 6);
	
	if (success)
	{
		printf("Success %s\n", function_name);
	}
}

int main(void) {
   /*  ft_isalpha_test();
    ft_isdigit_test();
	ft_isalnum_test();
    ft_isascii_test();
    ft_isprint_test();
    ft_strlen_test();
	ft_memset_test();
	ft_bzero_test();
	ft_memcpy_test();
	ft_memmove_test(); 
	// ft_strlcpy_test();
	// ft_strlcat_test();
	// ft_calloc_test();
	ft_strdup_test(); */
	
/* 
	ft_toupper_test();
	ft_tolower_test();
	ft_strchr_test();
	ft_strrchr_test();
	ft_strncmp_test(); */
	ft_memchr_test();
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
