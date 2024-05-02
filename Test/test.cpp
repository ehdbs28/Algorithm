#include <iostream>

int main()
{
    int length, target;
    std::cin >> length >> target;

    int sum = 0, front = 0, shortest = length;
    int* numbers = new int[length];
    std::cin >> numbers[0];
    sum = numbers[0];

    for (int i = 1; i < length; ++i)
    {
        std::cin >> numbers[i];
        sum += numbers[i];
        if (sum >= target)
        {
            while (front < i)
            {
                int frontNumber = numbers[front];
                if (sum - frontNumber < target)
                    break;

                front++;
                sum -= frontNumber;
            }

            int currentLength = i - front + 1;
            if (currentLength < shortest)
                shortest = currentLength;
        }
    }

    if (sum < target)
        std::cout << 0;
    else
        std::cout << shortest;

    return 0;
}