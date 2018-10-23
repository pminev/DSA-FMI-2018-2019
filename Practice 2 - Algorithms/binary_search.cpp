#include <iostream>

/// Binary search algorithm for searching a value in a sorted array.
/// @param[in] arr The input array, it must be sorted.
/// @param[in] arrCount The number of elements in the input array.
/// @param[in] value The searched value.
/// @return An index of the value in the arr array or -1 if it is not found.
int binarySearch(const int *arr, int arrCount, int value)
{
	// index of the first element in which could be the searched value.
	int leftBoundary = 0;
	// index of the last element in which could be the searched value.
	int rightBoundary = arrCount - 1;

	while (leftBoundary <= rightBoundary) {
		// index of the element between the left and right boundary.
		const int middleIndex = (rightBoundary + leftBoundary) / 2;
		
		if (arr[middleIndex] == value) {
			return middleIndex;
		} else if (arr[middleIndex] < value) {
			// if the middle element is less then the value in the middle
			// then all the element before the middle element are less then the value,
			// because the array is sorted,
			// so the first element in which the value could be is at index "middleIndex + 1".
			leftBoundary = middleIndex + 1;
		} else { // arr[middleIndex] > searchedElement
			// analogic to the other case.
			rightBoundary = middleIndex - 1;
		}
	}

	return -1;
}

int main()
{
	const int arr[] = { 1, 3, 6, 22, 55 };
	const int arrCount = sizeof(arr) / sizeof(arr[0]);

	std::cout << "Input array: ";
	for (int i = 0; i < arrCount; ++i) {
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';

	std::cout << "Value 3 is " << ((binarySearch(arr, arrCount, 3) != -1) ? "found" : "not found") << " in the array.\n";
	std::cout << "Value 5 is " << ((binarySearch(arr, arrCount, 5) != -1) ? "found" : "not found") << " in the array.\n";
	std::cout << "Value 100 is " << ((binarySearch(arr, arrCount, 100) != -1) ? "found" : "not found") << " in the array.\n";
	std::cout << "Value 22 is " << ((binarySearch(arr, arrCount, 22) != -1) ? "found" : "not found") << " in the array.\n";

	return 0;
}