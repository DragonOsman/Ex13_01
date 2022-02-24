// Osman Zakir
// 2 / 17 / 2022
// Beginning C++20: From Novice to Professional by Ivor Horton and Peter Van Weert
// Chapter 13 Example Code 1, 2 and 3
// Implementing a less-than operator
// For Example Code 2, also supporting double < Box and Box < double
// For Example Code 3:
// Overloading <=> and == to fully support all comparison operators

import <string_view>;
import <iostream>;
import <vector>;
import <format>;
import box;

void show(const Box& box);
void show(const Box& box1, std::string_view relationship, const Box& box2);

int main()
{
	std::vector<Box> boxes{ Box{2.0, 1.5, 3.0}, Box{1.0, 3.0, 5.0},
						    Box{1.0, 2.0, 1.0}, Box{2.0, 3.0, 3.0} };
	const Box the_box{ 3.0, 1.0, 4.0 };
	for (const auto& box : boxes)
	{
		if (the_box > box)
		{
			show(the_box, " is greater than ", box);
		}
	}
	std::cout << std::endl;

	for (const auto& box : boxes)
	{
		if (the_box != box)
		{
			show(the_box, " is not equal to ", box);
		}
	}
	std::cout << std::endl;

	for (const auto& box : boxes)
	{
		if (6.0 <= box)
		{
			std::cout << "6 is less than or equal to ";
			show(box);
			std::cout << std::endl;
		}
	}
}

void show(const Box& box)
{
	std::cout << std::format("Box {}x{}x{}",
		           box.get_length(), box.get_width(), box.get_height())
		      << std::endl;
}

void show(const Box& box1, std::string_view relationship, const Box& box2)
{
	show(box1);
	std::cout << relationship;
	show(box2);
	std::cout << std::endl;
}