/**
 * @file Lab6_username.cpp
 * @author Aayush Pande
 * @date 2026-10-12
 * @brief Compares static arrays and vectors for processing student test scores.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

/**
 * @brief Calculates the average of scores stored in a static array.
 * @param arr The array containing integer test scores.
 * @param size The number of elements in the array.
 * @return The average score as a float.
 */
float calculateAverage(const int arr[], int size)
{
    int total = 0;

    for (int i = 0; i < size; i++)
    {
        total += arr[i];
    }

    return static_cast<float>(total) / size;
}

/**
 * @brief Finds the highest score in a static array.
 * @param arr The array containing integer test scores.
 * @param size The number of elements in the array.
 * @return The highest score in the array.
 */
int findMax(const int arr[], int size)
{
    int highest = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > highest)
        {
            highest = arr[i];
        }
    }

    return highest;
}

/**
 * @brief Finds the lowest score in a static array.
 * @param arr The array containing integer test scores.
 * @param size The number of elements in the array.
 * @return The lowest score in the array.
 */
int findMin(const int arr[], int size)
{
    int lowest = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] < lowest)
        {
            lowest = arr[i];
        }
    }

    return lowest;
}

/**
 * @brief Calculates the average of scores stored in a vector.
 * @param vec The vector containing integer test scores.
 * @return The average score as a float.
 */
float calculateAverage(const vector<int>& vec)
{
    int total = 0;

    for (int score : vec)
    {
        total += score;
    }

    return static_cast<float>(total) / vec.size();
}

/**
 * @brief Finds the highest score in a vector.
 * @param vec The vector containing integer test scores.
 * @return The highest score in the vector.
 */
int findMax(const vector<int>& vec)
{
    int highest = vec[0];

    for (int score : vec)
    {
        if (score > highest)
        {
            highest = score;
        }
    }

    return highest;
}

/**
 * @brief Finds the lowest score in a vector.
 * @param vec The vector containing integer test scores.
 * @return The lowest score in the vector.
 */
int findMin(const vector<int>& vec)
{
    int lowest = vec[0];

    for (int score : vec)
    {
        if (score < lowest)
        {
            lowest = score;
        }
    }

    return lowest;
}

/**
 * @brief Calculates and displays student score statistics using a fixed-size static array.
 * @param None.
 * @return None.
 */
void arraySolution()
{
    const int SIZE = 10;
    int scores[SIZE];
    int score;

    cout << "Static Array Solution" << endl;
    cout << "---------------------" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter score " << i + 1 << " (0-100): ";
        cin >> score;

        while (score < 0 || score > 100)
        {
            cout << "Invalid score. Enter a score between 0 and 100: ";
            cin >> score;
        }

        scores[i] = score;
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage score: " << calculateAverage(scores, SIZE) << endl;
    cout << "Highest score: " << findMax(scores, SIZE) << endl;
    cout << "Lowest score: " << findMin(scores, SIZE) << endl;
}

/**
 * @brief Calculates and displays student score statistics using a dynamic vector.
 * @param None.
 * @return None.
 */
void vectorSolution()
{
    vector<int> scores;
    int score;

    cout << "\nVector Solution" << endl;
    cout << "---------------" << endl;
    cout << "Enter test scores from 0 to 100." << endl;
    cout << "Enter -1 when finished." << endl;

    while (true)
    {
        cout << "Enter score: ";
        cin >> score;

        if (score == -1)
        {
            break;
        }

        if (score < 0 || score > 100)
        {
            cout << "Invalid score. Enter a score between 0 and 100." << endl;
        }
        else
        {
            scores.push_back(score);
        }
    }

    if (scores.empty())
    {
        cout << "No scores were entered." << endl;
        return;
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage score: " << calculateAverage(scores) << endl;
    cout << "Highest score: " << findMax(scores) << endl;
    cout << "Lowest score: " << findMin(scores) << endl;

    sort(scores.begin(), scores.end());

    cout << "Sorted scores: ";

    for (int score : scores)
    {
        cout << score << " ";
    }

    cout << endl;
}

/**
 * @brief Entry point of the program.
 * @param None.
 * @return 0 to indicate successful program execution.
 */
int main()
{
    arraySolution();
    vectorSolution();

    return 0;
}