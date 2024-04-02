/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwoidt <dwoidt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:07:50 by dwoidt            #+#    #+#             */
/*   Updated: 2024/04/02 16:07:50 by dwoidt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
#include <fcntl.h>
#include <unistd.h>
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
	success &= check_result(ft_atoi(" 789"), 789, function_name, 3);

	// Test case 4: String with trailing spaces
	success &= check_result(ft_atoi("456 "), 456, function_name, 4);

	// Test case 5: String with both leading and trailing spaces
	success &= check_result(ft_atoi(" -123 "), -123, function_name, 5);

	// Test case 6: Integer with positive sign
	success &= check_result(ft_atoi("+789"), 789, function_name, 6);

	// Test case 7: Integer with multiple signs
	success &= check_result(ft_atoi("--456"), 0, function_name, 7);

	// Test case 8: Empty string
	success &= check_result(ft_atoi(""), 0, function_name, 8);

	// Test case 9: String with non-numeric characters
	success &= check_result(ft_atoi("abc"), 0, function_name, 9);

	// Test case 10: String with non-numeric characters and then a valid number
	success &= check_result(ft_atoi("xyz123"), 0, function_name, 10);

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
	char dest6[1] = "";
	char dest6_real[] = "";

	ft_strlcpy(dest6, src6, 0);

	success &= check_string(dest6, dest6_real, function_name, 6, "Copying to a buffer with size 0");
	// Test Case 7: Copying a source string that is exactly the size of the destination buffer
	char src7[] = "hello";
	char dest7[5];
	char dest7_real[] = "hell";
	
	ft_strlcpy(dest7, src7, sizeof(dest7));

	success &= check_string(dest7, dest7_real, function_name, 7, "Copying a string with the size of the destination buffer");

	char src10[] = "hello";
	char dest10[1000000]; // Large buffer size
	char dest10_real[] = "hello"; // Expected content

	ft_strlcpy(dest10, src10, sizeof(dest10));
	success &= check_string(dest10, dest10_real, function_name, 8, "Boundary test with very large buffer size");

	// Test Case 9: Edge case where source and destination buffer sizes match exactly
	char src11[] = "hello";
	char dest11[5]; // Exact buffer size
	char dest11_real[] = "hell"; // Expected content

	ft_strlcpy(dest11, src11, sizeof(dest11));
	success &= check_string(dest11, dest11_real, function_name, 9, "Edge case: source and destination buffer sizes match exactly");

	if (success) {
		printf("SUCCESS: %s\n", function_name);
	}
}

void ft_strlcat_test() {
	const char *function_name = "ft_strlcat";
	int success = 1;

	// Test Case 1: Concatenating strings within the buffer size
	char dest1[15] = "Hello";
	char src1[] = " World";
	char expected1[] = "Hello World";
	size_t result1 = ft_strlcat(dest1, src1, sizeof(dest1));
	success &= check_string(dest1, expected1, function_name, 1, "Concatenating within buffer size");
	success &= check_result(result1, strlen(expected1), function_name, 1);

	// Test Case 2: Concatenating to a smaller buffer
	char dest2[7] = "Hello";
	char src2[] = " World";
	char expected2[] = "Hello ";
	size_t result2 = ft_strlcat(dest2, src2, sizeof(dest2));
	success &= check_string(dest2, expected2, function_name, 2, "Concatenating to a smaller buffer");
	success &= check_result(result2, strlen("Hello World"), function_name, 2);

	// Test Case 3: Concatenating an empty source string
	char dest3[10] = "Hello";
	char src3[] = "";
	char expected3[] = "Hello";
	size_t result3 = ft_strlcat(dest3, src3, sizeof(dest3));
	success &= check_string(dest3, expected3, function_name, 3, "Concatenating an empty source string");
	success &= check_result(result3, strlen(expected3), function_name, 3);

	// Test Case 4: Concatenating to an empty destination string
	char dest4[10] = "";
	char src4[] = "World";
	char expected4[] = "World";
	size_t result4 = ft_strlcat(dest4, src4, sizeof(dest4));
	success &= check_string(dest4, expected4, function_name, 4, "Concatenating to an empty destination string");
	success &= check_result(result4, strlen(expected4), function_name, 4);

	// Test Case 5: Concatenating to a buffer with size 0
	char dest5[10] = "Hello";
	char src5[] = "World";
	char expected5[] = "Hello";
	size_t result5 = ft_strlcat(dest5, src5, 0);
	success &= check_string(dest5, expected5, function_name, 5, "Concatenating to a buffer with size 0");
	success &= check_result(result5, strlen(src5), function_name, 5);

	// Test Case 6: Concatenating a source string larger than the remaining size of the destination buffer
	char dest6[10] = "Hello";
	char src6[] = " World!";
	char expected6[] = "Hello Wor";
	size_t result6 = ft_strlcat(dest6, src6, sizeof(dest6));
	success &= check_string(dest6, expected6, function_name, 6, "Concatenating a source string larger than the remaining size");
	success &= check_result(result6, strlen("Hello World!"), function_name, 6);

	// Test Case 7: Concatenating to a full destination buffer
	char dest7[10] = "HelloWorl";
	char src7[] = "d";
	char expected7[] = "HelloWorl";
	size_t result7 = ft_strlcat(dest7, src7, sizeof(dest7));
	success &= check_string(dest7, expected7, function_name, 7, "Concatenating to a full destination buffer");
	success &= check_result(result7, strlen("HelloWorld"), function_name, 7);

	// Test Case 8: Concatenating an empty source string to an empty destination buffer
	char dest8[10] = "";
	char src8[] = "";
	char expected8[] = "";
	size_t result8 = ft_strlcat(dest8, src8, sizeof(dest8));
	success &= check_string(dest8, expected8, function_name, 8, "Concatenating an empty source string to an empty destination buffer");
	success &= check_result(result8, strlen(expected8), function_name, 8);

	if (success) {
		printf("SUCCESS: %s\n", function_name);
	}
}

void ft_calloc_test() {
	int success = 1;
	const char *function_name = "ft_calloc";

	// Test Case 1: Integer array allocation
	int *test1 = (int *)ft_calloc(15, sizeof(int));
	int expected1[15] = {0};
	success &= check_int_array(test1, expected1, 15, function_name, 1);
	free(test1);

	// Test Case 2: Character array allocation
	char *test2 = (char *)ft_calloc(9, sizeof(char));
	char expected2[9] = {0};
	success &= check_memory(test2, 9, expected2, compare_char, function_name, 2);
	free(test2);

	// Test Case 3: Zero elements allocation
	int *test3 = (int *)ft_calloc(0, sizeof(int));
	success &= check_pointer(test3, NULL, 1, function_name, 3);
	free(test3);

	// Test Case 4: Large allocation
	int *test4 = (int *)ft_calloc(100000, sizeof(int));
	if (test4 == NULL) {
		// Allocation failed, handle the error
		success &= check_pointer(test4, NULL, 1, function_name, 4);
	} else {
		int expected4[100000] = {0};
		success &= check_int_array(test4, expected4, 100000, function_name, 4);
		free(test4);
}

	// Test Case 5: Zero element size allocation
	int *test5 = (int *)ft_calloc(10, 0);
	success &= check_pointer(test5, NULL, 1, function_name, 5);
	free(test5);

	if (success) {
		printf("Success: %s\n", function_name);
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

	char string7[] = "Hello, World! 123 \n \t \0";
    char *clone7 = ft_strdup(string7);
    success &= check_string(clone7, string7, function_name, 7, "Duplicating a string with special characters");
    free(clone7);

	char string9[] = "Hello";
    char *clone9 = ft_strdup(string9);
    clone9[0] = 'M';
    success &= check_string(clone9, "Mello", function_name, 9, "Modifying the duplicated string");
    success &= check_string(string9, "Hello", function_name, 10, "Original string remains unchanged");
    free(clone9);

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

void ft_memchr_test() {
	int success = 1;
	const char *function_name = "ft_memchr";

	// Test Case 1: Search for a character in a string
	char *string1 = "Hello, World!";
	char *expected1 = "o, World!";
	char *result1 = ft_memchr(string1, 'o', strlen(string1));
	success &= check_string(result1, expected1, function_name, 1, "Search for 'o' in \"Hello, World!\"");

	// Test Case 2: Search for a character not present in the string
	char *string2 = "Hello, World!";
	char *result2 = ft_memchr(string2, 'z', strlen(string2));
	success &= check_pointer(result2, NULL, 1, function_name, 2);

	// Test Case 3: Search for a character in an empty string
	char *string3 = "";
	char *result3 = ft_memchr(string3, 'a', strlen(string3));
	success &= check_pointer(result3, NULL, 1, function_name, 3);

	// Test Case 4: Search for the null terminator in a string
	char *string4 = "Hello, World!";
	char *expected4 = "";
	char *result4 = ft_memchr(string4, '\0', strlen(string4) + 1);
	success &= check_string(result4, expected4, function_name, 4, "Search for null terminator in \"Hello, World!\"");

	// Test Case 5: Search with a length of 0
	char *string5 = "Hello, World!";
	char *result5 = ft_memchr(string5, 'o', 0);
	success &= check_pointer(result5, NULL, 1, function_name, 5);

	// Test Case 6: Search with a length greater than the string length
	char *string6 = "Hello, World!";
	char *expected6 = "o, World!";
	char *result6 = ft_memchr(string6, 'o', strlen(string6) + 10);
	success &= check_string(result6, expected6, function_name, 6, "Search with length greater than string length");

	// Test Case 7: Search for a character in a memory block
	char buffer7[] = {1, 2, 3, 4, 5};
	void *expected7 = &buffer7[2];
	void *result7 = ft_memchr(buffer7, 3, sizeof(buffer7));
	success &= check_pointer(result7, expected7, 1, function_name, 7);

	// Test Case 8: Search for a character not present in a memory block
	char buffer8[] = {1, 2, 3, 4, 5};
	void *result8 = ft_memchr(buffer8, 6, sizeof(buffer8));
	success &= check_pointer(result8, NULL, 1, function_name, 8);

	// Test Case 9: Search for the first character in a string
	char *string9 = "Hello, World!";
	char *expected9 = "Hello, World!";
	char *result9 = ft_memchr(string9, 'H', strlen(string9));
	success &= check_string(result9, expected9, function_name, 9, "Search for the first character in \"Hello, World!\"");

	// Test Case 10: Search for the last character in a string
	char *string10 = "Hello, World!";
	char *expected10 = "!";
	char *result10 = ft_memchr(string10, '!', strlen(string10));
	success &= check_string(result10, expected10, function_name, 10, "Search for the last character in \"Hello, World!\"");

	if (success) {
		printf("Success: %s\n", function_name);
	}
}

void ft_memcmp_test() {
	const char *function_name = "ft_memcmp";
	int success = 1;

	const char *s1_empty = "";
	const char *s2_empty = "";
	int result_empty = ft_memcmp(s1_empty, s2_empty, 0);
	success &= check_result(result_empty, 0, function_name, 1);

	const char *s1_equal = "abcd";
	const char *s2_equal = "abcd";
	int result_equal = ft_memcmp(s1_equal, s2_equal, strlen(s1_equal));
	success &= check_result(result_equal, 0, function_name, 2);

	const char *s1_unequal = "abcd";
	const char *s2_unequal = "abce";
	int result_unequal = ft_memcmp(s1_unequal, s2_unequal, strlen(s1_unequal));
	success &= check_result(result_unequal, -1, function_name, 3);

	const char *s1_diff_one = "abcde";
	const char *s2_diff_one = "abcdg";
	int result_diff_one = ft_memcmp(s1_diff_one, s2_diff_one, strlen(s1_diff_one));
	success &= check_result(result_diff_one, -1, function_name, 4);

	const char *s1_diff_length = "abcd";
	const char *s2_diff_length = "abcdef";
	int result_diff_length = ft_memcmp(s1_diff_length, s2_diff_length, strlen(s1_diff_length));
	success &= check_result(result_diff_length, 0, function_name, 5);

	if (success) {
		printf("SUCCESS: %s\n", function_name);
	}
}

void ft_strnstr_test() {
	const char *function_name = "ft_strnstr";
	int success = 1;

	const char *haystack_empty = "";
	const char *needle_empty = "";
	char *result_empty = ft_strnstr(haystack_empty, needle_empty, 0);
	success &= check_pointer(result_empty, haystack_empty, 1, function_name, 1);

	const char *haystack_equal = "abcd";
	const char *needle_equal = "abcd";
	char *result_equal = ft_strnstr(haystack_equal, needle_equal, strlen(haystack_equal));
	success &= check_pointer(result_equal, haystack_equal, 1, function_name, 2);

	const char *haystack_unequal = "abcd";
	const char *needle_unequal = "abce";
	char *result_unequal = ft_strnstr(haystack_unequal, needle_unequal, strlen(haystack_unequal));
	success &= check_pointer(result_unequal, NULL, 1, function_name, 3);

	const char *haystack_diff_one = "abcde";
	const char *needle_diff_one = "abcdg";
	char *result_diff_one = ft_strnstr(haystack_diff_one, needle_diff_one, strlen(haystack_diff_one));
	success &= check_pointer(result_diff_one, NULL, 1, function_name, 4);

	const char *haystack_diff_length = "abcd";
	const char *needle_diff_length = "abcdef";
	char *result_diff_length = ft_strnstr(haystack_diff_length, needle_diff_length, strlen(haystack_diff_length));
	success &= check_pointer(result_diff_length, NULL, 1, function_name, 5);

	if (success) {
		printf("SUCCESS: %s\n", function_name);
	}
}

void ft_substr_test() {
	const char *function_name = "ft_substr";
	int success = 1;

	// Test 1: Extract substring from the middle
	const char *input1 = "This is a test string.";
	const char *expected_output1 = "test ";
	char *result1 = ft_substr(input1, 10, 5);
	success &= check_string(result1, expected_output1, function_name, 1, "Extracting substring from the middle");
	free(result1);

	// Test 2: Extract substring from the beginning
	const char *input2 = "Hello, world!";
	const char *expected_output2 = "Hello";
	char *result2 = ft_substr(input2, 0, 5);
	success &= check_string(result2, expected_output2, function_name, 2, "Extracting substring from the beginning");
	free(result2);

	// Test 3: Extract substring from the end
	const char *input3 = "Testing the end";
	const char *expected_output3 = "end";
	char *result3 = ft_substr(input3, 12, 3);
	success &= check_string(result3, expected_output3, function_name, 3, "Extracting substring from the end");
	free(result3);

	// Test 4: Extracting entire string
	const char *input4 = "Complete";
	const char *expected_output4 = "Complete";
	char *result4 = ft_substr(input4, 0, 8); // Length longer than string length
	success &= check_string(result4, expected_output4, function_name, 4, "Extracting entire string");
	free(result4);

	// Test 5: Extracting substring with length exceeding string length
	const char *input5 = "Overflow";
	const char *expected_output5 = "Overflow";
	char *result5 = ft_substr(input5, 0, 100); // Length longer than string length
	success &= check_string(result5, expected_output5, function_name, 5, "Extracting substring with length exceeding string length");
	free(result5);

	// Test 6: Extracting empty substring
	const char *input6 = "Empty";
	const char *expected_output6 = "";
	char *result6 = ft_substr(input6, 5, 0); // Extract empty substring
	success &= check_string(result6, expected_output6, function_name, 6, "Extracting empty substring");
	free(result6);

	if (success) {
		printf("SUCCESS: %s\n", function_name);
	}
}

// Test function for ft_strjoin
void ft_strjoin_test() {
	const char *function_name = "ft_strjoin";
	int success = 1;

	// Test case 1: Test empty strings
	const char *s1_empty = "";
	const char *s2_empty = "";
	char *result_empty = ft_strjoin(s1_empty, s2_empty);
	success &= check_string(result_empty, "", function_name, 1, "Empty strings");

	// Test case 2: Test when one string is empty
	const char *s1 = "Hello, ";
	const char *s2 = "world!";
	char *result_s1_empty = ft_strjoin(s1, s2_empty);
	char *result_s2_empty = ft_strjoin(s1_empty, s2);
	success &= check_string(result_s1_empty, s1, function_name, 2, "First string empty");
	success &= check_string(result_s2_empty, s2, function_name, 3, "Second string empty");

	// Test case 3: Test when both strings are non-empty
	char *result_both_nonempty = ft_strjoin(s1, s2);
	char *expected_result_both_nonempty = "Hello, world!";
	success &= check_string(result_both_nonempty, expected_result_both_nonempty, function_name, 4, "Both strings non-empty");

	// Free allocated memory
	free(result_empty);
	free(result_s1_empty);
	free(result_s2_empty);
	free(result_both_nonempty);

	if (success) {
		printf("SUCCESS: %s\n", function_name);
	}
}

void ft_strtrim_test() {
	const char *function_name = "ft_strtrim";
	int success = 1;

	// Test case 1: Test with leading and trailing whitespaces
	const char *s1_with_spaces = "   hello world   ";
	const char *set_spaces = " ";
	char *result_spaces = ft_strtrim(s1_with_spaces, set_spaces);
	success &= check_string(result_spaces, "hello world", function_name, 1, "Leading and trailing whitespaces");
	free(result_spaces);

	// Test case 2: Test with leading and trailing specified characters
	const char *s1_with_chars = "---hello-world---";
	const char *set_chars = "-";
	char *result_chars = ft_strtrim(s1_with_chars, set_chars);
	success &= check_string(result_chars, "hello-world", function_name, 2, "Leading and trailing specified characters");
	free(result_chars);

	// Test case 3: Test with no leading or trailing whitespaces
	const char *s1_no_spaces = "hello world";
	const char *set_no_spaces = " ";
	char *result_no_spaces = ft_strtrim(s1_no_spaces, set_no_spaces);
	success &= check_string(result_no_spaces, "hello world", function_name, 3, "No leading or trailing whitespaces");
	free(result_no_spaces);

	// Test case 4: Test with empty input string and empty set of characters
	const char *s1_empty = "";
	const char *set_empty = "";
	char *result_empty = ft_strtrim(s1_empty, set_empty);
	success &= check_string(result_empty, "", function_name, 4, "Empty input string and empty set");
	free(result_empty);

	// Test case 5: Test with NULL input string and NULL set of characters
	char *result_null_input_null_set = ft_strtrim(NULL, NULL);
	success &= check_pointer(result_null_input_null_set, NULL, 1, function_name, 5);

	if (success) {
		printf("SUCCESS: %s\n", function_name);
	} else {
		printf("FAIL: %s\n", function_name);
	}
}


char shift_ascii(unsigned int i, char c)
{
	(void)i;
    if (c == 'z')
        return 'a';
    else if (c == 'Z')
        return 'A';
    else
        return c + 1;
}
void ft_strmapi_test() {
    const char *function_name = "ft_strmapi";
    int success = 1;

    // Test Case 1: Shift ASCII values of lowercase characters
    char *result1 = ft_strmapi("hello", shift_ascii);
    success &= check_string(result1, "ifmmp", function_name, 1, "Shift ASCII values of lowercase characters");
    free(result1);
    // Test Case 2: Shift ASCII values of uppercase characters
    char *result2 = ft_strmapi("HELLO", shift_ascii);
    success &= check_string(result2, "IFMMP", function_name, 2, "Shift ASCII values of uppercase characters");
    free(result2);

    // Test Case 3: Shift ASCII values of mixed case characters
    char *result3 = ft_strmapi("HeLlO", shift_ascii);
    success &= check_string(result3, "IfMmP", function_name, 3, "Shift ASCII values of mixed case characters");
    free(result3);

    // Test Case 4: Shift ASCII values with non-alphabetic characters
    char *result4 = ft_strmapi("hello123", shift_ascii);
    success &= check_string(result4, "ifmmp234", function_name, 4, "Shift ASCII values with non-alphabetic characters");
    free(result4);

    // Test Case 5: Empty string
    char *result5 = ft_strmapi("", shift_ascii);
    success &= check_string(result5, "", function_name, 5, "Empty string");
    free(result5);

	// Test Case 6: NULL string
    char *result6 = ft_strmapi("hello", NULL);
    success &= check_pointer(result6, NULL, 1, function_name, 6);

    if (success) {
        printf("SUCCESS: %s\n", function_name);
    }
}

void ft_putchar_fd_test() {
	const char *function_name = "ft_putchar_fd";
	int success = 1;

	// Open the file for writing
	int fd_custom = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644); // create a new file descriptor

	// Write to the file using ft_putchar_fd
	ft_putchar_fd('Z', fd_custom); // write to custom file
	ft_putchar_fd('\r', fd_custom); // write carriage return to custom file

	// Close the file descriptor
	close(fd_custom);

	// Open the file for reading
	FILE *file = fopen("output.txt", "r");
	if (file == NULL) {
		perror("Error opening file");
		success = 0;
	} else {
		// Read the content of the file
		char buffer[256];
		fgets(buffer, sizeof(buffer), file);

		// Check if the content matches the expected output
		const char *expected_output = "Z\r";
		if (strcmp(buffer, expected_output) != 0) {
			printf("FAIL: %s - File content does not match expected output\n", function_name);
			printf("Expected: \"%s\", Actual: \"%s\"\n", expected_output, buffer);
			success = 0;
		}

		// Close the file
		fclose(file);
	}

	if (success) {
		printf("SUCCESS: %s\n", function_name);
	}
}

void ft_putstr_fd_test() {
	const char *function_name = "ft_putstr_fd";
	int success = 1;

	// Open the file for writing
	int fd_custom = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644); // create a new file descriptor

	// Write to the file using ft_putstr_fd
	char *test_string = "Hello, world!";
	ft_putstr_fd(test_string, fd_custom); // write to custom file

	// Close the file descriptor
	close(fd_custom);

	// Open the file for reading
	FILE *file = fopen("output.txt", "r");
	if (file == NULL) {
		perror("Error opening file");
		success = 0;
	} else {
		// Read the content of the file
		char buffer[256];
		fgets(buffer, sizeof(buffer), file);

		// Check if the content matches the expected output
		const char *expected_output = "Hello, world!";
		if (strcmp(buffer, expected_output) != 0) {
			printf("FAIL: %s - File content does not match expected output\n", function_name);
			printf("Expected: \"%s\", Actual: \"%s\"\n", expected_output, buffer);
			success = 0;
		}

		// Close the file
		fclose(file);
	}

	if (success) {
		printf("SUCCESS: %s\n", function_name);
	}
}

void ft_putendl_fd_test() {
	const char *function_name = "ft_putendl_fd";
	int success = 1;

	// Open the file for writing
	int fd_custom = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644); // create a new file descriptor

	// Write to the file using ft_putendl_fd
	char *test_string = "Hello, world!";
	ft_putendl_fd(test_string, fd_custom); // write to custom file

	// Close the file descriptor
	close(fd_custom);

	// Open the file for reading
	FILE *file = fopen("output.txt", "r");
	if (file == NULL) {
		perror("Error opening file");
		success = 0;
	} else {
		// Read the content of the file
		char buffer[256];
		fgets(buffer, sizeof(buffer), file);

		// Check if the content matches the expected output
		const char *expected_output = "Hello, world!\n";
		if (strcmp(buffer, expected_output) != 0) {
			printf("FAIL: %s - File content does not match expected output\n", function_name);
			printf("Expected: \"%s\", Actual: \"%s\"\n", expected_output, buffer);
			success = 0;
		}

		// Close the file
		fclose(file);
	}

	if (success) {
		printf("SUCCESS: %s\n", function_name);
	}
}

void ft_putnbr_fd_test() {
	const char *function_name = "ft_putnbr_fd";
	int success = 1;

	// Redirect standard output to a file
	int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644); // Create a new file
	int original_stdout = dup(STDOUT_FILENO); // Save original stdout
	dup2(fd, STDOUT_FILENO); // Redirect stdout to the file

	// Run tests
	ft_putnbr_fd(12345, STDOUT_FILENO); // write positive integer to standard output
	ft_putnbr_fd(-54321, STDOUT_FILENO); // write negative integer to standard output
	ft_putnbr_fd(0, STDOUT_FILENO); // write zero to standard output
	ft_putnbr_fd(2147483647, STDOUT_FILENO); // write large positive integer to standard output
	ft_putnbr_fd(-2147483648, STDOUT_FILENO); // write large negative integer to standard output

	// Restore standard output
	dup2(original_stdout, STDOUT_FILENO); // Restore original stdout
	close(original_stdout); // Close the duplicated file descriptor
	close(fd); // Close the file descriptor

	// Check the content of the file
	int fd_check = open("output.txt", O_RDONLY); // Open the file for reading
	char buf[1024]; // Buffer for reading file content
	ssize_t bytes_read = read(fd_check, buf, sizeof(buf) - 1); // Read file content into buffer
	close(fd_check); // Close the file descriptor

	// Null-terminate the buffer
	buf[bytes_read] = '\0';

	// Expected output
	const char *expected_output = "12345-5432102147483647-2147483648";

	// Check if the file content matches the expected output
	if (strcmp(buf, expected_output) != 0) {
		success = 0;
	}

	// Print test result
	if (success) {
		printf("SUCCESS: %s\n", function_name);
	} else {
		printf("FAIL: %s\n", function_name);
	}
}


void ft_split_test() {
    const char *function_name = "ft_split";
    int success = 1;

    // Test Case 1: Empty string
    char **result1 = ft_split("", ' ');
    success &= check_pointer(result1[0], NULL, 1, function_name, 1);
    free(result1);

    // Test Case 2: String with only delimiters
    char **result2 = ft_split("   ", ' ');
    success &= check_pointer(result2[0], NULL, 1, function_name, 2);
    free(result2);

    // Test Case 3: String with one word
    char **result3 = ft_split("hello", ' ');
    success &= check_string(result3[0], "hello", function_name, 3, "Checking first word");
    success &= check_pointer(result3[1], NULL, 1, function_name, 3);
    free(result3[0]);
    free(result3);

    // Test Case 4: String with multiple words
    char **result4 = ft_split("hello world", ' ');
    success &= check_string(result4[0], "hello", function_name, 4, "Checking first word");
    success &= check_string(result4[1], "world", function_name, 4, "Checking second word");
    success &= check_pointer(result4[2], NULL, 1, function_name, 4);
    free(result4[0]);
    free(result4[1]);
    free(result4);

    // Test Case 5: String with leading and trailing delimiters
    char **result5 = ft_split("  hello  world  ", ' ');
    success &= check_string(result5[0], "hello", function_name, 5, "Checking first word");
    success &= check_string(result5[1], "world", function_name, 5, "Checking second word");
    success &= check_pointer(result5[2], NULL, 1, function_name, 5);
    free(result5[0]);
    free(result5[1]);
    free(result5);

    // Test Case 6: String with consecutive delimiters
    char **result6 = ft_split("hello   world", ' ');
    success &= check_string(result6[0], "hello", function_name, 6, "Checking first word");
    success &= check_string(result6[1], "world", function_name, 6, "Checking second word");
    success &= check_pointer(result6[2], NULL, 1, function_name, 6);
    free(result6[0]);
    free(result6[1]);
    free(result6);

    // Test Case 7: String with different delimiter
    char **result7 = ft_split("hello,world,foo,bar", ',');
    success &= check_string(result7[0], "hello", function_name, 7, "Checking first word");
    success &= check_string(result7[1], "world", function_name, 7, "Checking second word");
    success &= check_string(result7[2], "foo", function_name, 7, "Checking third word");
    success &= check_string(result7[3], "bar", function_name, 7, "Checking fourth word");
    success &= check_pointer(result7[4], NULL, 1, function_name, 7);
    free(result7[0]);
    free(result7[1]);
    free(result7[2]);
    free(result7[3]);
    free(result7);

    // Test Case 8: String with only one delimiter
    char **result8 = ft_split("hello", ',');
    success &= check_string(result8[0], "hello", function_name, 8, "Checking first word");
    success &= check_pointer(result8[1], NULL, 1, function_name, 8);
    free(result8[0]);
    free(result8);

    if (success) {
        printf("SUCCESS: %s\n", function_name);
    }
}

void ft_itoa_test() {
    const char *function_name = "ft_itoa";
    int success = 1;

    // Test Case 1: Zero
    char *result1 = ft_itoa(0);
    success &= check_string(result1, "0", function_name, 1, "Zero");
    free(result1);

    // Test Case 2: Positive number
    char *result2 = ft_itoa(42);
    success &= check_string(result2, "42", function_name, 2, "Positive number");
    free(result2);

    // Test Case 3: Negative number
    char *result3 = ft_itoa(-42);
    success &= check_string(result3, "-42", function_name, 3, "Negative number");
    free(result3);

    // Test Case 4: Maximum integer value
    char *result4 = ft_itoa(INT_MAX);
    char expected4[20];
    sprintf(expected4, "%d", INT_MAX);
    success &= check_string(result4, expected4, function_name, 4, "Maximum integer value");
    free(result4);

    // Test Case 5: Minimum integer value
    char *result5 = ft_itoa(INT_MIN);
    char expected5[20];
    sprintf(expected5, "%d", INT_MIN);
    success &= check_string(result5, expected5, function_name, 5, "Minimum integer value");
    free(result5);

    // Test Case 6: Single digit positive number
    char *result6 = ft_itoa(7);
    success &= check_string(result6, "7", function_name, 6, "Single digit positive number");
    free(result6);

    // Test Case 7: Single digit negative number
    char *result7 = ft_itoa(-7);
    success &= check_string(result7, "-7", function_name, 7, "Single digit negative number");
    free(result7);

    // Test Case 8: Large positive number
    char *result8 = ft_itoa(1234567890);
    success &= check_string(result8, "1234567890", function_name, 8, "Large positive number");
    free(result8);

    // Test Case 9: Large negative number
    char *result9 = ft_itoa(-1234567890);
    success &= check_string(result9, "-1234567890", function_name, 9, "Large negative number");
    free(result9);

    // Test Case 10: Number with leading zeros
	char *result10 = ft_itoa(0x002A);
	success &= check_string(result10, "42", function_name, 10, "Number with leading zeros");
	free(result10);

    if (success) {
        printf("SUCCESS: %s\n", function_name);
    }
}


// Define shift_ascii_ptr outside the ft_striteri_test function
void shift_ascii_ptr(unsigned int i, char *c) {
    (void)i; // Mark the 'i' parameter as unused

    if (*c == 'z')
        *c = 'a';
    else if (*c == 'Z')
        *c = 'A';
    else
        (*c)++;
}

void ft_striteri_test() {
    const char *function_name = "ft_striteri";
    int success = 1;

    // Test Case 1: Shift ASCII values of lowercase characters
    char str1[] = "hello";
    ft_striteri(str1, shift_ascii_ptr);
    success &= check_string(str1, "ifmmp", function_name, 1, "Shift ASCII values of lowercase characters");

    // Test Case 2: Shift ASCII values of uppercase characters
    char str2[] = "HELLO";
    ft_striteri(str2, shift_ascii_ptr);
    success &= check_string(str2, "IFMMP", function_name, 2, "Shift ASCII values of uppercase characters");

    // Test Case 3: Shift ASCII values of mixed case characters
    char str3[] = "HeLlO";
    ft_striteri(str3, shift_ascii_ptr);
    success &= check_string(str3, "IfMmP", function_name, 3, "Shift ASCII values of mixed case characters");

    // Test Case 4: Shift ASCII values with non-alphabetic characters
    char str4[] = "hello123";
    ft_striteri(str4, shift_ascii_ptr);
    success &= check_string(str4, "ifmmp234", function_name, 4, "Shift ASCII values with non-alphabetic characters");

    // Test Case 5: Empty string
    char str5[] = "";
    ft_striteri(str5, shift_ascii_ptr);
    success &= check_string(str5, "", function_name, 5, "Empty string");

    // Test Case 6: NULL string
    ft_striteri(NULL, shift_ascii_ptr);

    // Test Case 7: NULL function pointer
    ft_striteri("hello", NULL);

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
	ft_strlcat_test();
	ft_toupper_test();
	ft_tolower_test();
	ft_strchr_test();
	ft_strrchr_test();
	ft_strncmp_test(); 
	ft_memchr_test(); 
	ft_memcmp_test(); 
	ft_strnstr_test(); 
	ft_atoi_test();
	ft_calloc_test();
	ft_strdup_test(); 


	ft_substr_test();
	ft_strjoin_test();
	ft_strtrim_test();
	ft_split_test();
	ft_itoa_test();
	ft_strmapi_test();
	ft_striteri_test();
	ft_putchar_fd_test();
	ft_putstr_fd_test();
	ft_putendl_fd_test();
	ft_putnbr_fd_test();
	return 0;
}
