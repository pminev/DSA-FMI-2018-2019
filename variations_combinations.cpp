#include <cstdio>
#include <iostream>
#include <cstring>

/// Print the elemnts of an array.
/// @param[in] arr The input array.
/// @param[in] count Number of elements that must be printed from the array,
///                  must not be greater then the number of element in the array.
void printArray(const int* arr, int count)
{
	for (int i = 0; i < count; ++i) {
		printf("%d ", arr[i]); // equivalent to "std::cout << arr[i] << ' ';"
	}
	printf("\n"); // equivalent to "std::cout << '\n';"
	return;
}

/// Auxiliary function for printing k-permutations of n.
/// @param[in] arr Input array holding a set of elements.
/// @param[in] arrCount Number of elements in the arr array.
/// @param[in] k The length of the variations, must be less then the number of elements in the set.
/// @param[in, out] result Array holding the current result variation for printing at the k-th step,
///                        must be allocated and with lenght not less then k.
/// @param[in] current Index of the next element that must be placed in the result array.
/// @param[in, out] arrTaken Array indicating if an element from the arr set is currently taken in the result variation,
///                          must be allocated, with length not less then arrCount and all elements must be set to false. 
void printVariationsHelper(const int *arr, int arrCount, const int k, int *result, int current, bool *arrTaken)
{
	// if the result if filled with k elements,
	// a k-permutation is constucted and it must be printed.
	if (current == k) {
		printArray(result, k);
		return;
	}

	for (int i = 0; i < arrCount; ++i) {
		// check if the element in the i-th position in the arr array is already taken in the result variation.
		if (arrTaken[i] == false) {
			result[current] = arr[i];

			// mark the i-th element as taken.
			arrTaken[i] = true;
			printVariationsHelper(arr, arrCount, k, result, current + 1, arrTaken);
			// mark the i-th element as not taken, for the next iteration of the algorithm.
			arrTaken[i] = false;
		}
	}
}

/// Print k-permutations of n of a set of elements.
/// @param[in] arr Input array holding a set of elements.
/// @param[in] arrCount Number of elements in the arr array.
/// @param[in] k The length of the variations, must be less then the number of elements in the set.
void printVariation(const int *arr, int arrCount, int k)
{
	bool *arrTaken = new bool[arrCount];
	memset(arrTaken, 0, sizeof(arrTaken[0])*arrCount);
	int *result = new int[k];

	printVariationsHelper(arr, arrCount, k, result, 0, arrTaken);
	
	delete[] arrTaken;
	delete[] result;
}

/// Auxiliary function for printing k-combinations of n.
/// @param[in] arr Input array holding a set of elements.
/// @param[in] arrCount Number of elements in the arr array.
/// @param[in] k The length of the combinations, must be less then the number of elements in the set.
/// @param[in, out] result Array holding the current result combination for printing at the k-th step,
///                        must be allocated and with lenght not less then k.
/// @param[in] current Index of the next element that must be placed in the result array.
/// @param[in, out] firstToTake The next element that can be taken from the arr array for constructing the combination.
void printCombinationsHelper(const int *arr, int arrCount, int k, int *result, int current, int firstToTake)
{
	// if the result if filled with k elements,
	// a k-combination is constucted and it must be printed.
	if (current == k) {
		printArray(result, k);
		return;
	}

	// must make place for the next elements that we should take,
	// so that we can take k elements from the arr set.
	const int lastToTake = arrCount - (k - current);
	for (int i = firstToTake; i <= lastToTake; ++i) {
		result[current] = arr[i];
		printCombinationsHelper(arr, arrCount, k, result, current + 1, i + 1);
	}
}

/// Print k-combinations of n of a set of elements.
/// @param[in] arr Input array holding a set of elements.
/// @param[in] arrCount Number of elements in the arr array.
/// @param[in] k The length of the variations, must be less then the number of elements in the set.
void printCombinations(const int *arr, int arrCount, int k)
{
	int *result = new int[k];

	printCombinationsHelper(arr, arrCount, k, result, 0, 0);

	delete[] result;
}

int main()
{
	const int arr[] = { 1, 2, 3, 4, 5 };
	const int arrCount = sizeof(arr) / sizeof(arr[0]);

	printf("2-variations of 5 elements of { 1, 2, 3, 4, 5 } set\n");
	printVariation(arr, arrCount, 2);

	printf("\n3-combinations of 5 elements of { 1, 2, 3, 4, 5 } set\n");
	printCombinations(arr, arrCount, 3);

	return 0;
}