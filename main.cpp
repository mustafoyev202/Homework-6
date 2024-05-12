#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int num;

string findMaxOccurrence(const string &s1, const string &s2, char c, int &maxCount) {
    int count1 = count(s1.begin(), s1.end(), c);
    int count2 = count(s2.begin(), s2.end(), c);

    maxCount = max(count1, count2);
    if (maxCount == 0) {
        return "Not found";
    }
    if (count1 == count2) {
        return "Same times";
    }
    return count1 > count2 ? s1 : s2;
}

void digit_count(string &word, int &count) {
    count = 0;
    for (char &key: word) {
        if (isdigit(key)) {
            count++;
        } else if (islower(key)) {
            key = toupper(key);
        } else if (isupper(key)) {
            key = tolower(key);
        }
    }
}

template<typename T>
T maxPairSum(T a, T b, T c) {
    return max({a + b, b + c, a + c});
}

template<typename T>
void findMinMax(T arr[], int size, T &min, T &max) {
    min = arr[0];
    max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
}

template<typename T>
T &swapAndReturnLarger(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
    return (a > b) ? a : b;
}

template<typename T>
void swapArrays(T *a, T *b, int size) {
    for (int i = 0; i < size; i++) {
        T temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}


int main() {
    //Problem 1
    int num;
    cout << "Enter a value for the global variable: ";
    cin >> ::num;
    cout << "Enter a value for the local variable: ";
    cin >> num;
    if (num == 0) {
        cout << "Error: Division by zero is not allowed." << endl;
        return 1;
    }
    int remainder = ::num % num;
    cout << "Output: " << remainder << endl;

//Problem 2

    string s1, s2;
    char c;

    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;
    cout << "Enter character to search: ";
    cin >> c;

    int maxCount = 0;
    string result = findMaxOccurrence(s1, s2, c, maxCount);

    if (result == "Not found") {
        cout << "Output: " << result << endl;
    } else if (result == "Same times") {
        cout << "Output: The character '" << c << "' appears " << result << " (" << maxCount << " times)." << endl;
    } else {
        cout << "Output: The string \"" << result << "\" contains the character '" << c << "' most times (" << maxCount
             << " times)." << endl;
    }

//Problem 3

    string input;
    int digitCount = 0;
    do {
        cout << "Enter a string that ends with 'x': ";
        getline(cin, input);
    } while (input.empty() || input.back() != 'x');
    digit_count(input, digitCount);
    cout << input << " contains " << digitCount << " digits" << endl;

//Problem 4
    int choice;
    cout << "Enter 1 for max pair sum or 2 for min and max of an array: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int a, b, c;
            cout << "Enter three numbers: ";
            cin >> a >> b >> c;
            cout << "Output: " << maxPairSum(a, b, c) << endl;
            break;
        }
        case 2: {
            int size;
            cout << "Enter the size of the array: ";
            cin >> size;
            int *arr = new int[size];
            cout << "Enter elements of the array: ";
            for (int i = 0; i < size; ++i) {
                cin >> arr[i];
            }
            int min, max;
            findMinMax(arr, size, min, max);
            cout << "Output: Min: " << min << " Max: " << max << endl;
            delete[] arr;
            break;
        }
        default:
            cout << "Invalid input" << endl;
            break;
    }

//Problem 5
    int choice1;
    cout << "Enter 1 to swap two numbers or 2 to swap two arrays: ";
    cin >> choice1;

    if (choice1 == 1) {
        int x, y;
        cout << "Enter two numbers: ";
        cin >> x >> y;
        cout << "The larger value after the swap is: " << swapAndReturnLarger(x, y) << endl;
    } else if (choice1 == 2) {
        int size;
        cout << "Enter the size of the arrays: ";
        cin >> size;
        int *array1 = new int[size];
        int *array2 = new int[size];

        cout << "Enter elements of the first array: ";
        for (int i = 0; i < size; ++i) {
            cin >> array1[i];
        }
        cout << "Enter elements of the second array: ";
        for (int i = 0; i < size; ++i) {
            cin >> array2[i];
        }

        swapArrays(array1, array2, size);

        cout << "First array after swap: ";
        for (int i = 0; i < size; ++i) {
            cout << array1[i] << " ";
        }
        cout << endl;

        cout << "Second array after swap: ";
        for (int i = 0; i < size; ++i) {
            cout << array2[i] << " ";
        }
        cout << endl;

        delete[] array1;
        delete[] array2;
    } else {
        cout << "Invalid operation selected." << endl;
    }

    return 0;
}
