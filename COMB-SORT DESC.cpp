#include <iostream>
using namespace std;

// Function to perform Comb Sort in descending order
void combSortDescending(int arr[], int n) {
    double shrinkFactor = 1.3;   //Shrink factor for comb sort
    int gap = n;                  // Initial gap
    bool swapped = true;          // To check if any swap happened
    int comparisons = 0;          // Count comparisons
    int swaps = 0;                // Count  swaps

    while (gap > 1 || swapped) {   // Repeat until gap=1 and no swaps
        // Calculate new gap
        gap = int(gap / shrinkFactor);
        if (gap < 1) gap = 1;

        swapped = false;

        // Compare elements separated by the gap
        for (int i = 0; i + gap < n; i++) {
            comparisons++;  // Count comparison

            if (arr[i] < arr[i + gap]) { // Descending order check
                // Swap elements
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swaps++;       // Count swap
                swapped = true;
            }
        }
    }

    // Print final sorted list
    cout << "Sorted list (descending): ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    //Print records
    cout << "Total comparisons: " << comparisons << endl;
    cout << "Total swaps: " << swaps << endl;
}

int main() {
    int n;

    //Ask User to enter Number of Elements
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    // Input the list
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Call Comb Sort descending
    combSortDescending(arr, n);

    return 0;
}