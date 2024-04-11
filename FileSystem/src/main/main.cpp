#include "base.h"

int main(void)
{
	using ary::dynamic_array;

	int length;
	printf("Press a size array: ");
	std::cin >> length;
	dynamic_array<float> arr_value(length);

	if (length > 0)
	{
		std::cout << "Press a " << length << " Values: ";
		int index = 0; float value;
		while (index < length) {
			std::cin >> value;
			if (value <= 0)
			{
				printf("The value is negitive or == 0, pls Press 1 or 2");
				char choice;
				std::cin >> choice;
				switch (choice)
				{
				case '1': continue;
				case '2': exit(EXIT_SUCCESS);
				}
			}
			else
				arr_value[index] = value;
			index++;
		}
	}
	else
	{
		printf("Close Please Wait...");
		Sleep(500);
		exit(EXIT_SUCCESS);
	}

	if (Chacking_the_number(arr_value))
	{
		std::ofstream in_file;
		in_file.open("Text.txt");
		if (in_file.is_open()) {
			for (size_t i = 0; i < length; i++) {
				in_file << arr_value[i];
			}
		}
		else
			printf("Error File is not open: ");
	}
	else {
		printf("Oops, sorry");
		exit(EXIT_SUCCESS);
	}

	system("Pause");
	return 0;
}