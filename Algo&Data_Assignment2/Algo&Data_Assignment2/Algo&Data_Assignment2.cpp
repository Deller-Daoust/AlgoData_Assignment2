// Jayden Deller-Daoust
// 100847599

#include <iostream>
#include <vector>
#include <math.h> // This isn't needed but is useful if you want to calculate the middle using floor(vector.size() / 2) to get the middle of the array rather than the equation below.
#include <windows.h> // This along with Beep() down below will have to be removed when compiling and executing online, since it relies on the computer you're using.

using namespace std;

int elementNum;

void mergeVectors(vector<int>& inputVec, int leftNum, int middleNum, int rightNum);
void mergeSort(vector<int>& inputVector, int leftNum, int rightNum);

int main()
{
    cout << "Please enter the number of elements in the vector: \n";
    cin >> elementNum;

    vector<int> inputVector(elementNum);

    cout << "\nPlease enter: " << elementNum << " integers: \n";

    for (int i = 0; i < elementNum; i++)
    {
        cin >> inputVector[i];
    }
    
    /* Debug to make sure integers are properly assigned.
    
    for (int num : inputVector)
    {
        cout << num << endl;
    }
    
    */

    mergeSort(inputVector, 0, inputVector.size() - 1);

    cout << "\nSorted vector: \n";
    for (int i = 0; i < elementNum; i++)
    {
        cout << inputVector[i] << " ";
    }
    cout << endl;

    return 0;
}

void mergeSort(vector<int>& inputVector, int leftNum, int rightNum)
{
    if (inputVector.size() >= 2)
    {
        int middleNum = leftNum + (rightNum - leftNum) / 2;

        mergeSort(inputVector, leftNum, middleNum);
        mergeSort(inputVector, middleNum + 1, rightNum);

        mergeVectors(inputVector, leftNum, middleNum, rightNum);
    }
    else
    {
        return;
    }
}

void mergeVectors(vector<int>& inputVector, int leftNum, int middleNum, int rightNum)
{
    int num1 = middleNum - leftNum + 1;
    int num2 = rightNum - middleNum;

    vector<int> leftVec(num1), rightVec(num2);

    for (int i = 0; i < num1; i++)
    {
        leftVec[i] = inputVector[leftNum + i];
    }

    for (int j = 0; j < num2; j++)
    {
        rightVec[j] = inputVector[middleNum + 1 + j];
    }

    int i = 0, j = 0, k = leftNum;

    while (i < num1 && j < num2)
    {
        if (leftVec[i] <= rightVec[j])
        {
            inputVector[k] = leftVec[i];
            i++;
        }
        else
        {
            inputVector[k] = rightVec[j];
            j++;
        }

        k++;

        Beep(512, 200); // This along with windows.h above will have to be removed when compiling and executing online, since it relies on the computer you're using.

        cout << endl;

        for (int i = 0; i < inputVector.size(); i++)  // Outputs the original vector to display the changes that are being made to it with every iteration.
        {
            cout << inputVector[i] << " ";
        }

        cout << endl;
    }

    while (i < num1) {
        inputVector[k] = leftVec[i];
        i++, k++;
    }

    while (j < num2) {
        inputVector[k] = rightVec[j];
        j++, k++;
    }
}
